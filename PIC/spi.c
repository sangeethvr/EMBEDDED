#include<pic.h>
void init(void)
{
	TRISC=0x10;//
	PORTC=0x40;
	SSPCON=0x30;
	SSPSTAT=0x00;
}
void main()
{
	init();
	RC6=0;
	SSPBUF=0x03;
	SSPIF=0;
	while(SSPIF==0);
	SSPBUF=0x30;
	SSPIF=0;
	while(SSPIF==0);
	RC6=1;
	while(1)
	{
	
	}
}	