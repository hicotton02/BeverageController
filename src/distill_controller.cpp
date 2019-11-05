#include "distill_controller.h"
#include "abv_calculations.h"

DistillController::DistillController(int t)
{
    stillType = t;
}
float DistillController::getColumnABV()
{
    float P = sensors->getPressure();
    float T = sensors->getTemp(2);
    return TtoVaporABV(stillType, T, P);
}
float DistillController::getBoilerABV()
{
    float P = sensors->getPressure();
    float T = sensors->getTemp(1);
    return TtoLiquidABV(stillType, T, P);
}