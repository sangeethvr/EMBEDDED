#include<pic.h>
int m1=0,m2=0;

void init(void)
	{
	TRISB=0x30;
	PORTB=0x00;
	}
void motor(void)
	{
	if(RB4==1)
		{
		while(RB4==1);
		if(m1%3==0)
			{
			RB0=1;
			RB1=0;
			}
		else if(m1%3==1)
			{
			RB0=0;
			RB1=1;
			}
		else
			{
			RB0=0;
			RB1=0;
			}
		m1++;
		}
	}

void motor1(void)
	{
	if(RB5==1)
		{
		while(RB5==1);
		if(m2%3==0)
			{
			RB2=1;
			RB3=0;
			}
		else if(m2%3==1)
			{
			RB2=0;
			RB3=1;
			}
		else
			{
			RB2=0;
			RB3=0;
			}
		m2++;
		}
	}

void main()
	{

	init();
	while(1)
		{
		motor();
		motor1();
		}
	}