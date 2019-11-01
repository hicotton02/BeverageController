#include "display.h"

NexPage Display::lockPage = NexPage(0, 0, "Lock");

NexPage Display::selectPage = NexPage(1, 0, "Select");
NexButton Display::autoBrewButton = NexButton(1, 1, "bAutoBrew");
NexButton Display::manualBrewButton = NexButton(1, 2, "bManualBrew");
NexButton Display::autoDistillButton = NexButton(1, 3, "bAutoDistill");
NexButton Display::manualDistillButton = NexButton(1, 4, "bManualDistill");
NexButton Display::settingsButton = NexButton(1, 5, "bSettings");

NexPage Display::autoBrewPage = NexPage(2, 0, "BrewAuto");
NexDSButton Display::autoBrewHLTButton = NexDSButton(2, 7, "btHlt");
NexDSButton Display::autoBrewBoilButton = NexDSButton(2, 8, "btBoil");
NexDSButton Display::autoBrewMainPumpButton = NexDSButton(2, 42, "btMain");
NexDSButton Display::autoBrewHermsPumpButton = NexDSButton(2, 41, "btHerms");
NexButton Display::autoBrewNextButton = NexButton(2, 1, "bNext");
NexText Display::autoBrewHltActual = NexText(2, 29, "aHlt");
NexText Display::autoBrewHltTarget = NexText(2, 26, "tHlt");
NexText Display::autoBrewMltActual = NexText(2, 30, "aMlt");
NexText Display::autoBrewMltTarget = NexText(2, 38, "tMlt");
NexText Display::autoBrewBoilActual = NexText(2, 31, "aBoil");
NexText Display::autoBrewBoilTarget = NexText(2, 27, "tBoil");
NexText Display::autoBrewIpAddress = NexText(2, 18, "BrewAuto.tIp");
NexText Display::autoBrewSsid = NexText(2, 20, "BrewAuto.tSsid");
NexText Display::autoBrewAmpsLeg1 = NexText(2, 41, "tLeg1Amps");
NexText Display::autoBrewAmpsLeg2 = NexText(2, 43, "tLeg2Amps");
NexNumber Display::autoBrewHours = NexNumber(2, 12, "nHour");
NexNumber Display::autoBrewMinutes = NexNumber(2, 15, "nMin");
NexNumber Display::autoBrewSeconds = NexNumber(2, 16, "nSec");
NexButton Display::autoBrewHomeButton = NexButton(2, 33, "bHome");
NexVariable Display::autoBrewStatusMessage = NexVariable(2, 34, "BrewAuto.vStatusMsg");

NexPage Display::manualBrewPage = NexPage(3, 0, "BrewManual");
NexDSButton Display::manualBrewHLTButton = NexDSButton(3, 1, "btHlt");
NexDSButton Display::manualBrewBoilButton = NexDSButton(3, 2, "btBoil");
NexDSButton Display::manualBrewPumpButton = NexDSButton(3, 6, "btMain");
NexDSButton Display::manualBrewHermsButton = NexDSButton(3, 7, "btHerms");
NexButton Display::manualBrewResetButton = NexButton(3, 20, "bReset");
NexButton Display::manualBrewHltUpButton = NexButton(3, 27, "btHltUp");
NexButton Display::manualBrewHltDownButton = NexButton(3, 29, "btHltDown");
NexButton Display::manualBrewMltUpButton = NexButton(3, 35, "btMltUp");
NexButton Display::manualBrewMltDownButton = NexButton(3, 36, "btMltDown");
NexButton Display::manualBrewBoilUpButton = NexButton(3, 28, "btBoilUp");
NexButton Display::manualBrewBoilDownButton = NexButton(3, 30, "btBoilDown");
NexButton Display::manualBrewTimeUpButton = NexButton(3, 39, "btTimeUp");
NexButton Display::manualBrewTimeDownButton = NexButton(3, 40, "btTimeDown");
NexText Display::manualBrewHltActual = NexText(3, 31, "aHlt");
NexText Display::manualBrewHltTarget = NexText(3, 24, "tHlt");
NexText Display::manualBrewMltActual = NexText(3, 32, "aMlt");
NexText Display::manualBrewMltTarget = NexText(3, 26, "tMlt");
NexText Display::manualBrewBoilActual = NexText(3, 33, "aBoil");
NexText Display::manualBrewBoilTarget = NexText(3, 25, "tBoil");
NexText Display::manualBrewIpAddress = NexText(3, 15, "BrewManual.tIp");
NexText Display::manualBrewSsid = NexText(3, 16, "BrewManual.tSsid");
NexText Display::manualBrewAmpsLeg1 = NexText(3, 45, "tLeg1Amps");
NexText Display::manualBrewAmpsLeg2 = NexText(3, 47, "tLeg2Amps");
NexNumber Display::manualBrewHours = NexNumber(3, 8, "nHour");
NexNumber Display::manualBrewMinutes = NexNumber(3, 11, "nMin");
NexNumber Display::manualBrewSeconds = NexNumber(3, 12, "nSec");
NexButton Display::manualBrewHomeButton = NexButton(3, 37, "bHome");
NexButton Display::manualBrewStartButton = NexButton(3, 38, "bStart");
NexVariable Display::manualBrewStatusMessage = NexVariable(3, 45, "BrewManual.vStatusMsg");

NexPage Display::autoDistillPage = NexPage(4, 0, "DistillAuto");
NexButton Display::autoDistillHomeButton = NexButton(4, 13, "bHome");
NexText Display::autoDistillIpAddress = NexText(4, 8, "DistillAuto.tIp");
NexText Display::autoDistillSsid = NexText(4, 10, "DistillAuto.tSsid");
NexText Display::autoDistillAmpsLeg1 = NexText(4, 23, "tLeg1Amps");
NexText Display::autoDistillAmpsLeg2 = NexText(4, 25, "tLeg2Amps");
NexText Display::autoDistillColumnActual = NexText(4, 14, "aColumn");
NexText Display::autoDistillBoilActual = NexText(4, 15, "aBoil");
NexText Display::autoDistillAbv = NexText(4, 24, "tABV");
NexVariable Display::autoDistillStatusMessage = NexVariable(4, 22, "DistillAuto.vStatusMsg");

NexPage Display::manualDistillPage = NexPage(5, 0, "DistillManual");
NexDSButton Display::manualDistillBoilButton = NexDSButton(5, 11, "btBoil");
NexDSButton Display::manualDistillPumpButton = NexDSButton(5, 22, "btPump");
NexText Display::manualDistillColumnActual = NexText(5, 12, "aColumn");
NexText Display::manualDistillBoilActual = NexText(5, 13, "aBoil");
NexText Display::manualDistillCoolantActual = NexText(5, 27, "aCoolant");
NexSlider Display::manualDistillSlider = NexSlider(5, 16, "hPP");
NexNumber Display::manualDistillPowerPercentage = NexNumber(5, 19, "nPowerPercent");
NexText Display::manualDistillIpAddress = NexText(5, 7, "DistillManual.tIp");
NexText Display::manualDistillSsid = NexText(5, 9, "DistillManual.tSsid");
NexText Display::manualDistillAmpsLeg1 = NexText(5, 10, "tLeg1Amps");
NexText Display::manualDistillAmpsLeg2 = NexText(5, 29, "tLeg2Amps");
NexText Display::manualDistillAbv = NexText(5, 25, "tABV");
NexButton Display::manualDistillHomeButton = NexButton(5, 21, "bHome");
NexVariable Display::manualDistillStatusMessage = NexVariable(5, 24, "DistillManual.vStatusMsg");

NexPage Display::settingsPage = NexPage(6, 0, "Settings");
NexButton Display::settingsSaveButton = NexButton(6, 1, "bSave");
NexButton Display::settingsCancelButton = NexButton(6, 2, "bCancel");
NexText Display::settingsSsid = NexText(6, 4, "tSsid");
NexText Display::settingsPass = NexText(6, 5, "tPass");
NexCheckbox Display::settingsHerms = NexCheckbox(6, 8, "cHerms");
NexCheckbox Display::settingsStillPump = NexCheckbox(6, 10, "cStillPump");
NexText Display::settingsTimeZone = NexText(6, 11, "tTimeZone");
u_int Display::pageDisplayed = 0;

bool Display::manualHltButtonUpPressed = false;
bool Display::manualHltButtonDownPressed = false;
bool Display::manualMltButtonUpPressed = false;
bool Display::manualMltButtonDownPressed = false;
bool Display::manualBoilButtonUpPressed = false;
bool Display::manualBoilButtonDownPressed = false;
bool Display::manualTimeButtonUpPressed = false;
bool Display::manualTimeButtonDownPressed = false;

NexTouch *Display::nex_listen_list[42] = {
    &settingsPage,
    &manualDistillPage,
    &autoDistillPage,
    &manualBrewPage,
    &autoBrewPage,
    &selectPage,
    &lockPage,
    &autoBrewMainPumpButton,
    &autoBrewHermsPumpButton,
    &autoDistillButton,
    &manualDistillButton,
    &settingsButton,
    &autoBrewButton,
    &manualBrewButton,
    &autoBrewHLTButton,
    &autoBrewBoilButton,
    &autoBrewNextButton,
    &manualBrewHLTButton,
    &manualBrewBoilButton,
    &manualBrewPumpButton,
    &manualBrewHermsButton,
    &manualBrewResetButton,
    &manualBrewStartButton,
    &manualDistillBoilButton,
    &manualDistillPumpButton,
    &manualDistillSlider,
    &manualDistillHomeButton,
    &settingsSaveButton,
    &settingsCancelButton,
    &autoBrewHomeButton,
    &manualBrewHomeButton,
    &autoDistillHomeButton,
    &manualDistillHomeButton,
    &manualBrewHltUpButton,
    &manualBrewHltDownButton,
    &manualBrewMltUpButton,
    &manualBrewMltDownButton,
    &manualBrewBoilUpButton,
    &manualBrewBoilDownButton,
    &manualBrewTimeUpButton,
    &manualBrewTimeDownButton,
    NULL};

void Display::begin()
{
    Serial2.println("Setting up Display");
    nexInit();
    autoDistillButton.attachPop(ButtonAutoDistillRelease, &autoDistillButton);
    manualDistillButton.attachPop(ButtonManualDistillRelease, &manualDistillButton);
    settingsButton.attachPop(ButtonSettingRelease, &settingsButton);
    autoBrewButton.attachPop(ButtonAutoBrewRelease, &autoBrewButton);
    manualBrewButton.attachPop(ButtonManualBrewRelease, &manualBrewButton);
    autoBrewHLTButton.attachPop(ButtonAutoBrewHLTRelease, &autoBrewHLTButton);
    autoBrewBoilButton.attachPop(ButtonAutoBrewBoilRelease, &autoBrewBoilButton);
    autoBrewNextButton.attachPop(ButtonAutoBrewNextRelease, &autoBrewNextButton);
    manualBrewHLTButton.attachPop(ButtonManualBrewHltRelease, &manualBrewHLTButton);
    manualBrewBoilButton.attachPop(ButtonManualBrewBoilRelease, &manualBrewBoilButton);
    manualBrewPumpButton.attachPop(ButtonManualBrewPumpRelease, &manualBrewPumpButton);
    manualBrewHermsButton.attachPop(ButtonManualBrewHermsRelease, &manualBrewHermsButton);
    manualBrewResetButton.attachPop(ButtonManualBrewResetRelease, &manualBrewResetButton);
    manualBrewStartButton.attachPop(ButtonManualBrewStartRelease, &manualBrewStartButton);
    manualDistillBoilButton.attachPop(ButtonManualDistillBoilRelease, &manualDistillBoilButton);
    manualDistillPumpButton.attachPop(ButtonManualDistillPumpRelease, &manualDistillPumpButton);
    manualDistillSlider.attachPop(SliderManualDistillRelease, &manualDistillSlider);
    manualDistillHomeButton.attachPop(HomeButtonRelease, &manualDistillHomeButton);
    settingsSaveButton.attachPop(ButtonSettingsSaveRelease, &settingsSaveButton);
    settingsCancelButton.attachPop(ButtonSettingsCancelRelease, &settingsCancelButton);
    autoBrewHomeButton.attachPop(HomeButtonRelease, &autoBrewHomeButton);
    manualBrewHomeButton.attachPop(HomeButtonRelease, &manualBrewHomeButton);
    autoDistillHomeButton.attachPop(HomeButtonRelease, &autoDistillHomeButton);
    manualBrewHomeButton.attachPop(HomeButtonRelease, &manualBrewHomeButton);
    manualBrewHltUpButton.attachPop(ButtonBrewHltUpRelease, &manualBrewHltUpButton);
    manualBrewHltUpButton.attachPush(ButtonBrewHltUpPress, &manualBrewHltUpButton);
    manualBrewHltDownButton.attachPop(ButtonBrewHltDownRelease, &manualBrewHltDownButton);
    manualBrewHltDownButton.attachPush(ButtonBrewHltDownPress, &manualBrewHltDownButton);
    manualBrewMltUpButton.attachPop(ButtonBrewMltUpRelease, &manualBrewMltUpButton);
    manualBrewMltUpButton.attachPush(ButtonBrewMltUpPress, &manualBrewMltUpButton);
    manualBrewMltDownButton.attachPop(ButtonBrewMltDownRelease, &manualBrewMltDownButton);
    manualBrewMltDownButton.attachPush(ButtonBrewMltDownPress, &manualBrewMltDownButton);
    manualBrewBoilUpButton.attachPop(ButtonBrewBoilUpRelease, &manualBrewBoilUpButton);
    manualBrewBoilUpButton.attachPush(ButtonBrewBoilUpPress, &manualBrewBoilUpButton);
    manualBrewBoilDownButton.attachPush(ButtonBrewBoilDownPress, &manualBrewBoilDownButton);
    manualBrewBoilDownButton.attachPop(ButtonBrewBoilDownRelease, &manualBrewBoilDownButton);
    manualBrewTimeDownButton.attachPop(ButtonBrewTimeDownRelease, &manualBrewTimeDownButton);
    manualBrewTimeDownButton.attachPush(ButtonBrewTimeDownPress, &manualBrewTimeDownButton);
    manualBrewTimeUpButton.attachPop(ButtonBrewTimeUpRelease, &manualBrewTimeUpButton);
    manualBrewTimeUpButton.attachPush(ButtonBrewTimeUpPress, &manualBrewTimeUpButton);
}
void Display::updateAmps(char * leg1, char* leg2){
    int pageDisplayed = getPageDisplayed();
    switch (pageDisplayed) {
    case 2:
      autoBrewAmpsLeg1.setText(leg1);
      autoBrewAmpsLeg2.setText(leg2);
      break;
    case 3:
      manualBrewAmpsLeg1.setText(leg1);
      manualBrewAmpsLeg2.setText(leg2);
      break;
    case 4:
      autoDistillAmpsLeg1.setText(leg1);
      autoDistillAmpsLeg2.setText(leg2);
      break;
    case 5:
      manualDistillAmpsLeg1.setText(leg1);
      manualDistillAmpsLeg2.setText(leg2);
      break;
    default:
      break;
  }
}
void Display::updateSsid(char *ssid)
{
    int pageDisplayed = getPageDisplayed();
    switch (pageDisplayed)
    {
    case 2:
        autoBrewSsid.setText(ssid);
        break;
    case 3:
        manualBrewSsid.setText(ssid);
        break;
    case 4:
        autoDistillSsid.setText(ssid);
        break;
    case 5:
        manualDistillSsid.setText(ssid);
        break;
    default:
        break;
    }
}

void Display::updateIpAddress(char *ip)
{
    int pageDisplayed = getPageDisplayed();
    switch (pageDisplayed)
    {
    case 2:
        autoBrewIpAddress.setText(ip);
        break;
    case 3:
        manualBrewIpAddress.setText(ip);
        break;
    case 4:
        autoDistillIpAddress.setText(ip);
        break;
    case 5:
        manualDistillIpAddress.setText(ip);
        break;
    default:
        break;
    }
}

void Display::updateActualTemp(temperature_sensor_t t, char* v)
{
    //find out the page, and update the temp on that page
    pageDisplayed = getPageDisplayed();
    switch (t)
    {
    case Hlt_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewHltActual.setText(v);
            break;
        case 3:
            manualBrewHltActual.setText(v);
            break;
        default:
            break;
        }
        break;
    case Mlt_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewMltActual.setText(v);
            break;
        case 3:
            manualBrewMltActual.setText(v);
            break;
        default:
            break;
        }
        break;
    case Boiler_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewBoilActual.setText(v);
            break;
        case 3:
            manualBrewBoilActual.setText(v);
            break;
        default:
            break;
        }
        break;
    case Still_t:
        switch (pageDisplayed)
        {
        case 2:
            autoDistillBoilActual.setText(v);
            break;
        case 3:
            manualDistillBoilActual.setText(v);
            break;
        default:
            break;
        }
        break;
    case Column_t:
        switch (pageDisplayed)
        {
        case 2:
            autoDistillColumnActual.setText(v);
            break;
        case 3:
            manualDistillColumnActual.setText(v);
            break;
        default:
            break;
        }
        break;
    case Coolant_t:
        switch (pageDisplayed)
        {
        case 2:
            //autoDistillCoolantActual.setText(temp);
            break;
        case 3:
            manualDistillCoolantActual.setText(v);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void Display::updateTargetTemp(temperature_sensor_t t, char * v)
{
    //find out the page, and update the temp on that page
    pageDisplayed = getPageDisplayed();

    switch (t)
    {
    case Hlt_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewHltTarget.setText(v);
            break;
        case 3:
            manualBrewHltTarget.setText(v);
            break;
        default:
            break;
        }
        break;
    case Mlt_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewMltTarget.setText(v);
            break;
        case 3:
            manualBrewMltTarget.setText(v);
            break;
        default:
            break;
        }
        break;
    case Boiler_t:
        switch (pageDisplayed)
        {
        case 2:
            autoBrewBoilTarget.setText(v);
            break;
        case 3:
            manualBrewBoilTarget.setText(v);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void Display::listenThread()
{
    for (;;)
    {
        nexLoop(Display::nex_listen_list);
    }
    vTaskDelete(NULL);
}
void Display::sendThread()
{
    for (;;)
    {
        //feeding watchdog for now
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}
void Display::UpdateDisplay()
{
    /*
  UpdateDisplayAmps();
  if (stillRunning) {
    if (autoDistill) {
      //Auto Distill
    }
    else {
      //Manual Distill
      char abvText[6];
      char aBoilTemp[6];
      char aColumnTemp[6];
      char aCoolantTemp[6];
      dtostrf(actualSensorATemp, 3, 1, aColumnTemp);
      dtostrf(vaporAbv, 2, 1, abvText);
      dtostrf(actualSensorCTemp, 3, 1, aBoilTemp);
      dtostrf(actualSensorBTemp, 3, 1, aCoolantTemp);
      manualDistillColumnActual.setText(aColumnTemp);
      manualDistillBoilActual.setText(aBoilTemp);
      manualDistillCoolantActual.setText(aCoolantTemp);
      manualDistillAbv.setText(abvText);
    }
  }
  else if (brewSessionEnabled) {
    if (autoBrew) {
      //Auto Brew

    }
    else {
      //Manual Brew

    }
  }
  else {
    //non-updatable page
  }
  */
}
void Display::UpdateDisplayIPAddress()
{
    //manualDistillIpAddress.setText(localIp);
    //manualBrewIpAddress.setText(localIp);
}
void Display::UpdateDisplayAmps()
{
    /*
  dtostrf(leg1, 4, 1, ampDisplayLeg1);
  dtostrf(leg2, 4, 1, ampDisplayLeg2);
  switch (pageDisplayed) {
    case 2:
      autoBrewAmpsLeg1.setText(ampDisplayLeg1);
      autoBrewAmpsLeg2.setText(ampDisplayLeg2);
      break;
    case 3:
      manualBrewAmpsLeg1.setText(ampDisplayLeg1);
      manualBrewAmpsLeg2.setText(ampDisplayLeg2);
      break;
    case 4:
      autoDistillAmpsLeg1.setText(ampDisplayLeg1);
      autoDistillAmpsLeg2.setText(ampDisplayLeg2);
      break;
    case 5:
      manualDistillAmpsLeg1.setText(ampDisplayLeg1);
      manualDistillAmpsLeg2.setText(ampDisplayLeg2);
      break;
    default:
      break;
  }
  */
}
void Display::UpdateDisplaySsid()
{
    /*
  autoDistillSsid.setText(configuration.ssid);
  autoBrewSsid.setText(configuration.ssid);
  manualDistillSsid.setText(configuration.ssid);
  manualBrewSsid.setText(configuration.ssid);
  */
}
void Display::GetTime()
{
    //rtc.read_rtc_time(rtcTime, 7);
}
void Display::SetDisplayRTCTime()
{
    /*
    if (timeinfo.tm_year > 0)
    {
        rtcTime[0] = timeinfo.tm_year;
        rtcTime[1] = timeinfo.tm_mon;
        rtcTime[2] = timeinfo.tm_yday;
        rtcTime[3] = timeinfo.tm_hour;
        rtcTime[4] = timeinfo.tm_min;
        rtcTime[5] = timeinfo.tm_sec;
        rtc.write_rtc_time(rtcTime);
    }
    */
}
void Display::HomeButtonRelease(void *ptr)
{
    /*
    Serial2.println("In Home Routine");
    brewSessionEnabled = false;
    autoBrew = false;
    stillRunning = false;
    autoDistill = false;
    pageDisplayed = 1;
    */
}
void Display::UpdateTimeOnManualBrewPage()
{
    /*
    if (targetTimeInMinutes < 60)
    {
        manualBrewMinutes.setValue(targetTimeInMinutes);
    }
    else
    {
        uint8_t hours = targetTimeInMinutes / 60;
        manualBrewHours.setValue(hours);
        manualBrewMinutes.setValue(targetTimeInMinutes % 60);
    }
    */
}
void Display::ButtonBrewHltUpRelease(void *ptr)
{
    manualHltButtonUpPressed = false;
}
void Display::ButtonBrewHltUpPress(void *ptr)
{
    manualHltButtonUpPressed = true;
}
void Display::ButtonBrewHltDownRelease(void *ptr)
{
    manualHltButtonDownPressed = false;
}
void Display::ButtonBrewHltDownPress(void *ptr)
{
    manualHltButtonDownPressed = true;
}
void Display::ButtonBrewMltUpRelease(void *ptr)
{
    manualMltButtonUpPressed = false;
}
void Display::ButtonBrewMltUpPress(void *ptr)
{
    manualMltButtonUpPressed = true;
}
void Display::ButtonBrewMltDownRelease(void *ptr)
{
    manualMltButtonDownPressed = false;
}
void Display::ButtonBrewMltDownPress(void *ptr)
{
    manualMltButtonDownPressed = true;
}
void Display::ButtonBrewBoilUpRelease(void *ptr)
{
    manualBoilButtonUpPressed = false;
}
void Display::ButtonBrewBoilUpPress(void *ptr)
{
    manualBoilButtonUpPressed = true;
}
void Display::ButtonBrewBoilDownRelease(void *ptr)
{
    manualBoilButtonDownPressed = false;
}
void Display::ButtonBrewBoilDownPress(void *ptr)
{
    manualBoilButtonDownPressed = true;
}
void Display::ButtonBrewTimeUpRelease(void *ptr)
{
    manualTimeButtonUpPressed = false;
}
void Display::ButtonBrewTimeUpPress(void *ptr)
{
    manualTimeButtonUpPressed = true;
}
void Display::ButtonBrewTimeDownRelease(void *ptr)
{
    manualTimeButtonDownPressed = false;
}
void Display::ButtonBrewTimeDownPress(void *ptr)
{
    manualTimeButtonDownPressed = true;
}
void Display::ButtonSettingRelease(void *ptr)
{
    settingsPage.show();
    //state = SETTINGS;
}

void Display::ButtonManualDistillRelease(void *ptr)
{
    //EnableSession(false, false);
    Serial2.println(F("Starting Distilling Session from Manual Button"));
}

void Display::ButtonAutoDistillRelease(void *ptr)
{
    //EnableSession(false, true);
    Serial2.println(F("Starting Distilling Session from Auto Button"));
}

void Display::ButtonManualBrewRelease(void *ptr)
{
    //EnableSession(true, false);
    Serial2.println(F("Starting Brewing Session from Manual Button"));
}

void Display::ButtonAutoBrewRelease(void *ptr)
{
    //EnableSession(true, true);
    Serial2.println(F("Starting Brewing Session from Auto Button"));
}
void Display::ButtonAutoBrewHLTRelease(void *ptr)
{
    /*
    //override and toggle Hlt Element
    hltElementStatus = !hltElementStatus;
    autoBrewHLTButton.setValue(hltElementStatus);

    Serial2.print("Auto Brew Hlt Element changed to: ");
    Serial2.println(hltElementStatus);
    */
}
void Display::ButtonAutoBrewBoilRelease(void *ptr)
{
    /*
    //override and toggle Boil Element
    boilElementStatus = !boilElementStatus;
    autoBrewBoilButton.setValue(boilElementStatus);

    Serial2.print("Auto Brew Boil Element changed to: ");
    Serial2.println(boilElementStatus);
    */
}
void Display::ButtonAutoBrewNextRelease(void *ptr)
{
    //waitingOnUserResponse = false;
    //goToNextStep = true;
}
void Display::ButtonManualBrewHltRelease(void *ptr)
{
    //Toggle Hlt Element
    //hltElementStatus = !hltElementStatus;
    //manualBrewHLTButton.setValue(hltElementStatus);
}
void Display::ButtonManualBrewBoilRelease(void *ptr)
{
    //Toggle Boiler Element
    Serial2.println("Toggling Boiler Element from Display");
    //boilElementStatus = !boilElementStatus;
    //manualBrewBoilButton.setValue(boilElementStatus);
}
void Display::ButtonManualBrewPumpRelease(void *ptr)
{
    //Toggle Main Pump
    Serial2.println("Toggling Pump Element from Display");
    //mainPumpStatus = !mainPumpStatus;
    //manualBrewPumpButton.setValue(mainPumpStatus);
}
void Display::ButtonManualBrewHermsRelease(void *ptr)
{
    //Toggle Herms Pump
    //hermsPumpStatus = !hermsPumpStatus;
    //manualBrewHermsButton.setValue(hermsPumpStatus);
}
void Display::ButtonManualBrewResetRelease(void *ptr)
{
    // Reset page counter to 0s
    //targetTimeInMinutes = 0;
}
void Display::ButtonManualBrewStartRelease(void *ptr)
{
    //start counter
    //brewTimerStarted = true;
}
void Display::ButtonManualDistillBoilRelease(void *ptr)
{
    //Toggle Boiler Element
    Serial2.println("Toggling Boiler Element from Display");
    //boilElementStatus = !boilElementStatus;
    //manualDistillBoilButton.setValue(boilElementStatus);
}
void Display::SliderManualDistillRelease(void *ptr)
{
    //Set Power % for boiler
    unsigned int value;
    manualDistillSlider.getValue(&value);
    //boilerPowerPercentage = value / 100.0;
    //distillDutyTime = distillDutyCycle * boilerPowerPercentage;
}
void Display::ButtonManualDistillPumpRelease(void *ptr)
{
    //Toggle Recirculating Pump
    Serial2.println("Toggling Pump Element from Display");
    //mainPumpStatus = !mainPumpStatus;
    //manualDistillPumpButton.setValue(mainPumpStatus);
}
void Display::ButtonSettingsSaveRelease(void *ptr)
{
    /*
    settingsStillPump.getValue(&configuration.enableDistillPump);
    settingsHerms.getValue(&configuration.hermsEnabled);
    settingsSsid.getText(configuration.ssid, sizeof(configuration.ssid));
    settingsPass.getText(configuration.pass, sizeof(configuration.pass));
    settingsTimeZone.getText(configuration.timeZone, sizeof(configuration.timeZone));
*/
    //wifiSetup();
}
void Display::ButtonSettingsCancelRelease(void *ptr)
{
}