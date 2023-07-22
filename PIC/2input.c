#include<pic.h>
void main()
{
TRISD=0x03;
TRISB=0x00;
PORTB=0x00;
PORTD=0x00;
while(1)
{
if(RD0==1 && RD1==1)
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
}
}