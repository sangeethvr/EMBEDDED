#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void data(char a);
void cmd(char a);
void txr(char b);
char rxr();
char a;
int x;

int main(void)
{
	DDRD=0XF2;
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=51;
	
	DDRA=0X00;
	DDRC=0XFF;
	
	ADCSRA=0X80;
	ADMUX=0X40;
	cmd(0X01);
	cmd(0X0E);
	cmd(0X06);
	cmd(0X38);
	cmd(0X80);
	while (1)
	{
		
		ADCSRA=0XC0;
		while ((ADCSRA & 0X40)==0X40);
		int a=ADCL;
		a+=ADCH<<8;
		
		int b=(a/1000);
		data(b+48);
		txr(b+48);
		
		int c=(a%1000)/100;
		data(c+48);
		txr(c+48);
	
		int d=(a%100)/10;
		data(d+48);
		txr(d+48);
		
		int e=(a%10);
		data(e+48);
		txr(e+48);
		txr('\r');
		cmd(0X01);
		_delay_ms(100);
		
	}
}

void data(char a)
{
	PORTC=a;
	PORTD=0XC0;
	_delay_ms(100);
	PORTD=0X40;
		
}
void cmd(char a)
{
	PORTC=a;
	PORTD=0X80;
	_delay_ms(100);
	PORTD=0X00;
}
char rxr()
{
	while ((UCSRA&0X80)==0);
	UCSRA=0X80;
	return(UDR);
}
void txr(char b)
{
	UDR=b;
	while((UCSRA&0X40)==0);
	UCSRA=0X40;
}
