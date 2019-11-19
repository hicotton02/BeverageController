#include "sensors.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_ADS1015.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "display.h"

const int TEMP_PRECISION = 9;

Adafruit_BME280 Sensors::bme = Adafruit_BME280();
Adafruit_ADS1015 Sensors::adsLegs[2] = {
    Adafruit_ADS1015(0x48),
    Adafruit_ADS1015(0x49)};

OneWire Sensors::oneWires[3] = {
    OneWire(4),
    OneWire(23),
    OneWire(5)};

DallasTemperature Sensors::tempSensors[3] = {
    DallasTemperature(&oneWires[0]),
    DallasTemperature(&oneWires[1]),
    DallasTemperature(&oneWires[2])};
Sensors::Sensors()
{
    Display *display = display->getInstance();
}
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
        Display::updateAmps(leg1, leg2);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}
void Sensors::tempSensorTaskThread()
{
    for (;;)
    {
        for (DallasTemperature sensor : tempSensors)
        {
            sensor.requestTemperatures();
        }
        vTaskDelay(pdMS_TO_TICKS(750));
    }
    vTaskDelete(NULL);
}
void Sensors::begin()
{
    Serial2.println(F("Setting up OneWire Devices"));
    pinMode(4, INPUT);
    pinMode(23, INPUT);
    pinMode(5, INPUT);
    for (DallasTemperature sensor : tempSensors)
    {
        sensor.begin();
        sensor.setResolution(TEMP_PRECISION);
        sensor.setWaitForConversion(false);
    }
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
float Sensors::getTemp(int index)
{
    if (index > 3)
    {
        return tempSensors[index].getTempFByIndex(0);
    }
    else
    {
        return bme.readTemperature();
    }
}

float Sensors::getPressure()
{
    float v = bme.readPressure();
    Serial2.printf("Pressure :");
    Serial2.println(v);
    return v;
}
float Sensors::getHumidity()
{
    float v = bme.readHumidity();
    Serial2.printf("Humidity :");
    Serial2.println(v);
    return v;
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