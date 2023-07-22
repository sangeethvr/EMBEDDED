#include<pic.h>
void init()
{
ADCON0=0X01;
ADCON1=0X0e;
TRISB=0X00;
PORTB=0X00;
TRISC=0X00;
PORTC=0X0;
}
void data(char a)
{
	int i;
	RB0=1;
	RB1=0;
	PORTC=a;
	RB2=1;
	for(i=0;i<=1000;i++);
	RB2=0;
}
void cmd(char a)
{
	int i;
	RB0=0;
	RB1=0;
	PORTC=a;
	RB2=1;
	for(i=0;i<=1000;i++);
	RB2=0;
}
void main ()
{
	init();
	cmd(0x0c);
	while(1)
	{
		char ch[3];
		int adc=0,i;
		ADGO=1;
		while(ADIF==0);
		adc=ADRESH;
		cmd(0x01);
		if(adc==0)
		{
			data('0');
		}	
		
		for(i=0;adc>0;i++)
		{
			ch[i]=(adc%10)+0x30;
			adc=adc/10;
		}
		for(i--;i>=0;i--)
			data(ch[i]);
			
	} 
}