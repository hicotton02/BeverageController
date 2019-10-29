#include "sensors.h"

Adafruit_BME280 bme;
Adafruit_ADS1015 adsLegs[2] = {Adafruit_ADS1015(0x48), Adafruit_ADS1015(0x49)};

Sensors::Sensors()
{
}

void Sensors::begin()
{

    Serial2.println("Setting up BME280");
    Wire.begin(SDA, SCL);
    Wire.setClock(2000000);
    bme.begin();
    Serial2.println("Setting up ADS");
    for (Adafruit_ADS1015 leg : adsLegs)
    {
        leg.setGain(GAIN_TWO);
        leg.setSPS(ADS1015_DR_3300SPS);
    }
}
int Sensors::getTemp()
{
    return (int)bme.readTemperature();
}

float Sensors::getPressure()
{
    return bme.readPressure();
}
float Sensors::getHumidity()
{
    return bme.readHumidity();
}
float *Sensors::getAmperage()
{
    float amps[2] = {0.0, 0.0};
    int maxValue = 0;
    int minValue = 0;
    for (int i = 0; i < 2; i++)
    {
        long stopTime = millis() + 500;
        while (millis() < stopTime)
        {
            int readValue = adsLegs[i].readADC_Differential_0_1();
            if (readValue > maxValue)
                maxValue = readValue; // update max
            if (readValue < minValue)
                minValue = readValue; // update min
        }
        amps[i] = ((maxValue - minValue) * 0.036);

        maxValue = -4096;
        minValue = 0;
    }
    return amps;
}