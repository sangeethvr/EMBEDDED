#include <SoftwareSerial.h>

const byte rxPin = 2;//
const byte txPin = 3;
SoftwareSerial mySerial (rxPin, txPin);
void setup() {
  Serial.begin(9600);//
  mySerial.begin(9600);//
  pinMode(13,OUTPUT);

}

void loop() {
  if(mySerial.available())
  {
    char a=mySerial.read();
    if(a=='1')
    {
      digitalWrite(13,1);
      }
      else if(a=='2')
      {
        digitalWrite(13,0);
        }
       
        }
        mySerial.println(analogRead(0));
        delay(1000);
}
