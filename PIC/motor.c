#include<pic.h>
int j=0;

void init(void)
	{
	TRISB=0x04;
	PORTB=0x00;
	}
void motor(void)
	{
	if(RB2==1)
		{
		while(RB2==1);
		if(j%3==0)
			{
			RB0=1;
			RB1=0;
			}
		else if(j%3==1)
			{
			RB0=0;
			RB1=1;
			}
		else
			{
			RB0=0;
			RB1=0;
			}
		j++;
		}
	}

void main()
	{

	init();
	while(1)
		{
		motor();
		}
	}