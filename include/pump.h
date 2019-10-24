#ifndef __PUMP_H__
#define __PUMP_H__

class Pump
{
private:
    int pin;

public:
    Pump(int pin);
    void begin();
    void enable();
    void disable();
};

#endif /* __PUMP_H__ */