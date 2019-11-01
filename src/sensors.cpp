#include "sensors.h"

Adafruit_BME280 Sensors::bme = Adafruit_BME280();
Adafruit_ADS1015 Sensors::adsLegs[2] = {
    Adafruit_ADS1015(0x48),
    Adafruit_ADS1015(0x49)};

void Sensors::amperageTaskThread()
{
    for (;;)
    {
        char leg1[5];
        char leg2[5];
        float ampsL1 = getAmperage(0);
        float ampsL2 = getAmperage(1);
        dtostrf(ampsL1, 4, 1, leg1);
        dtostrf(ampsL2, 4, 1, leg2);
        display->updateAmps(leg1, leg2);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
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
float Sensors::getAmperage(int i)
{
    float amps = 0;
    int maxValue = 0;
    int minValue = 0;

    long stopTime = millis() + 250;
    while (millis() < stopTime)
    {
        int readValue = adsLegs[i].readADC_Differential_0_1();
        if (readValue > maxValue)
            maxValue = readValue; // update max
        if (readValue < minValue)
            minValue = readValue; // update min
    }
    amps = ((maxValue - minValue) * 0.036);

    maxValue = -4096;
    minValue = 0;
    return amps;
}