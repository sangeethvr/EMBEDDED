#include<pic.h>
void main()
{
TRISD=0x07;
TRISB=0x00;
PORTB=0x00;
PORTD=0x00;
while(1)
{
if(RD0==1 && RD1==1 && RD2==1) 
{
PORTB=0x07;
}
else
{
RB2=0;
}
if(RD1==1||RD2==1||RD0==1)
{
RB0=1;
}
else
{
RB0=0;
}
if((RD0==1&&RD1==1)||(RD1==1 && RD2==1)||(RD0==1 && RD2==1))
{
RB0=1;
RB1=1;
}
else
{
RB1=0;
}
}
}