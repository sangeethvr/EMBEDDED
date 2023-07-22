#include<pic.h>
void init(void)
{
	TRISC=0x00;
	PORTC=0x00;
	TRISD=0x00;
	PORTD=0x00;
}
void main()
{
	int i,j;
	init();
	RC0=0;
	RC1=0;
	PORTD=0x0f;
	RC2=1;
	for(i=0;i<=1000;i++);
	RC2=0;

	RC0=1;
	RC1=0;
	PORTD=a;
	RC2	=1;
	for(i=0;i<=1000;i++);
	RC2=0;
	while(1)
	{	
	}
}