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
	
	SSPBUF=0xd0;//slave ad
	SSPIF=0;
	while (SSPIF==0);
	
	SSPBUF=0x00;//Sec
	SSPIF=0;
	while(SSPIF==0);
	
	SSPBUF=0x05;//data to sec
	SSPIF=0;
	while(SSPIF==0);
	
		SSPBUF=0x10;//data to min 01
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x51;//data to hour 02
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x01;//data to day 03
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x02;//data to date 04
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x08;//data to mnth 05
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x20;//data to year 06
	SSPIF=0;
	while(SSPIF==0);
	PEN=1;
	while(PEN==1);
	while(1)
	{
		SEN=1;
		while(SEN==1);
		SSPBUF=0xd1;
		SSPIF=0;
		while(SSPIF==0);
		RCEN=1;
		while(RCEN==1);
		ACKDT=0;
		ACKEN=1;
		while(ACKEN==1);
		RCEN=1;
		while(RCEN==1);
		ACKDT=1;
		ACKEN=1;
		while(ACKEN==1);
		PEN=1;
		while(PEN==1);

	}
}	