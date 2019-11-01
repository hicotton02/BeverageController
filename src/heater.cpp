#include "heater.h"
#include <HardwareSerial.h>
#include <esp32-hal-gpio.h>
#include <WString.h>

const int TEMP_PRECISION = 9;

Heater::Heater(int s, int f, int o, heater_t t)
{
    relayPin = s;
    ssrPin = f;
    onewirePin = o;
    oneWire = OneWire(onewirePin);
    tempSensor = &oneWire;
    type = t;
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
        float temp = tempSensor.getTempFByIndex(0);
        char tempText[6];
        dtostrf(temp, 3, 1, tempText);
        if (temp > 0 && temp < 212)
        {
            Input = temp;
            switch (type)
            {
            case Hlt_h:
                display->updateActualTemp(Hlt_t, tempText);
                break;
            case Boiler_h:
                display->updateActualTemp(Boiler_t, tempText);
                break;
            case Still_h:
                display->updateActualTemp(Still_t, tempText);
                break;
            default:
                break;
            }
        }
        pid.Compute();
    }
    vTaskDelete(NULL);
}
