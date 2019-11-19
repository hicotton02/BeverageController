#include "controller.h"
#include "abv_calculations.h"
#include "sensors.h"
#include "display.h"
#include "heater.h"

const int HEATER2_CONTACTOR_PIN = 25;
const int HEATER2_SSR_PIN = 13;
const int HEATER2_TEMP_PIN = 5;
const int HEATER1_SSR_PIN = 14;
const int HEATER1_TEMP_PIN = 4;
const int HEATER1_CONTACTOR_PIN = 18;
Controller::Controller()
{
    Display *display = display->getInstance();
    Sensors *sensors = sensors->getInstance();
}
void Controller::enableSession()
{
    enabled = true;
}
void Controller::disableSession()
{
    enabled = false;
    isAuto = false;
}
float Controller::getColumnABV()
{
    float P = Sensors::getPressure();
    float T = Sensors::getTemp(2);
    return TtoVaporABV(stillType, T, P);
}
float Controller::getBoilerABV()
{
    float P = Sensors::getPressure();
    float T = Sensors::getTemp(1);
    return TtoLiquidABV(stillType, T, P);
}
void Controller::setType(controller_t t){
    controllerType = t;
}
void Controller::workTaskThread()
{
    for (;;)
    {
        if (enabled == 1)
        {
            switch (controllerType)
            {
            case AutoBrew_t:
                autoBrewLoop();
                break;
            case ManualBrew_t:
                manualBrewLoop();
                break;
            case AutoDistill_t:
                autoDistillLoop();
                break;
            case ManualDistill_t:
                manualDistillLoop();
                break;
            }
        }
    }
    vTaskDelete(NULL);
}
void Controller::autoBrewLoop()
{
}
void Controller::manualBrewLoop()
{
}
void Controller::manualDistillLoop()
{
}
void Controller::autoDistillLoop()
{
}