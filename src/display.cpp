#include "display.h"
#include "Nextion.h"

//Display Variables
int pageDisplayed = 0;
bool manualHltButtonUpPressed = false;
bool manualHltButtonDownPressed = false;
bool manualMltButtonUpPressed = false;
bool manualMltButtonDownPressed = false;
bool manualBoilButtonUpPressed = false;
bool manualBoilButtonDownPressed = false;
bool manualTimeButtonUpPressed = false;
bool manualTimeButtonDownPressed = false;
NexRtc rtc;
//Lock Page
NexPage lockPage = NexPage(0, 0, "Lock");

//Select Page
NexPage selectPage = NexPage(1, 0, "Select");
NexButton autoBrewButton = NexButton(1, 1, "bAutoBrew");
NexButton manualBrewButton = NexButton(1, 2, "bManualBrew");
NexButton autoDistillButton = NexButton(1, 3, "bAutoDistill");
NexButton manualDistillButton = NexButton(1, 4, "bManualDistill");
NexButton settingsButton = NexButton(1, 5, "bSettings");

//BrewAuto Page
NexPage autoBrewPage = NexPage(2, 0, "BrewAuto");
NexDSButton autoBrewHLTButton = NexDSButton(2, 7, "btHlt");
NexDSButton autoBrewBoilButton = NexDSButton(2, 8, "btBoil");
NexDSButton autoBrewMainPumpButton = NexDSButton(2, 42, "btMain");
NexDSButton autoBrewHermsPumpButton = NexDSButton(2, 41, "btHerms");
NexButton autoBrewNextButton = NexButton(2, 1, "bNext");
NexText autoBrewHltActual = NexText(2, 29, "aHlt");
NexText autoBrewHltTarget = NexText(2, 26, "tHlt");
NexText autoBrewMltActual = NexText(2, 30, "aMlt");
NexText autoBrewMltTarget = NexText(2, 38, "tMlt");
NexText autoBrewBoilActual = NexText(2, 31, "aBoil");
NexText autoBrewBoilTarget = NexText(2, 27, "tBoil");
NexText autoBrewIpAddress = NexText(2, 18, "BrewAuto.tIp");
NexText autoBrewSsid = NexText(2, 20, "BrewAuto.tSsid");
NexText autoBrewAmpsLeg1 = NexText(2, 41, "tLeg1Amps");
NexText autoBrewAmpsLeg2 = NexText(2, 43, "tLeg2Amps");
NexNumber autoBrewHours = NexNumber(2, 12, "nHour");
NexNumber autoBrewMinutes = NexNumber(2, 15, "nMin");
NexNumber autoBrewSeconds = NexNumber(2, 16, "nSec");
NexButton autoBrewHomeButton = NexButton(2, 33, "bHome");
NexVariable autoBrewStatusMessage = NexVariable(2, 34, "BrewAuto.vStatusMsg");

//BrewManual Page
NexPage manualBrewPage = NexPage(3, 0, "BrewManual");
NexDSButton manualBrewHLTButton = NexDSButton(3, 1, "btHlt");
NexDSButton manualBrewBoilButton = NexDSButton(3, 2, "btBoil");
NexDSButton manualBrewPumpButton = NexDSButton(3, 6, "btMain");
NexDSButton manualBrewHermsButton = NexDSButton(3, 7, "btHerms");
NexButton manualBrewResetButton = NexButton(3, 20, "bReset");
NexButton manualBrewHltUpButton = NexButton(3, 27, "btHltUp");
NexButton manualBrewHltDownButton = NexButton(3, 29, "btHltDown");
NexButton manualBrewMltUpButton = NexButton(3, 35, "btMltUp");
NexButton manualBrewMltDownButton = NexButton(3, 36, "btMltDown");
NexButton manualBrewBoilUpButton = NexButton(3, 28, "btBoilUp");
NexButton manualBrewBoilDownButton = NexButton(3, 30, "btBoilDown");
NexButton manualBrewTimeUpButton = NexButton(3, 39, "btTimeUp");
NexButton manualBrewTimeDownButton = NexButton(3, 40, "btTimeDown");
NexText manualBrewHltActual = NexText(3, 31, "aHlt");
NexText manualBrewHltTarget = NexText(3, 24, "tHlt");
NexText manualBrewMltActual = NexText(3, 32, "aMlt");
NexText manualBrewMltTarget = NexText(3, 26, "tMlt");
NexText manualBrewBoilActual = NexText(3, 33, "aBoil");
NexText manualBrewBoilTarget = NexText(3, 25, "tBoil");
NexText manualBrewIpAddress = NexText(3, 15, "BrewManual.tIp");
NexText manualBrewSsid = NexText(3, 16, "BrewManual.tSsid");
NexText manualBrewAmpsLeg1 = NexText(3, 45, "tLeg1Amps");
NexText manualBrewAmpsLeg2 = NexText(3, 47, "tLeg2Amps");
NexNumber manualBrewHours = NexNumber(3, 8, "nHour");
NexNumber manualBrewMinutes = NexNumber(3, 11, "nMin");
NexNumber manualBrewSeconds = NexNumber(3, 12, "nSec");
NexButton manualBrewHomeButton = NexButton(3, 37, "bHome");
NexButton manualBrewStartButton = NexButton(3, 38, "bStart");
NexVariable manualBrewStatusMessage = NexVariable(3, 45, "BrewManual.vStatusMsg");

//DistillAuto Page
NexPage autoDistillPage = NexPage(4, 0, "DistillAuto");
NexButton autoDistillHomeButton = NexButton(4, 13, "bHome");
NexText autoDistillIpAddress = NexText(4, 8, "DistillAuto.tIp");
NexText autoDistillSsid = NexText(4, 10, "DistillAuto.tSsid");
NexText autoDistillAmpsLeg1 = NexText(4, 23, "tLeg1Amps");
NexText autoDistillAmpsLeg2 = NexText(4, 25, "tLeg2Amps");
NexText autoDistillColumnActual = NexText(4, 14, "aColumn");
NexText autoDistillBoilActual = NexText(4, 15, "aBoil");
NexText autoDistillAbv = NexText(4, 24, "tABV");
NexVariable autoDistillStatusMessage = NexVariable(4, 22, "DistillAuto.vStatusMsg");

//DistillManual Page
NexPage manualDistillPage = NexPage(5, 0, "DistillManual");
NexDSButton manualDistillBoilButton = NexDSButton(5, 11, "btBoil");
NexDSButton manualDistillPumpButton = NexDSButton(5, 22, "btPump");
NexText manualDistillColumnActual = NexText(5, 12, "aColumn");
NexText manualDistillBoilActual = NexText(5, 13, "aBoil");
NexText manualDistillCoolantActual = NexText(5, 27, "aCoolant");
NexSlider manualDistillSlider = NexSlider(5, 16, "hPP");
NexNumber manualDistillPowerPercentage = NexNumber(5, 19, "nPowerPercent");
NexText manualDistillIpAddress = NexText(5, 7, "DistillManual.tIp");
NexText manualDistillSsid = NexText(5, 9, "DistillManual.tSsid");
NexText manualDistillAmpsLeg1 = NexText(5, 10, "tLeg1Amps");
NexText manualDistillAmpsLeg2 = NexText(5, 29, "tLeg2Amps");
NexText manualDistillAbv = NexText(5, 25, "tABV");
NexButton manualDistillHomeButton = NexButton(5, 21, "bHome");
NexVariable manualDistillStatusMessage = NexVariable(5, 24, "DistillManual.vStatusMsg");

//Settings Page
NexPage settingsPage = NexPage(6, 0, "Settings");
NexButton settingsSaveButton = NexButton(6, 1, "bSave");
NexButton settingsCancelButton = NexButton(6, 2, "bCancel");
NexText settingsSsid = NexText(6, 4, "tSsid");
NexText settingsPass = NexText(6, 5, "tPass");
NexCheckbox settingsHerms = NexCheckbox(6, 8, "cHerms");
NexCheckbox settingsStillPump = NexCheckbox(6, 10, "cStillPump");
NexText settingsTimeZone = NexText(6, 11, "tTimeZone");

NexTouch *nex_listen_list[] = {
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

void UpdateDisplayTask(void *parameter)
{
  while (1)
  {
    //    UBaseType_t uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    //    Serial2.print( "Update Display Task Memory: " );
    //    Serial2.print(uxHighWaterMark );
    //    Serial2.print( " ");
    //    Serial2.println( esp_get_free_heap_size() );
    UpdateDisplay();
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}
void ProcessDisplayTask(void *parameter)
{
  while (1)
  {
    nexLoop(nex_listen_list);
    pageDisplayed = getPageDisplayed(); //this needs to go somewhere else
    //Serial2.print("Page Index = ");
    //Serial2.println(pageDisplayed);
    vTaskDelay(10);
  }
}
void DisplayInit()
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
  SetDisplayRTCTime();
  UpdateDisplaySsid();
  UpdateDisplayIPAddress();
}
void UpdateDisplay()
{
  UpdateDisplayAmps();
  if (stillRunning)
  {
    if (autoDistill)
    {
      //Auto Distill
    }
    else
    {
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
  else if (brewSessionEnabled)
  {
    if (autoBrew)
    {
      //Auto Brew
    }
    else
    {
      //Manual Brew
    }
  }
  else
  {
    //non-updatable page
  }
}
void UpdateDisplayIPAddress()
{
  manualDistillIpAddress.setText(localIp);
  manualBrewIpAddress.setText(localIp);
}
void UpdateDisplayAmps()
{
  dtostrf(leg1, 4, 1, ampDisplayLeg1);
  dtostrf(leg2, 4, 1, ampDisplayLeg2);
  switch (pageDisplayed)
  {
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
}
void UpdateDisplaySsid()
{
  autoDistillSsid.setText(configuration.ssid);
  autoBrewSsid.setText(configuration.ssid);
  manualDistillSsid.setText(configuration.ssid);
  manualBrewSsid.setText(configuration.ssid);
}
void GetTime()
{
  rtc.read_rtc_time(rtcTime, 7);
}
void SetDisplayRTCTime()
{
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
}
void HomeButtonRelease(void *ptr)
{
  Serial2.println("In Home Routine");
  brewSessionEnabled = false;
  autoBrew = false;
  stillRunning = false;
  autoDistill = false;
  pageDisplayed = 1;
}
void UpdateTimeOnManualBrewPage()
{
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
}
void ButtonBrewHltUpRelease(void *ptr)
{
  manualHltButtonUpPressed = false;
}
void ButtonBrewHltUpPress(void *ptr)
{
  manualHltButtonUpPressed = true;
}
void ButtonBrewHltDownRelease(void *ptr)
{
  manualHltButtonDownPressed = false;
}
void ButtonBrewHltDownPress(void *ptr)
{
  manualHltButtonDownPressed = true;
}
void ButtonBrewMltUpRelease(void *ptr)
{
  manualMltButtonUpPressed = false;
}
void ButtonBrewMltUpPress(void *ptr)
{
  manualMltButtonUpPressed = true;
}
void ButtonBrewMltDownRelease(void *ptr)
{
  manualMltButtonDownPressed = false;
}
void ButtonBrewMltDownPress(void *ptr)
{
  manualMltButtonDownPressed = true;
}
void ButtonBrewBoilUpRelease(void *ptr)
{
  manualBoilButtonUpPressed = false;
}
void ButtonBrewBoilUpPress(void *ptr)
{
  manualBoilButtonUpPressed = true;
}
void ButtonBrewBoilDownRelease(void *ptr)
{
  manualBoilButtonDownPressed = false;
}
void ButtonBrewBoilDownPress(void *ptr)
{
  manualBoilButtonDownPressed = true;
}
void ButtonBrewTimeUpRelease(void *ptr)
{
  manualTimeButtonUpPressed = false;
}
void ButtonBrewTimeUpPress(void *ptr)
{
  manualTimeButtonUpPressed = true;
}
void ButtonBrewTimeDownRelease(void *ptr)
{
  manualTimeButtonDownPressed = false;
}
void ButtonBrewTimeDownPress(void *ptr)
{
  manualTimeButtonDownPressed = true;
}
void ButtonSettingRelease(void *ptr)
{
  //settingsPage.show();
  state = SETTINGS;
}

void ButtonManualDistillRelease(void *ptr)
{
  EnableSession(false, false);
  Serial2.println("Starting Distilling Session from Manual Button");
}

void ButtonAutoDistillRelease(void *ptr)
{
  EnableSession(false, true);
}

void ButtonManualBrewRelease(void *ptr)
{
  EnableSession(true, false);
}

void ButtonAutoBrewRelease(void *ptr)
{
  EnableSession(true, true);
}
void ButtonAutoBrewHLTRelease(void *ptr)
{

  //override and toggle Hlt Element
  hltElementStatus = !hltElementStatus;
  autoBrewHLTButton.setValue(hltElementStatus);

  Serial2.print("Auto Brew Hlt Element changed to: ");
  Serial2.println(hltElementStatus);
}
void ButtonAutoBrewBoilRelease(void *ptr)
{
  //override and toggle Boil Element
  boilElementStatus = !boilElementStatus;
  autoBrewBoilButton.setValue(boilElementStatus);

  Serial2.print("Auto Brew Boil Element changed to: ");
  Serial2.println(boilElementStatus);
}
void ButtonAutoBrewNextRelease(void *ptr)
{
  waitingOnUserResponse = false;
  goToNextStep = true;
}
void ButtonManualBrewHltRelease(void *ptr)
{
  //Toggle Hlt Element
  hltElementStatus = !hltElementStatus;
  manualBrewHLTButton.setValue(hltElementStatus);
}
void ButtonManualBrewBoilRelease(void *ptr)
{
  //Toggle Boiler Element
  Serial2.println("Toggling Boiler Element from Display");
  boilElementStatus = !boilElementStatus;
  manualBrewBoilButton.setValue(boilElementStatus);
}
void ButtonManualBrewPumpRelease(void *ptr)
{
  //Toggle Main Pump
  Serial2.println("Toggling Pump Element from Display");
  mainPumpStatus = !mainPumpStatus;
  manualBrewPumpButton.setValue(mainPumpStatus);
}
void ButtonManualBrewHermsRelease(void *ptr)
{
  //Toggle Herms Pump
  hermsPumpStatus = !hermsPumpStatus;
  manualBrewHermsButton.setValue(hermsPumpStatus);
}
void ButtonManualBrewResetRelease(void *ptr)
{
  // Reset page counter to 0s
  targetTimeInMinutes = 0;
}
void ButtonManualBrewStartRelease(void *ptr)
{
  //start counter
  brewTimerStarted = true;
}
void ButtonManualDistillBoilRelease(void *ptr)
{
  //Toggle Boiler Element
  Serial2.println("Toggling Boiler Element from Display");
  boilElementStatus = !boilElementStatus;
  manualDistillBoilButton.setValue(boilElementStatus);
}
void SliderManualDistillRelease(void *ptr)
{
  //Set Power % for boiler
  unsigned int value;
  manualDistillSlider.getValue(&value);
  boilerPowerPercentage = value / 100.0;
  distillDutyTime = distillDutyCycle * boilerPowerPercentage;
}
void ButtonManualDistillPumpRelease(void *ptr)
{
  //Toggle Recirculating Pump
  Serial2.println("Toggling Pump Element from Display");
  mainPumpStatus = !mainPumpStatus;
  manualDistillPumpButton.setValue(mainPumpStatus);
}
void ButtonSettingsSaveRelease(void *ptr)
{

  settingsStillPump.getValue(&configuration.enableDistillPump);
  settingsHerms.getValue(&configuration.hermsEnabled);
  settingsSsid.getText(configuration.ssid, sizeof(configuration.ssid));
  settingsPass.getText(configuration.pass, sizeof(configuration.pass));
  settingsTimeZone.getText(configuration.timeZone, sizeof(configuration.timeZone));

  //wifiSetup();
}
void ButtonSettingsCancelRelease(void *ptr)
{
}