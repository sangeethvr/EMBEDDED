#include<pic.h>
void main()
{
int j,i;
TRISD=0x01;
TRISB=0x00;
PORTB=0x00;
PORTD=0x00;
while(1)
{
if(RD0==1)
{
for(j=8;j>=0;j--)
{
PORTB=0xff>>j;
for(i=0;i<=1000;i++);
}
}
else
{
PORTB=0x00;
}
}
}