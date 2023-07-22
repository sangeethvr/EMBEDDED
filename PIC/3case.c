#include<pic.h>
void main()
{
int sw2=0,i;
TRISB=0x00;
PORTB=0X00;
TRISD=0X42;
PORTD=0X00;
TRISC=0x00;
PORTC=0x00;
while(1)
{

	if(RD6==1)
		{
		while(RD6==1)
			{
			}
		sw2++;
		}
	if(sw2%4==0)
			{
			PORTC=0x00;
			}
		else if (sw2%4==1)
			{
			PORTC=0xff;
			}
		else if(sw2%4==2)
			{
			PORTC=0xff;
			for(i=0;i<=5000;i++)
			{}
			PORTC=0x00;
			for(i=0;i<=5000;i++)
			{}
			}
		else
			{
			PORTC=0x55;
			for(i=0;i<=5000;i++)
			{}
			PORTC=0xAA;
			for(i=0;i<=5000;i++)
			{}
			}
}
}


