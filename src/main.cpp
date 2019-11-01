#include "config.h"
#include "sensors.h"
#include "heater.h"
#include "display.h"
#include "network_wrapper.h"
#include "HeaterType.h"
#include <SD.h>

//pinout
const int DEBUG_TX = 16;
const int DEBUG_RX = 17;
const int DISPLAY_TX = 26;
const int DISPLAY_RX = 27;
const int BAUD_RATE = 115200;
const int HEATER1_CONTACTOR_PIN = 18;
const int HEATER1_SSR_PIN = 14;
const int HEATER1_TEMP_PIN = 4;
const int HEATER2_CONTACTOR_PIN = 25;
const int HEATER2_SSR_PIN = 13;
const int HEATER2_TEMP_PIN = 5;

CONFIG_T configuration;

uint64_t chipId;
Display *Display::instance = 0;
Display *display = display->getInstance();
Heater heaters[2] = {
    Heater(HEATER1_CONTACTOR_PIN, HEATER1_SSR_PIN, HEATER1_TEMP_PIN, Hlt_h),
    Heater(HEATER2_CONTACTOR_PIN, HEATER2_SSR_PIN, HEATER2_TEMP_PIN, Boiler_h)};

Sensors *Sensors::instance = 0;
Sensors *sensors = sensors->getInstance();
NetworkWrapper nw;
TaskHandle_t heater1TaskHandle;
TaskHandle_t heater2TaskHandle;
TaskHandle_t displayReceiveTaskHandle;
TaskHandle_t displaySendTaskHandle;
TaskHandle_t ammeterTaskHandle;


//Callbacks
void heater1Callback(void *parameters)
{
  heaters[0].taskThread();
}
void heater2Callback(void *parameters)
{
  heaters[1].taskThread();
}
void displayReceiveCallback(void *parameters)
{
  display->listenThread();
}
void displaySendCallback(void *parameters)
{
  display->sendThread();
}
void ammeterCallback(void *parameters)
{
  sensors->amperageTaskThread();
}
void setup()
{

  Serial.begin(BAUD_RATE);                                      //Programming
  Serial1.begin(BAUD_RATE, SERIAL_8N1, DISPLAY_RX, DISPLAY_TX); //Display Port
  Serial2.begin(BAUD_RATE, SERIAL_8N1, DEBUG_RX, DEBUG_TX);     //Debug Port

  chipId = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes).
  nw.begin(configuration);
  sensors->begin();
  display->begin();
  for (Heater heater : heaters)
  {
    heater.begin();
  }

  xTaskCreate(
      ammeterCallback,     /* pvTaskCode */
      "ammeterTask",       /* pcName */
      2000,                /* usStackDepth */
      NULL,                /* pvParameters */
      100,                 /* uxPriority */
      &ammeterTaskHandle); /* pxCreatedTask */
  xTaskCreate(
      heater1Callback,     /* pvTaskCode */
      "Heater1Task",       /* pcName */
      1000,                /* usStackDepth */
      NULL,                /* pvParameters */
      20,                  /* uxPriority */
      &heater1TaskHandle); /* pxCreatedTask */
  xTaskCreate(
      heater2Callback,     /* pvTaskCode */
      "Heater2Task",       /* pcName */
      1000,                /* usStackDepth */
      NULL,                /* pvParameters */
      21,                  /* uxPriority */
      &heater2TaskHandle); /* pxCreatedTask */
  xTaskCreate(
      displayReceiveCallback,     /* pvTaskCode */
      "displayReceive",           /* pcName */
      2000,                       /* usStackDepth */
      NULL,                       /* pvParameters */
      1,                          /* uxPriority */
      &displayReceiveTaskHandle); /* pxCreatedTask */
  xTaskCreate(
      displaySendCallback,     /* pvTaskCode */
      "displaySend",           /* pcName */
      2000,                    /* usStackDepth */
      NULL,                    /* pvParameters */
      2,                       /* uxPriority */
      &displaySendTaskHandle); /* pxCreatedTask */
}

//DO NOT USE
void loop() {}