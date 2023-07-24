#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB=0XFF;
	DDRA=0XFF;
	DDRD=~(1<<DDD3);
	MCUCR=(1<<ISC11)|(1<<ISC10);
	GICR=(1<<INT1);
	sei();
	while(1)
	{
		PORTA=0x55;
		_delay_ms(100);
		PORTA=0xAA;
		_delay_ms(100);
		sei();
	}
	
}

INT1_vect()
{
	PORTB=~(PORTB);
}