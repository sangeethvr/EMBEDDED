

// the sensor communicates using SPI, so include the library:
#include <SPI.h>

void setup() {
  char a[]={0x3f,0,2,8,0x19,0x10};
  pinMode(10,OUTPUT);//slave select channel select chip select
   pinMode(9,OUTPUT);
  digitalWrite(10,1);
  digitalWrite(9,1);
  Serial.begin(9600); 
  SPI.begin();
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE3));
  digitalWrite(10,0);
SPI.transfer(a,5);//3 8 0x3 0x08 0x308 0000 0011 0000 1000  0x308
   digitalWrite(10,1);
}

void loop() {
  byte c[5]; 
/* digitalWrite(10,0);
SPI.transfer(0xBF);//3 8 0x3 0x08 0x308 0000 0011 0000 1000  0x308 
for(int i=0;i<=4;i++)
c[i] = SPI.transfer(0);
   digitalWrite(10,1);
  for(int i=0;i<=4;i++) 
 Serial.println(c[i]);*/
 delay(1000);
 digitalWrite(9,0);
 c[0]=SPI.transfer(0x08);
   digitalWrite(9,1);
    Serial.println(c[0],HEX);
 }
  
