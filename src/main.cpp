#include "sensors.h"
#include "heater.h"
#include "display.h"

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

uint64_t chipId;
Display *Display::instance = 0;
Display *display = display->getInstance();
Heater heaters[2] = {Heater(HEATER1_CONTACTOR_PIN, HEATER1_SSR_PIN, HEATER1_TEMP_PIN), Heater(HEATER2_CONTACTOR_PIN, HEATER2_SSR_PIN, HEATER2_TEMP_PIN)};

Sensors sensors;
TaskHandle_t heater1Taskhandle;
TaskHandle_t heater2Taskhandle;

void heater1Callback(void *parameters)
{
  heaters[0].taskThread();
}

void heater2Callback(void *parameters)
{
  heaters[1].taskThread();
}

void setup()
{
  
  Serial.begin(BAUD_RATE);                                      //Programming
  Serial1.begin(BAUD_RATE, SERIAL_8N1, DISPLAY_RX, DISPLAY_TX); //Display Port
  Serial2.begin(BAUD_RATE, SERIAL_8N1, DEBUG_RX, DEBUG_TX);     //Debug Port

  chipId = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes).
  sensors.begin();
  for (Heater heater : heaters)
  {
    heater.begin();
  }

  xTaskCreate(
      heater1Callback,     /* pvTaskCode */
      "Heater1Workload",   /* pcName */
      1000,                /* usStackDepth */
      NULL,                /* pvParameters */
      20,                  /* uxPriority */
      &heater1Taskhandle); /* pxCreatedTask */
  xTaskCreate(
      heater2Callback,     /* pvTaskCode */
      "Heater2Workload",   /* pcName */
      1000,                /* usStackDepth */
      NULL,                /* pvParameters */
      21,                  /* uxPriority */
      &heater2Taskhandle); /* pxCreatedTask */
}

//DO NOT USE
void loop() {}