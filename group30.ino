#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
  Serial.begin(9600);
  Serial.print("group : 30\n"); 
  Serial.print("03050841\n"); 
 Serial.println("03053613");
 
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);


}
void loop()
{
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
      Serial.println(val);    
      if(val>=0 && val<10000)
      {
        sevseg.setNumber(val);
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
      
      
    }
    else
            sevseg.refreshDisplay();

    
}
  

