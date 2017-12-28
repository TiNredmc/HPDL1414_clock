#include <DL1414.h>

/**
   These are the pin names as in the DL1414 datasheet.
   Define them as you have connected them on your circuit.
*/
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

void setup() {
  // After powerup some DL1414 modules show random characters
  Serial.begin(9600);
  dl1414.clear();
  dl1414.writeStringScrolling("USE ONLY UPPER CASE CHARACTER ! FOR HPDL1414 16 SEGS.", 133);
  
}
char displaybuffer[4] = {' ', ' ', ' ', ' '};
void loop() {
  while (! Serial.available()) return;

  char c = Serial.read();
  if (! isprint(c)) return; // only printable!

  displaybuffer[0] = displaybuffer[1];
  displaybuffer[1] = displaybuffer[2];
  displaybuffer[2] = displaybuffer[3];
  displaybuffer[3] = c;

  dl1414.writeByte(displaybuffer[0],3 );
  dl1414.writeByte(displaybuffer[1],2 );
  dl1414.writeByte(displaybuffer[2],1 );
  dl1414.writeByte(displaybuffer[3],0 );
  delay(200);
}
