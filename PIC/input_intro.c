#include<pic.h>
void main()
{
TRISB=0x00;
TRISD=0x01;//0000 0001
PORTB=0X00;
PORTC=0X00;
while(1)
{
RB0=RD0;
RB1=RD0;

}

}