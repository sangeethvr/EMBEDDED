#include<pic.h>
void main()
{
TRISB=0x00;
TRISD=0x01;//0000 0001
PORTB=0X00;
PORTC=0X00;
while(1)
{
if(RD0==1)
{
PORTB=0xff;
}
if(RD0==0)
{

PORTB=0x00;
}

}

}