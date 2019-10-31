#ifndef __HEATER_H__
#define __HEATER_H__

#include <PID_v1.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "display.h"
#include "HeaterType.h"

class Heater
{
public:
    
    void enable(int setTemp = 0);
    void disable();
    void begin();
    void taskThread();
    Heater(int slowPin, int fastPin, int oneWireBus, heater_t type);

private:
    heater_t type;
    int relayPin, ssrPin, onewirePin;
    double Input, Setpoint, Output;
    double kp = 2, ki = 5, kd = 1;
    int pidWindowSize = 1000;
    PID pid = PID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);
    OneWire oneWire;
    DallasTemperature tempSensor;
    Display *display = display->getInstance();
};
#endif /* __HEATER_H__ */