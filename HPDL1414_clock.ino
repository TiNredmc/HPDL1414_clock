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
char dow;
int yea = 0;
int mon = 0;
int days = 0;
void setup() {
 Serial.begin(9600);
  rtc.begin();
  dl1414.clear();
 
}

void loop() {
  
  dl1414.clear();
    // Get the time from the DS1307.
    DateTime now = rtc.now();
    // Now set the hours and minutes.
    hours = now.hour();
    minutes = now.minute();
    dow = now.dayOfTheWeek();
    days = now.day();
    mon = now.month();
    yea = now.year();
int displayValue = hours*100 + minutes;
int dayDisplay = days*1;
int monthDispaly = mon*1;
int yearDisplay = yea*1;
String str= String(displayValue);
String dowS = String(dow);
String dayS= String(days);
String monS= String(mon);
String yeaS= String(yea);
  // Now print the time value to the display.
  dl1414.writeStringFix(str);
  Serial.print(str);
  Serial.print("/");
  delay(500);
  dl1414.writeStringFix(dowS);
  Serial.print(dowS);
  Serial.print("/");
  delay(500);
  dl1414.writeStringFix(dayS);
  Serial.print(dayS);
  Serial.print("/");
  delay(500);
  dl1414.writeStringFix(monS);
  Serial.print(monS);
  Serial.print("/");
  delay(500);
  dl1414.writeStringFix(yeaS);
  Serial.print(yeaS);
  Serial.print("/");
  delay(500);
}

