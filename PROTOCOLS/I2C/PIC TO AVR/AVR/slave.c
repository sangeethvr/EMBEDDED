/*
 * main.c
 *
 * Created: 7/18/2022 7:48:18 PM
 *  Author: anoop
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void i2c_init();
char i2c_statusw();
char i2c_statusr();
void trans(char b)
{

	while((UCSRA&0X20)==0);
	UCSRA=0X20;
	UDR=b;

}
int main(void)
{

	DDRA=DDRB=0xff;
	DDRD=0X02;
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=0X33;
	UBRRH=0X00;
	i2c_init();
	char v=i2c_statusr();
	trans(v);
	char w=i2c_statusr();
	trans(w);
	while(1)
	{


	}
}

void i2c_init()
{
	DDRC=0;//1111 1111
	TWAR=0xd0;//  02 0   0110 1000 0x61
	TWCR=0x44;//ack
	TWCR|=0x80;// TWCR=TWCR|0x80
	while((TWCR&(0x80))==0);//slave

}

char i2c_statusr()
{
	TWCR=0x44;//
	TWCR|=0x80;
	while((TWCR&(0x80))==0);//slave ad+W
	return TWDR;
	//1 clear flag bit lpc2138/avr 0 1
}
