#include <SoftwareSerial.h>
SoftwareSerial m(2, 3);//rx 2 tx 3
void setup() {
  // put your setup code here, to run once:
m.begin(9600);//gsm
Serial.begin(9600);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
m.println("AT");
delay(2000);
}

void loop() {
  if(digitalRead(8))
  {
    Serial.println("Calling");
    m.println("ATD8921179126;");
    delay(5000);
    }
    else if(digitalRead(9))
    {
      Serial.println("Call disconnecting");
      m.println("ATH");
      Serial.println("Call disconnected");
      delay(5000);
      }
      else if(digitalRead(10))
    {
      Serial.println("Call Attending");
      m.println("ATA");
      Serial.println("Call connected");
      delay(5000);
      }
      else if(digitalRead(11))
      {
        Serial.println("Message Sending");
      m.println("AT+CMGF=1");
      delay(1000);
      m.println("AT+CMGS=\"8921179126\"");
      delay(1000);
      m.println("Hello from GSM");
      m.write(26);
      Serial.println("Message connected");
      delay(5000);
        }
}
