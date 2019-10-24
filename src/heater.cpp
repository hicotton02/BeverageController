#include "heater.h"
#include <HardwareSerial.h>
#include <esp32-hal-gpio.h>
#include <WString.h>

Heater::Heater(int slowPin, int fastPin)
{
    relayPin = slowPin;
    ssrPin = fastPin;
   
}

void Heater::begin()
{
    Serial2.println(F("Setting up Heater"));
    pinMode(relayPin, OUTPUT);
    pinMode(ssrPin, OUTPUT);
    digitalWrite(relayPin, LOW);
    digitalWrite(ssrPin, LOW);
    
}

void Heater::enable(int setTemp = 0)
{
    if (setTemp > 0)
    {
        digitalWrite(relayPin, HIGH);
        pid = PID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);
        pid.SetOutputLimits(0, pidWindowSize);
        pid.SetMode(AUTOMATIC);
        
        //TODO: have PID run
    }
    else
    {
        digitalWrite(relayPin, HIGH);
        digitalWrite(ssrPin, HIGH);
    }
}

void Heater::disable(){
    digitalWrite(relayPin, LOW);
    digitalWrite(ssrPin, LOW);
}
void Heater::loop(double currentTemp){
    
    pid.Compute();
}