#include<pic.h>
void init()
{
ADCON0=0X51;
ADCON1=0X40;//01000000
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
	int temp=0,adc;
	init();
	cmd(0x0c);//lcd display on cursor off blink off
	while(1)//infinity loop
	{
		char ch[4];
		int i;
		ADGO=1;//convertion to digital
		while(ADIF==0);//status of convr ADIF=0 convr= on process ADIF=1 conv. completed.
		adc=(ADRESL>>6)|(ADRESH<<2);//125 adc=125
		if(temp!=adc)//temp=125 != 125
			{
				temp=adc;//temp=125
		cmd(0x01);
		if(adc==0)
		{
			data('0');
		}	
		
		for(i=0;adc>0;i++)
		{
			ch[i]=(adc%10)+0x30;//adc number is extracted and  convert to char. 
			adc=adc/10;//adc
		}
		for(i--;i>=0;i--)
			data(ch[i]);
		}
		for(i=0;i<=5000;i++);	
	} 
}	