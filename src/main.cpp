#include "sensors.h"

//pinout
#define ON_LED 12
#define USB_TX 1
#define USB_RX 3
#define TEMPA_BUS 4           //Onewire1
#define TEMPC_BUS 5           //onewire2
#define ELEMENT2_SSR_RELAY 13 //Boiler
#define ELEMENT1_SSR_RELAY 14 //HLT or Still
#define PUMP1_RELAY 15        //Main pump or recirculating pump for still
#define DEBUG_TX 16
#define DEBUG_RX 17
#define ELEMENT1_CONTACTOR_RELAY 18 //HLT or Still Boiler Element 2
#define ERROR_RELAY 19              //Error LED
#define TEMPB_BUS 23                //Onewire3
#define ELEMENT2_CONTACTOR_RELAY 25 //Brew Boiler or Still Boiler Element 1
#define DISPLAY_TX 26
#define DISPLAY_RX 27
#define PUMP2_RELAY 33 //Herms Pump

#define BAUD_RATE 115200
uint64_t chipId;
typedef struct
{
  char ssid[26] = "xxxx";
  char pass[26] = "xxxxxxxxx";
  unsigned int hermsEnabled = 1;
  unsigned int enableDistillPump = 1;
  char timeZone[4] = "-8";
} CONFIG_T;

CONFIG_T configuration;
enum machineStates
{
  HOME,
  AUTO_BREW,
  MANUAL_BREW,
  AUTO_DISTILL,
  MANUAL_DISTILL,
  SETTINGS
};

void setup()
{
  Serial.begin(BAUD_RATE);                                      //Programming
  Serial1.begin(BAUD_RATE, SERIAL_8N1, DISPLAY_RX, DISPLAY_TX); //Display Port
  Serial2.begin(BAUD_RATE, SERIAL_8N1, DEBUG_RX, DEBUG_TX);     //Debug Port

  chipId = ESP.getEfuseMac(); //The chip ID is essentially its MAC address(length: 6 bytes).

  Sensors sensors;
  sensors.begin();

}

void loop()
{
  // not used
}