#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <Nextion.h>
#include "HeaterType.h"
#include "TemperatureSensorType.h"

class Display
{

private:
    static Display *instance;
    Display()
    {
    }
    static bool manualHltButtonUpPressed;
    static bool manualHltButtonDownPressed;
    static bool manualMltButtonUpPressed;
    static bool manualMltButtonDownPressed;
    static bool manualBoilButtonUpPressed;
    static bool manualBoilButtonDownPressed;
    static bool manualTimeButtonUpPressed;
    static bool manualTimeButtonDownPressed;
    static u_int pageDisplayed;
    static NexRtc rtc;

    static NexPage lockPage;

    static NexPage selectPage;
    static NexButton autoBrewButton;
    static NexButton manualBrewButton;
    static NexButton autoDistillButton;
    static NexButton manualDistillButton;
    static NexButton settingsButton;

    static NexPage autoBrewPage;
    static NexDSButton autoBrewHLTButton;
    static NexDSButton autoBrewBoilButton;
    static NexDSButton autoBrewMainPumpButton;
    static NexDSButton autoBrewHermsPumpButton;
    static NexButton autoBrewNextButton;
    static NexText autoBrewHltActual;
    static NexText autoBrewHltTarget;
    static NexText autoBrewMltActual;
    static NexText autoBrewMltTarget;
    static NexText autoBrewBoilActual;
    static NexText autoBrewBoilTarget;
    static NexText autoBrewIpAddress;
    static NexText autoBrewSsid;
    static NexText autoBrewAmpsLeg1;
    static NexText autoBrewAmpsLeg2;
    static NexNumber autoBrewHours;
    static NexNumber autoBrewMinutes;
    static NexNumber autoBrewSeconds;
    static NexButton autoBrewHomeButton;
    static NexVariable autoBrewStatusMessage;

    static NexPage manualBrewPage;
    static NexDSButton manualBrewHLTButton;
    static NexDSButton manualBrewBoilButton;
    static NexDSButton manualBrewPumpButton;
    static NexDSButton manualBrewHermsButton;
    static NexButton manualBrewResetButton;
    static NexButton manualBrewHltUpButton;
    static NexButton manualBrewHltDownButton;
    static NexButton manualBrewMltUpButton;
    static NexButton manualBrewMltDownButton;
    static NexButton manualBrewBoilUpButton;
    static NexButton manualBrewBoilDownButton;
    static NexButton manualBrewTimeUpButton;
    static NexButton manualBrewTimeDownButton;
    static NexText manualBrewHltActual;
    static NexText manualBrewHltTarget;
    static NexText manualBrewMltActual;
    static NexText manualBrewMltTarget;
    static NexText manualBrewBoilActual;
    static NexText manualBrewBoilTarget;
    static NexText manualBrewIpAddress;
    static NexText manualBrewSsid;
    static NexText manualBrewAmpsLeg1;
    static NexText manualBrewAmpsLeg2;
    static NexNumber manualBrewHours;
    static NexNumber manualBrewMinutes;
    static NexNumber manualBrewSeconds;
    static NexButton manualBrewHomeButton;
    static NexButton manualBrewStartButton;
    static NexVariable manualBrewStatusMessage;

    static NexPage autoDistillPage;
    static NexButton autoDistillHomeButton;
    static NexText autoDistillIpAddress;
    static NexText autoDistillSsid;
    static NexText autoDistillAmpsLeg1;
    static NexText autoDistillAmpsLeg2;
    static NexText autoDistillColumnActual;
    static NexText autoDistillBoilActual;
    static NexText autoDistillAbv;
    static NexVariable autoDistillStatusMessage;

    static NexPage manualDistillPage;
    static NexDSButton manualDistillBoilButton;
    static NexDSButton manualDistillPumpButton;
    static NexText manualDistillColumnActual;
    static NexText manualDistillBoilActual;
    static NexText manualDistillCoolantActual;
    static NexSlider manualDistillSlider;
    static NexNumber manualDistillPowerPercentage;
    static NexText manualDistillIpAddress;
    static NexText manualDistillSsid;
    static NexText manualDistillAmpsLeg1;
    static NexText manualDistillAmpsLeg2;
    static NexText manualDistillAbv;
    static NexButton manualDistillHomeButton;
    static NexVariable manualDistillStatusMessage;

    static NexPage settingsPage;
    static NexButton settingsSaveButton;
    static NexButton settingsCancelButton;
    static NexText settingsSsid;
    static NexText settingsPass;
    static NexCheckbox settingsHerms;
    static NexCheckbox settingsStillPump;
    static NexText settingsTimeZone;

    static NexTouch *nex_listen_list[42];

    static void UpdateDisplayIPAddress();
    static void ButtonSettingsCancelRelease(void *);
    static void ButtonSettingsSaveRelease(void *);
    static void ButtonManualDistillPumpRelease(void *);
    static void SetDisplayRTCTime();
    static void HomeButtonRelease(void *);
    static void UpdateTimeOnManualBrewPage();
    static void ButtonAutoDistillRelease(void *);
    static void ButtonBrewHltUpRelease(void *);
    static void ButtonBrewHltUpPress(void *);
    static void SliderManualDistillRelease(void *);
    static void ButtonManualDistillBoilRelease(void *);
    static void ButtonManualBrewResetRelease(void *);
    static void ButtonManualBrewHermsRelease(void *);
    static void ButtonManualBrewPumpRelease(void *);
    static void ButtonManualBrewStartRelease(void *);
    static void ButtonManualBrewBoilRelease(void *);
    static void ButtonManualBrewHltRelease(void *);
    static void ButtonAutoBrewNextRelease(void *);
    static void ButtonAutoBrewHLTRelease(void *);
    static void ButtonAutoBrewBoilRelease(void *);
    static void ButtonAutoBrewRelease(void *);
    static void ButtonManualBrewRelease(void *);
    static void ButtonManualDistillRelease(void *);
    static void ButtonSettingRelease(void *);
    static void ButtonBrewTimeDownPress(void *);
    static void ButtonBrewTimeDownRelease(void *);
    static void ButtonBrewTimeUpPress(void *);
    static void ButtonBrewTimeUpRelease(void *);
    static void ButtonBrewBoilDownPress(void *);
    static void ButtonBrewBoilDownRelease(void *);
    static void ButtonBrewBoilUpPress(void *);
    static void ButtonBrewBoilUpRelease(void *);
    static void ButtonBrewMltDownPress(void *);
    static void ButtonBrewMltDownRelease(void *);
    static void ButtonBrewMltUpPress(void *);
    static void ButtonBrewMltUpRelease(void *);
    static void ButtonBrewHltDownPress(void *);
    static void ButtonBrewHltDownRelease(void *);

public:
    static Display *getInstance()
    {
        if (!instance)
            instance = new Display;
        return instance;
    }
    void begin();
    static void UpdateDisplay();
    static void listenThread();
    static void sendThread();
    static void updateActualTemp(temperature_sensor_t t, char * v);
    static void updateTargetTemp(temperature_sensor_t t, char * v);
    static void updateIpAddress(char *ip);
    static void updateSsid(char *ssid);
    static void updateAmps(char * leg1, char * leg2);
    static void setDisplayRTCTime(tm * timeinfo);
};

#endif /*__DISPLAY_H__*/