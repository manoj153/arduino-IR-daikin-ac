
#include <DYIRDaikin.h>

//#define DYIRDAIKIN_SOFT_IR

DYIRDaikin irdaikin;
int isOn;
int temp1;
int fan1;
int on1;

byte payload1[3];

void setup()
{
  Serial.begin(9600);
  #ifdef DYIRDAIKIN_SOFT_IR
  irdaikin.begin(3);
  #else
  irdaikin.begin();
  #endif
  //irdaikin.on();
    irdaikin.setSwing_off();
    irdaikin.setMode(1);
//  irdaikin.setFan(4);//FAN speed to MAX
//  irdaikin.setTemp(25);
  //----everything is ok and to execute send command-----
//  irdaikin.sendCommand();
  isOn = 0;
}

void loop() {
  while (Serial.available() > 0) {

    Serial.readBytes(payload1, 2);

    temp1 = payload1[1];
    fan1 = payload1[0] & 0xF;
    on1 =  ((payload1[0] >> 4) & 0x01);

    Serial.println(temp1,DEC);
    Serial.println(fan1,DEC);
    Serial.println(on1,DEC);
  
    if(on1)
    {
      irdaikin.on();
      Serial.print("T1");
    }
    else 
    {
      irdaikin.off();
    }
    
    irdaikin.setFan(fan1);
    irdaikin.setTemp(temp1);
    irdaikin.sendCommand();
  }
  
}
