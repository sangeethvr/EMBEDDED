#include <SoftwareSerial.h>
SoftwareSerial m(2, 3);//rx 2 tx 3
void setup() {
  // put your setup code here, to run once:
m.begin(9600);
Serial.begin(9600);
}
String s,lat,lon;
void loop() {
  // put your main code here, to run repeatedly:
if(m.available())
{
  if(m.read()=='$')
  {
    s=m.readStringUntil(',');
   
    if(s.compareTo("GPGGA")==0)
    {
      m.readStringUntil(',');
      lat=m.readStringUntil(',');
      m.readStringUntil(',');
      lon=m.readStringUntil(',');
      Serial.print("Lat : ");
      Serial.print(lat);
      Serial.print("Lon : ");
      Serial.println(lon);
      }
    
    }
  }
}
