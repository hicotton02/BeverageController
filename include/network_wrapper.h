#ifndef __NETWORK_WRAPPER_H__
#define __NETWORK_WRAPPER_H__

#include "config.h"

class NetworkWrapper
{
private:
    void startOTA();
    void getNTPTime(char * timeZone);

public:
    NetworkWrapper();
    void begin(CONFIG_T config);
};

#endif