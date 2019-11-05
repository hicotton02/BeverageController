#ifndef __NETWORK_WRAPPER_H__
#define __NETWORK_WRAPPER_H__

#include "config.h"
#include "display.h"

class NetworkWrapper
{
private:
    void startOTA();
    void getNTPTime(char * timeZone);
    Display *display = display->getInstance();

public:
    NetworkWrapper();
    void begin(CONFIG_T config);
};

#endif