#include<pic.h>
int c=0;
void cmd(char a)
{
	int i;
	RC0=0;
	PORTD=a;
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
		while(RB4==0||RB5==0||RB6==0||RB7==0);
}
void data(char a)
{
	int i;
	RC0=1;
	PORTD=a;
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
	c++;
	if(c==16)
	{
		cmd(0xc0);
	}	
	while(RB4==0||RB5==0||RB6==0||RB7==0);
}

void main()
{
	int i=0,on=0;
	RBPU=0;
	TRISB=0xf0;
	PORTB=0x00;
	TRISC=0x00;
	PORTC=0x00;
	TRISD=0x00;
	PORTD=0x00;
	cmd(0x01);
	cmd(0x0f);
	cmd(0x06);
	cmd(0x38);
	while(1)
	{
		PORTB=0x0e;
		switch(PORTB&0xf0)
		{	
			case 0xe0:
			data('7');
			break;
			case 0xd0:
			data('8');
			break;
			case 0xB0:
			data('9');
			break;
		}
	
		PORTB=0x0D;
		switch(PORTB&0xf0)
		{	
			case 0xe0:
			data('4');
			break;
			case 0xd0:
			data('5');
			break;
			case 0xB0:
			data('6');
			break;
		}
		PORTB=0x0B;
		switch(PORTB&0xf0)
		{	
			case 0xe0:
			data('7');
			break;
			case 0xd0:
			data('8');
			break;
			case 0xB0:
			data('9');
			break;
		}
		else if(RB7==0)
		{
		
			if(c!=0)
			{
			cmd(0x10);//real c=20  c=21 
			data(' ');//' ' real c=21 c=22 
			cmd(0x10);//realc= 20 c=22
			c=c-2;
			if (c==15)
			{
			cmd(0x90);
			}
			}
		}
		PORTB=0x07;
		if(RB4==0)
		{
		
			if(on%2==0)
			{
				cmd(0x0f);
			}
			else
			{
				cmd(0x08);
			}
			on++;	
		}
		else if(RB5==0)
		{
		
			data('0');
		}
		else if(RB6==0)
		{
		
			data('E');
		}
		else if(RB7==0)
		{
		
			cmd(0x01);
			c=0;
		}
		
		
	}

}