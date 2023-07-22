#include<pic.h>
char pass[]="1234",inp[4];
int v=0;
void trans(char a)
{
		while(TXIF==0);
		TXREG=a;
		while(RB4==0||RB5==0||RB6==0||RB7==0);
		if(v<=3)
		{
			inp[v]=a;
		}	
		v++;
}	
void display(const char *p)
{
	while(*p)
	{
		trans(*p++);
		v=0;
	}
}		
void main()
{
	int i;
TRISB=0xf0;
TRISC=0x00;
PORTB=0x00;
RBPU=0;
TXSTA=0x20;
RCSTA=0x80;
SPBRG=25;
start:
display("Enter Password");
trans(0x0d);
v=0;

while(1)
{
	PORTB=0x0e;	
	switch(PORTB&0xf0)
	{
		case 0xe0:
		trans('7');
		break;
		case 0xD0:
		trans('8');
		break;
		case 0xB0:
		trans('9');
		break;
		case 0x70:
		trans(' ');
		break;
	}	
		PORTB=0x0D;	
	switch(PORTB&0xf0)
	{
		case 0xe0:
		trans('4');
		break;
		case 0xD0:
		trans('5');
		break;
		case 0xB0:
		trans('6');
		break;
		case 0x70:
		trans(' ');
		break;
	}
		PORTB=0x0b;	
	switch(PORTB&0xf0)
	{
		case 0xe0:
		trans('1');
		break;
		case 0xD0:
		trans('2');
		break;
		case 0xB0:
		trans('3');
		break;
		case 0x70:
		trans(' ');
		break;
	}	
		PORTB=0x07;	
	switch(PORTB&0xf0)
	{
		int flag=0;	
		case 0xe0:
		trans(0x0d);
		break;
		case 0xD0:
		trans('0');
		break;
		case 0xB0:
		trans(0x08);
		v-=2;
		break;
		case 0x70:
		for(i=0;i<=3;i++)
		{
			if(inp[i]==pass[i])
			{
				flag++;
			}
		}	
		if(flag==4&&v==4)
		{
			display("Correct");
			trans(0x0d);
		}	
		else
		{
			display("Wrong");
			trans(0x0d);
		}	
		goto start;
		break;
	}		
		
}
}