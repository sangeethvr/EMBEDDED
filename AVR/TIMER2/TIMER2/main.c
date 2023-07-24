#include <avr/io.h>

void tmr();

int main(void)
{
	DDRB = 0xFF;
	TCCR2 = 0X07;
	
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
	
	
	while((TIFR&(1<<TOV2))==0);
	TIFR = (1<<TOV2);
	TCNT2=0XB2;
}