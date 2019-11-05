/* 
This is the Controller Configuration for a Reflux or Pot Still
It assumes the following setup
OneWire A is the temp sensor in the boiler
OneWire B is the temp sensor in the column
OneWire C can be connected to a temp sensor that is in the coolant water

Both Heating elements are used as 1. This board has been tested on up to 2x5500w elements totalling 11Kw of power.

This Controller makes use of an on-board barometer so to accurately calculate the ABV of the product coming out of the still.

*/

#ifndef __DISTILL_CONTROLLER_H__
#define __DISTILL_CONTROLLER_H__


#include "sensors.h"
#include "display.h"

class DistillController
{
public:
    DistillController(int stillType);

private:
    int stillType;
    float getColumnABV();
    float getBoilerABV();
    Display *display = display->getInstance();
    Sensors *sensors = sensors->getInstance();
};

#endif /*__DISTILL_CONTROLLER_H__*/