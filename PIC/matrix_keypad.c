#include<pic.h>
void main()
{
	int i=0;
	TRISB=0xf0;
	PORTB=0x00;
	TRISC=0x00;
	PORTC=0x00;
	while(1)
	{
		PORTB=0x0e;
		if(RB4==0)
		{
			while(RB4==0);
			RC0=1;
		}
		else if(RB5==0)
		{
			while(RB5==0);
			RC1=1;
		}
		else if(RB6==0)
		{
			while(RB6==0);
			RC2=1;
		}
		else if(RB7==0)
		{
			while(RB7==0);
			RC3=1;
		}
		PORTB=0x0d;
		if(RB4==0)
		{
			while(RB4==0);
			RC4=1;
		}
		else if(RB5==0)
		{
			while(RB5==0);
			RC5=1;
		}
		else if(RB6==0)
		{
			while(RB6==0);
			RC6=1;
		}
		else if(RB7==0)
		{
			while(RB7==0);
			RC7=1;
		}
		PORTB=0x0B;
		if(RB4==0)
		{
			while(RB4==0);
			RC0=0;
		}
		else if(RB5==0)
		{
			while(RB5==0);
			RC1=0;
		}
		else if(RB6==0)
		{
			while(RB6==0);
			RC2=0;
		}
		else if(RB7==0)
		{
			while(RB7==0);
			RC3= 0;
		}
		PORTB=0x07;
		if(RB4==0)
		{
			while(RB4==0);
			RC4=0;
		}
		else if(RB5==0)
		{
			while(RB5==0);
			RC5=0;
		}
		else if(RB6==0)
		{
			while(RB6==0);
			RC6=0;
		}
		else if(RB7==0)
		{
			while(RB7==0);
			RC7= 0;
		}
		
	}

}