#include <lpc213x.h>
void main()
{					   
long i;
IO0DIR|=1;
IO0SET|=1;
	PINSEL0=1<<8|1<<10|1<<12 ;
	S0SPCCR=8;
	S0SPCR=1<<3|1<<4|1<<5|1<<11;
	IO0CLR|=1;
			S0SPDR=0X3f;
			while(!(S0SPSR&(1<<7)));
			S0SPDR=0X15;
			while(!(S0SPSR&(1<<7)));
			S0SPDR=0X15;
			while(!(S0SPSR&(1<<7)));
			S0SPDR=0X15;
			while(!(S0SPSR&(1<<7)));
		  IO0SET|=1;
	while(1)
	{
		 IO0CLR|=1;
			S0SPDR=0XBf;
			while(!(S0SPSR&(1<<7)));
			S0SPDR=0X00;
			while(!(S0SPSR&(1<<7)));
			S0SPDR;
			S0SPDR=0x00;
			while(!(S0SPSR&(1<<7)));
			S0SPDR;
		  IO0SET|=1;
		  for(i=0;i<=10000000;i++);
	}
	}