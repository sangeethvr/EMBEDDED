#include<pic.h>
void main()
{
	int i;
	INTE=1;
	GIE=1;
	INTEDG=0;
	TRISB=0x01;
	PORTB=0x00;
	TRISC=0x00;
	PORTC=0x00;//PORTC=0x00
	while(1)
	{
		PORTC=~PORTC;//PORTC=~PORTC;
		for(i=0;i<=10000;i++);
		
	}
}
void interrupt external(void)
{
	PORTB=~PORTB;
	INTF=0;
}