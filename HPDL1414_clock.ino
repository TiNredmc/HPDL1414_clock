#include <Wire.h> // i2c library 
#include <RTClib.h>// ds1307 library from adafruit ;D
#include <DL1414.h>// DL1414 Dot matrix and 16 segment version
int WR = A1;
int Addr0 =A3;
int Addr1 = A2;
int D0 = 2; 
int D1 = 3;
int D2 = 4;
int D3 = 5; 
int D4 = A0;
int D5 = 13;
int D6 = 6; 
// Init Library with proper pin definitions
DL1414 dl1414(WR, Addr0, Addr1, D0, D1, D2, D3, D4, D5, D6);
RTC_DS1307 rtc = RTC_DS1307();

int hours = 0;
int minutes = 0;

void setup() {
 Serial.begin(9600);
  rtc.begin();
  dl1414.clear();
 
}
int blinkDisp = 1;
void loop() {
    // Get the time from the DS1307.
    DateTime now = rtc.now();
    // Now set the hours and minutes.
    hours = now.hour();
    minutes = now.minute();
    
int displayValue = hours*100 + minutes;
 String str = String(displayValue);
 
  if (blinkDisp == 1) {
    //set the 0 infront of the hour less than 10 AM
    if ((hours < 10) && (hours >= 0))
    {
      str = "   0" + str;
      int l = str.length() + 1;
      byte b[l];
      str.getBytes(b, l);
      for (int i = 0; i < l - 4; i++) {
        dl1414.writeByte(3, b[0 + i]);
        dl1414.writeByte(2, b[1 + i]);
        dl1414.writeByte(1, b[2 + i]);
        dl1414.writeByte(0, b[3 + i]);
      }

    } else
    {
      str = "    " + str;
      int l = str.length() + 1;
      byte b[l];
      str.getBytes(b, l);
      for (int i = 0; i < l - 4; i++) {
        dl1414.writeByte(3, b[0 + i]);
        dl1414.writeByte(2, b[1 + i]);
        dl1414.writeByte(1, b[2 + i]);
        dl1414.writeByte(0, b[3 + i]);
      }

      //set the 0 infront of the minute less than 10 minutes
      if ((minutes < 10) && (minutes >= 0))
      {
        str = "  0 " + str;
        int l = str.length() + 1;
        byte b[l];
        str.getBytes(b, l);
        for (int i = 0; i < l - 4; i++) {
          dl1414.writeByte(3, b[0 + i]);
          dl1414.writeByte(2, b[1 + i]);
          dl1414.writeByte(1, b[2 + i]);
          dl1414.writeByte(0, b[3 + i]);

        }
      } else
      {
        str = "   0" + str;
        int l = str.length() + 1;
        byte b[l];
        str.getBytes(b, l);
        for (int i = 0; i < l - 4; i++) {
          dl1414.writeByte(3, b[0 + i]);
          dl1414.writeByte(2, b[1 + i]);
          dl1414.writeByte(1, b[2 + i]);
          dl1414.writeByte(0, b[3 + i]);
        }//for line92
      }//else line86
    }//else line59
    blinkDisp = 0 ;
    delay(500);
  } else
  { // blinkDisp line44
    dl1414.clear();
    blinkDisp = 1;
    delay(500);
  }
}

