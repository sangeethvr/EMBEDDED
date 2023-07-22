// the sensor communicates using SPI, so include the library:
#include <SPI.h>

void setup() {
 
  pinMode(10,OUTPUT);//slave select channel select chip select
  digitalWrite(10,1);
  Serial.begin(9600);
  SPI.begin();
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE3));
 
}

void loop()
{
 
 int num=48;
 delay(1000);
 digitalWrite(10,0);
 for(int i=0;i<=10;i++)
 {
  SPI.transfer(num++);//3 8 0x3 0x08 0x308 0000 0011 0000 1000  0x308
  delay(2000);
 }
   digitalWrite(10,1);
   
 }