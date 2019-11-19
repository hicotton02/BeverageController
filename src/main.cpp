#include "config.h"
#include "controller.h"
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

CONFIG_T configuration;

uint64_t chipId;
Display *Display::instance = 0;
Display *display = display->getInstance();

Sensors *Sensors::instance = 0;
Sensors *sensors = sensors->getInstance();

Controller *Controller::instance = 0;
Controller *controller = controller->getInstance();

NetworkWrapper nw;
TaskHandle_t heater1TaskHandle;
TaskHandle_t heater2TaskHandle;
TaskHandle_t displayReceiveTaskHandle;
TaskHandle_t displaySendTaskHandle;
TaskHandle_t ammeterTaskHandle;
TaskHandle_t tempSensorTaskHandle;

//Callbacks
void tempSensorsCallback(void *parameters)
{
  sensors->tempSensorTaskThread();
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


  xTaskCreate(
      tempSensorsCallback,    /* pvTaskCode */
      "tempSensorTask",       /* pcName */
      1000,                   /* usStackDepth */
      NULL,                   /* pvParameters */
      99,                     /* uxPriority */
      &tempSensorTaskHandle); /* pxCreatedTask */
  xTaskCreate(
      ammeterCallback,     /* pvTaskCode */
      "ammeterTask",       /* pcName */
      2000,                /* usStackDepth */
      NULL,                /* pvParameters */
      100,                 /* uxPriority */
      &ammeterTaskHandle); /* pxCreatedTask */
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