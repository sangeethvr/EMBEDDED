#include<pic.h>
void main()
{
int sw=0;
TRISB=0x00;
PORTB=0X00;
TRISD=0X40;
PORTD=0X00;
while(1)
{
if(RD6==1)
{
while(RD6==1)
{
}
if(sw%2==1)
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
sw++;//sw=1
}
}

}