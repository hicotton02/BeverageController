#ifndef __HEATER_H__
#define __HEATER_H__

#include <PID_v1.h>

class Heater{
    private:
    int relayPin, ssrPin;
    double Input, Setpoint, Output;
    double kp = 2, ki = 5, kd = 1;
    int pidWindowSize = 1000;
    PID pid;
    
    public:
    int currentTemp();
    void enable(int setTemp = 0);
    void disable();
    void begin();
    void loop();
    Heater(int slowPin, int fastPin);
};



#endif /* __HEATER_H__ */