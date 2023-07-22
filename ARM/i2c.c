#include <lpc213x.h>
void main()
{
	long i;
	PINSEL0=(1<<4|1<<6);
	I2C0CONCLR=0xff;
	I2C0CONSET=1<<6;
	I2C0SCLL=75;	
	I2C0SCLH=75;
	
	I2C0CONSET=1<<5;
	 while(!(I2C0CONSET&(1<<3)))  ;
	 I2C0DAT=0xD0;
	 I2C0CONCLR=1<<5|1<<3;
	 
	 while(!(I2C0CONSET&(1<<3)))  ;
	 I2C0DAT=1;
	 I2C0CONCLR=1<<3;
	 while(!(I2C0CONSET&(1<<3)))  ;
	 I2C0DAT=0x20;
	 I2C0CONCLR=1<<3;
	 while(!(I2C0CONSET&(1<<3)))  ;
	 I2C0CONCLR=1<<3;
		I2C0CONSET=1<<4;
	while(1)
	{
	I2C0CONSET=1<<5;
	 while(!(I2C0CONSET&(1<<3)))  ;	 //start
	 I2C0DAT=0xD1;
	 I2C0CONCLR=1<<5|1<<3;
	 while(!(I2C0CONSET&(1<<3)))  ;			//slave+ read
	 I2C0CONCLR=1<<3;
	 while(!(I2C0CONSET&(1<<3)))  ;						 //rec data
	 I2C0DAT;
	I2C0CONCLR=1<<3;
		I2C0CONSET=1<<4;
		
	}
}
