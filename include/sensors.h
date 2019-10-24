#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_ADS1015.h>

class Sensors
{
private:
    Adafruit_BME280 bme;
    OneWire onewireDevices[3];
    DallasTemperature tempSensors[3];
    Adafruit_ADS1015 adsLegs[2];

public:
    int *getTemps();
    float getPressure();
    float getHumidity();
    float *getAmperage();
    void begin();
    Sensors();
};

#endif /* __SENSORS_H__ */