#include<pic.h>
void init()
{
ADCON1=0XC0;//11000000 to configure speed result storing method digital/analog
TRISB=0X00;//direction output
PORTB=0X00;//0v o/p
TRISC=0X00;//output
PORTC=0X00;//portc 0v o/p
TXSTA=0x20;
RCSTA=0x80;
SPBRG=25;
}
void trans(char a)
{
	while(TXIF==0);
	TXREG=a;
}
void main()
{
	int temp=0,adc,adc2,temp2=0;
	init();
	while(1)
	{
		int i;
		char ch[4];
		ADCON0=0x51;
		for(i=0;i<=1000;i++);
		ADGO=1;
		while(ADIF==0);
		ADIF=0;
		adc=(ADRESL)|(ADRESH<<8);
		if(adc==0)
		{
			trans('0');	
		}	
		
		for(i=0;adc>0;i++)
		{
			ch[i]=(adc%10)+0x30;
			adc=adc/10;
		}	
		for(i--;i>=0;i--)
			trans(ch[i]);
		trans(0x0d);
		
	}
}		
		