#include "heater.h"
#include <HardwareSerial.h>
#include <esp32-hal-gpio.h>
#include <WString.h>


const int TEMP_PRECISION = 9;

Heater::Heater(int slowPin, int fastPin, int oneWireBus)
{
    relayPin = slowPin;
    ssrPin = fastPin;
    onewirePin = oneWireBus;
    oneWire = OneWire(onewirePin);
    tempSensor = &oneWire;
    
}

void Heater::begin()
{
    Serial2.println(F("Setting up Heater"));
    pinMode(onewirePin, INPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(ssrPin, OUTPUT);
    digitalWrite(relayPin, LOW);
    digitalWrite(ssrPin, LOW);
    tempSensor.begin();
    tempSensor.setResolution(TEMP_PRECISION);
    tempSensor.setWaitForConversion(false);
}

void Heater::enable(int setTemp)
{
    if (setTemp < 212)
    {
        digitalWrite(relayPin, HIGH);

        pid.SetOutputLimits(0, pidWindowSize);
        pid.SetMode(AUTOMATIC);
    }
    else
    {
        digitalWrite(relayPin, HIGH);
        digitalWrite(ssrPin, HIGH);
    }
}

void Heater::disable()
{
    digitalWrite(relayPin, LOW);
    digitalWrite(ssrPin, LOW);
}

void Heater::taskThread()
{
    for (;;)
    {
        //Serial2.println("Requesting Temperatures");
        tempSensor.requestTemperatures();

        vTaskDelay(pdMS_TO_TICKS(750));
        int temp = (int)tempSensor.getTempFByIndex(0);
        
        if (temp > 0 && temp < 212)
        {
            Input = temp;
            Serial.println(temp);
            display->updateHltTemp(temp);
        }
        pid.Compute();
    }
    vTaskDelete(NULL);
}
