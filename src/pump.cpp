#include "pump.h"
#include <HardwareSerial.h>
#include <esp32-hal-gpio.h>
#include <WString.h>

Pump::Pump(int p){
    pin = p;
}
void Pump::begin(){
    Serial2.println(F("Setting up Pump"));
    pinMode(pin, OUTPUT);
}
void Pump::enable(){
    digitalWrite(pin, HIGH);
}
void Pump::disable(){
    digitalWrite(pin, LOW);
}