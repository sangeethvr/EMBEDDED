#include<pic.h>

void main()
{
	TRISC=0x18;
	PORTC=0x00;
	SSPADD=2;
	SSPCON=0x28;
	SSPSTAT=0x00;
	SEN=1;
	while(SEN==1);
	SSPBUF=0xd0;
	SSPIF=0;
	while(SSPIF==0);
	
	SSPBUF=0x01;
	SSPIF=0;
	while(SSPIF==0);
	
	SSPBUF=0x00;
	SSPIF=0;
	while(SSPIF==0);
	
		SSPBUF=0x00;
	SSPIF=0;
	while(SSPIF==0);
	PEN=1;
	while(PEN==1);
	while(1)
	{
	}
}	