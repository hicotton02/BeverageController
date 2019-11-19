#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "controller_type.h"

class Display;
class Sensors;
class Heater;
enum controller_t;

class Controller
{
private:
    static Controller *instance;
    static controller_t controllerType;
    Controller();
    static int enabled;
    static bool isAuto;
    static int stillType;
    float getColumnABV();
    float getBoilerABV();
    static Heater heaters[2];
    void autoDistillLoop();
    void autoBrewLoop();
    void manualDistillLoop();
    void manualBrewLoop();

public:
    static Controller *getInstance()
    {
        if (!instance)
            instance = new Controller;
        return instance;
    }
    static void setType(controller_t t);
    void workTaskThread();
    static void enableSession();
    static void disableSession();
};

#endif /*__CONTROLLER_H__*/