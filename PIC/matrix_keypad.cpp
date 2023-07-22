#include<pic.h>
void data(char a)
{
	int i;
	RC0=1;
	PORTD=a;
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
}
void cmd(char a)
{
	int i;
	RC0=0;
	PORTD=a;
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
}
void main()
{
	int i=0;
	TRISB=0xf0;
	PORTB=0x00;
	TRISC=0x00;
	PORTC=0x00;
	TRISD=0x00;
	PORTD=0x00;
	cmd(0x01);
	cmd(0x0f);
	cmd(0x06);
	while(1)
	{
		PORTB=0x0e;
		if(RB4==0)
		{
			while(RB4==0);
			data('0');
		}
		else if(RB5==0)
		{
			while(RB5==0);
			data('1');
		}
		else if(RB6==0)
		{
			while(RB6==0);
			data('2');
		}
		else if(RB7==0)
		{
			while(RB7==0);
			data('3');
		}
		PORTB=0x0d;
		if(RB4==0)
		{
			while(RB4==0);
			data('4');
		}
		else if(RB5==0)
		{
			while(RB5==0);
			data('5');
		}
		else if(RB6==0)
		{
			while(RB6==0);
			data('6');
		}
		else if(RB7==0)
		{
			while(RB7==0);
			data('7');
		}
		PORTB=0x0B;
		if(RB4==0)
		{
			while(RB4==0);
			data('8');
		}
		else if(RB5==0)
		{
			while(RB5==0);
			data('9');
		}
		else if(RB6==0)
		{
			while(RB6==0);
			data('A');
		}
		else if(RB7==0)
		{
			while(RB7==0);
			data('B');
		}
		PORTB=0x07;
		if(RB4==0)
		{
			while(RB4==0);
			data('C');
		}
		else if(RB5==0)
		{
			while(RB5==0);
			data('D');
		}
		else if(RB6==0)
		{
			while(RB6==0);
			data('E');
		}
		else if(RB7==0)
		{
			while(RB7==0);
			data('F');
		}
		
	}

}