
#ifndef __BREW_CONTROLLER_H__
#define __BREW_CONTROLLER_H__


#include "sensors.h"
#include "display.h"

class BrewController
{
public:
    BrewController(int h);

private:
    int hermsEnabled;    
    Display *display = display->getInstance();
    Sensors *sensors = sensors->getInstance();
};

#endif /*__BREW_CONTROLLER_H__*/