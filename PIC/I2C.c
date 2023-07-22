#include<pic.h>

void main()
{
	TRISC=0x18;
	PORTC=0x00;
	SSPADD=2;
	SSPCON=0x28;
	SSPSTAT=0x00;
	SEN=1;   //Start condition
	while(SEN==1);//waiting to end start condition
	
	SSPBUF=0xd0;
	SSPIF=0;
	while (SSPIF==0);
	
	SSPBUF=0x00;
	SSPIF=0;
	while(SSPIF==0);
	
	SSPBUF=0x05;
	SSPIF=0;
	while(SSPIF==0);
	
		SSPBUF=0x10;
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x51;
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x01;
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x02;
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x08;
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x20;
	SSPIF=0;
	while(SSPIF==0);
	PEN=1;
	while(PEN==1);
	while(1)
	{
	}
}	