#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void tmr();

int main(void)
{
	DDRB|= (1<<PB3);
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<CS02)|(1<<CS00)|(1<<COM01);
	
	while(1)
	{
		int i;
		for(i=0;i<255;i++)
		{
			OCR0=i;
			_delay_ms(20);
		}
		for(i=255;i>1;i--)
		{
			OCR0=i;
			_delay_ms(20);
		}
		
	}
}

