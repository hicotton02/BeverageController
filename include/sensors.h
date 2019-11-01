#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_ADS1015.h>
#include "display.h"

class Sensors
{
private:
    static Sensors *instance;
    Sensors() {}
    static Adafruit_BME280 bme;
    static Adafruit_ADS1015 adsLegs[2];
    Display *display = display->getInstance();

public:
    static int getTemp();
    static float getPressure();
    static float getHumidity();
    static float getAmperage(int i);
    void begin();
    void amperageTaskThread();
    static Sensors *getInstance()
    {
        if (!instance)
            instance = new Sensors;
        return instance;
    }
};

#endif /* __SENSORS_H__ */