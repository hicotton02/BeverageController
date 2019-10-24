#include "sensors.h"

const int TEMP_PRECISION = 9;
const int TEMPA_BUS = 4;  //Onewire1
const int TEMPB_BUS = 23; //Onewire2
const int TEMPC_BUS = 5;  //onewire3

Adafruit_BME280 bme;
OneWire onewireDevices[3] = {OneWire(TEMPA_BUS), OneWire(TEMPB_BUS), OneWire(TEMPC_BUS)};
DallasTemperature tempSensors[3] = {DallasTemperature(&onewireDevices[0]), DallasTemperature(&onewireDevices[1]), DallasTemperature(&onewireDevices[2])};
Adafruit_ADS1015 adsLegs[2] = {Adafruit_ADS1015(0x48), Adafruit_ADS1015(0x49)};

Sensors::Sensors()
{
}

void Sensors::begin()
{
    Serial2.println(F("Setting up onewire devices"));
    pinMode(TEMPC_BUS, INPUT);
    pinMode(TEMPB_BUS, INPUT);
    pinMode(TEMPA_BUS, INPUT);
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
int *Sensors::getTemps()
{
    int temps[4];
    for (int i = 0; i < 3; i++)
    {
        int temp = tempSensors[i].getTempFByIndex(0);
        if (temp > 0 && temp < 212)
            temps[i] = temp;
    }
    temps[4] = (int)bme.readTemperature();
    return temps;
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