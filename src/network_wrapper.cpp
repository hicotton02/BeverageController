#include "network_wrapper.h"
#include <HardwareSerial.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include "time.h"

NetworkWrapper::NetworkWrapper() {}

void NetworkWrapper::begin(CONFIG_T config)
{
    Serial2.println("Setting up WiFi");
    char localIp[16];
    if (config.ssid && config.pass)
    {
        WiFi.mode(WIFI_STA);
        WiFi.begin(config.ssid, config.pass);
        while (WiFi.status() != WL_CONNECTED)
        {
            vTaskDelay(pdMS_TO_TICKS(500));
            Serial2.print(".");
        }
        strncpy(localIp, WiFi.localIP().toString().c_str(), 16);
        Serial2.print("IP Address: ");
        Serial2.println(localIp);

        //Get NTP Time
        getNTPTime(config.timeZone);
        startOTA();
    }
}
void NetworkWrapper::startOTA() {
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial2.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial2.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial2.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial2.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial2.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial2.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial2.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial2.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial2.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial2.println("OTA Ready");
}

void NetworkWrapper::getNTPTime(char * timeZone) {
  int timeZoneOffsetH = 0;
  int timeZoneOffsetS = 0;
  sscanf(timeZone, "%d", &timeZoneOffsetH);
  timeZoneOffsetS = timeZoneOffsetH * 60 * 60;
  configTime(timeZoneOffsetS, 3600, "us.pool.ntp.org");
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial2.println("Failed to get time");
    return;
  }
  Serial2.println(&timeinfo, "%I:%M:%S");
  display->setDisplayRTCTime(&timeinfo);
}