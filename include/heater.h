#ifndef __HEATER_H__
#define __HEATER_H__

#include <PID_v1.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "display.h"

class Heater
{
private:
    int relayPin, ssrPin, onewirePin;
    double Output;
    double kp = 2, ki = 5, kd = 1;
    int pidWindowSize = 1000;
    PID pid = PID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);
    OneWire oneWire;
    DallasTemperature tempSensor;
    Display *display = display->getInstance();

public:
    double Input, Setpoint;
    void enable(int setTemp = 0);
    void disable();
    void begin();
    void taskThread();
    Heater(int slowPin, int fastPin, int oneWireBus);
};
#endif /* __HEATER_H__ */