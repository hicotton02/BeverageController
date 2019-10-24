#include <SD.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>
#include <Adafruit_ADS1015.h> //https://github.com/soligen2010/Adafruit_ADS1X15
#include <TimeLib.h>
#include "Nextion.h"
#include <PID_v1.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <AWS_IOT.h>
//#include "Esp32MQTTClient.h"
#include <WiFi.h>
#include <HardwareSerial.h>
//#include <WebServer.h>   //https://github.com/zhouhan0126/DNSServer---esp32
//#include <DNSServer.h>   //https://github.com/zhouhan0126/DNSServer---esp32
//#include <WiFiManager.h> //https://github.com/zhouhan0126/DNSServer---esp32
#include <time.h>