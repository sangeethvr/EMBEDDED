#include<pic.h>
void main()
{
int a,i;
TRISD=0x01;
TRISB=0x00;
PORTB=0x00;
PORTD=0x00;
while(1)
{
PORTB=~PORTB;
for(i=0;i<=1000;i++)
{}
if(RD0==1 && a!=1)
{a=1;
PORTB=0x00;
}
else if(RD0==0 &&a!=0)
{
a=0;
PORTB=0xaa;
}
}
}