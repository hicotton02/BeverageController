#ifndef DISPLAY_H
#define DISPLAY_H


void DisplayInit();
void ProcessDisplayTask(void *parameter);
void UpdateDisplayTask(void *parameter);
void UpdateDisplayIPAddress();
void UpdateDisplayAmps();
void UpdateDisplaySsid();
void GetTime();
void SetDisplayRTCTime();
void HomeButtonRelease(void *ptr);
void UpdateTimeOnManualBrewPage();
void ButtonBrewHltUpRelease(void *ptr);
void ButtonBrewHltUpPress(void *ptr);
void ButtonBrewHltDownRelease(void *ptr);
void ButtonBrewHltDownPress(void *ptr);
void ButtonBrewMltUpRelease(void *ptr);
void ButtonBrewMltUpPress(void *ptr);
void ButtonBrewMltDownRelease(void *ptr);
void ButtonBrewMltDownPress(void *ptr);
void ButtonBrewBoilUpRelease(void *ptr);
void ButtonBrewBoilUpPress(void *ptr);
void ButtonBrewBoilDownRelease(void *ptr);
void ButtonBrewBoilDownPress(void *ptr);
void ButtonBrewTimeUpRelease(void *ptr);
void ButtonBrewTimeUpPress(void *ptr);
void ButtonBrewTimeDownRelease(void *ptr);
void ButtonBrewTimeDownPress(void *ptr);
void ButtonSettingRelease(void *ptr);
void ButtonManualDistillRelease(void *ptr);
void ButtonAutoDistillRelease(void *ptr);
void ButtonManualBrewRelease(void *ptr);
void ButtonAutoBrewRelease(void *ptr);
void ButtonAutoBrewHLTRelease(void *ptr);
void ButtonAutoBrewBoilRelease(void *ptr);
void ButtonAutoBrewNextRelease(void *ptr);
void ButtonManualBrewHltRelease(void *ptr);
void ButtonManualBrewBoilRelease(void *ptr);
void ButtonManualBrewPumpRelease(void *ptr);
void ButtonManualBrewHermsRelease(void *ptr);
void ButtonManualBrewResetRelease(void *ptr);
void ButtonManualBrewStartRelease(void *ptr);
void ButtonManualDistillBoilRelease(void *ptr);
void SliderManualDistillRelease(void *ptr);
void ButtonManualDistillPumpRelease(void *ptr);
void ButtonSettingsSaveRelease(void *ptr);
void ButtonSettingsCancelRelease(void *ptr);

#endif