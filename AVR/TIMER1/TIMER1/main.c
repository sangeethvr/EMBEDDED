#include <avr/io.h>

void tmr();

int main(void)
{
	DDRB = 0xFF;
	TCCR1A = 0X00;
	TCCR1B =0X05;
	TCNT1H=0X00;
	TCNT1L=0X00;
	while(1)
	{
		PORTB=0x55;
		tmr();
		PORTB=0xAA;
		tmr();
	}
}

void tmr()
{
	
	
	while((TIFR&(1<<TOV1))==0);
	TIFR = (1<<TOV1);
	TCNT1H=0XFF;
	TCNT1L=0XB1;
}