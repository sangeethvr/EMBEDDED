#include<pic.h>
void init(void)
{
	ADIE=1;
	PEIE=1;
	GIE=1;
	ADCON0=0x01;
	ADCON1=0x80;
	TRISB=0x00;
	TRISC=0x00;
}
void data(char a)
{
	int i;
	RB0=1;
	PORTC=a;
	RB1=1;
	for(i=0;i<=1000;i++);
	RB1=0;
}
void cmd(char a)
{
	int i;
	RB0=0;
	PORTC=a;
	RB1=1;
	for(i=0;i<=1000;i++);
	RB1=0;
}
void main()
{
	int i;
	init();
	
	while(1)
	{
		for(i=0;i<=1000;i++);
		ADGO=1;	
	}	

}

void interrupt adc1()
{
	char ch[4];
		int adc,i;
	cmd(0x01);
	cmd(0x0c);
		adc=ADRESL|(ADRESH<<8);
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
		data(' ');
		data(' ');
		data(' ');
		ADIF=0;
}