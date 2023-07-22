#include<pic.h>
void init(void)
{
	TRISC=0x80;
	PORTC=0x00;
	TRISB=0x00;
	PORTB=0x00;
	TXSTA=0x20;
	RCSTA=0x90;
	SPBRG=25;
	RCIE=1;
	PEIE=1;
	GIE=1;
	
}

void trans(char a)
{
	while(TXIF==0);
	TXREG=a;
}	

void main()
{
	init();
	while(1)
	{
		int i;
		PORTB=~PORTB;
		for(i=0;i<=20000;i++);
	}	
}
void interrupt uart(void)
{
	char a;
		a=RCREG;
		trans(a);
		RCIF=0;
}		