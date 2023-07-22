#include<pic.h>
void init()
{
ADCON1=0Xc0;//11000000 to configure speed result storing method digital/analog
TRISB=0X00;//direction output
PORTB=0X00;//0v o/p
TRISC=0X00;//output
PORTC=0X0;//portc 0v o/p
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
void display(const char *p)
{
	while(*p)
	{
		data(*p);
		p++;
	}	

}
void main ()
{
	int temp=0,adc,adc2,temp2=0;
	init();
	cmd(0x0c);//lcd display on cursor off blink off
	cmd(0x38);//enable 2nd line.
	while(1)//infinity loop
	{
		char ch[4];//char ch[4]     4 ch[0],ch[1],ch[2],ch[3]
		int i;

		ADCON0=0X51;//channel An2
		for(i=0;i<=5000;i++);	
		ADGO=1;//convertion to digital
		while(ADIF==0);//status of convr ADIF=0 convr= on process ADIF=1 conv. completed.
		ADIF=0;
		adc=(ADRESL)|(ADRESH<<8);//125 adc=125 right jjustified
		if(temp!=adc)//temp=125 != 125
			{
				temp=adc;//temp=125
		cmd(0x80);
		display("ADC1 =");
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
		display("     ");
		}
		for(i=0;i<=5000;i++);	
		ADCON0=0X59;//channel An3 
		for(i=0;i<=5000;i++);	//wait time;
		ADGO=1;//convertion to digital
		while(ADIF==0);//status of convr ADIF=0 convr= on process ADIF=1 conv. completed.
		ADIF=0;
		adc2=(ADRESL)|(ADRESH<<8);//125 adc=125
		if(temp2!=adc2)//temp=125 != 125
			{
				temp2=adc2;//temp=125
		cmd(0xc0);
		display("ADC2 =");
		if(adc2==0)
		{
			data('0');
		}	
		
		for(i=0;adc2>0;i++)
		{
			ch[i]=(adc2%10)+0x30;//adc number is extracted and  convert to char. 
			adc2=adc2/10;//adc
		}
		for(i--;i>=0;i--)
			data(ch[i]);
		display("      ");
		}
	
		for(i=0;i<=5000;i++);	
	} 
}	