#include<pic.h>
void init(void)
{
TRISB=0x00;
PORTB=0x00;
TRISC=0x1f;
PORTC=0x00;
}

void main()
{
init();
while(1)
{
if(RC4==1)
{
if(RC0==1&&RC1==0&&RC2==0&&RC3==0)
	{
	PORTB=0x55;
	}
if(RC1==1&&RC0==0&&RC2==0&&RC3==0)
	{
	PORTB=0xAA;
	}
if(RC0==1 && RC2 ==1&&RC1==0&&RC3==0)
{
PORTB=0x44;
}
if(RC0==1 && RC3==1&&RC1==0&&RC2==0)
{
PORTB=0x11;
}
if(RC1==1 && RC3==1&&RC0==0&&RC2==0)
{
PORTB=0x22;
}
if(RC1==1 && RC2==1&&RC0==0&&RC3==0)
{
PORTB=0x88;
}
}
else
{
init();
}
}
}