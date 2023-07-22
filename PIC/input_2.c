#include<pic.h>
void main()
{
int  I;
TRISB=0x00;
TRISD=0x01;
PORTB=0x00;
PORTD=0x00;
while(1)
{
if(RD0==1)
{
int j;
for(j=8;j>=0;j--)
{
PORTB=0XFF>>j;
for(I=0;I<=5000;I++)
{}
}
}
else
{
PORTB=~PORTB;
for(I=0;I<=5000;I++)
{}
}

}
}