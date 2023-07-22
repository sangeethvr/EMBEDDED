#include<pic.h>
int c;
void data(char a)
{
	int i;
	RC0=1;
	RC1=0;
	PORTB=a;
	RC2=1;
	for(i=0;i<=1000;i++);
	RC2=0;
	c++;
}
void cmd(char a)
{
	int i;
	RC0=0;
	RC1=0;
	PORTB=a;
	RC2=1;
	for(i=0;i<=1000;i++);
	RC2=0;
}
 char rxn(void)
{
	 while(RCIF==0);
	 return RCREG;
} 
void main()
{
	TRISB=0x00;
	TRISC=0x80;
	PORTB=0x00;
	PORTC=0x00;
	TXSTA=0x20;
	RCSTA=0x90;
	SPBRG=25;
	cmd(0x0f);
	cmd(0x06);
	cmd(0x01);
	cmd(0x38);
	while(1)
	{
		char a=rxn();
		switch(a)
		{
			case 8:
			//c=16
			if(c>0 && c<31)
			{
				//c=16
				if(c==16)
			{
				cmd(0x90);
			}	
			cmd(0x10);
			data(' ');
			cmd(0x10);
			c=c-2;
			
			}
			break;
			case 13:
			cmd(0xc0);
			c=16;
			break;
			default:
			data(a);
			break;
		}
		if(c==16)
		{
			cmd(0xc0);
		}
		if(c==31)
		{
			cmd(0x80);
			c=0;
		}		
			
		
		
	}	
}