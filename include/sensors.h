#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_ADS1015.h>

class Sensors
{
private:
    Adafruit_BME280 bme;
    Adafruit_ADS1015 adsLegs[2];

public:
    int getTemp();
    float getPressure();
    float getHumidity();
    float *getAmperage();
    void begin();
    Sensors();
};

#endif /* __SENSORS_H__ */