
#include <avr/io.h>
#include <util/delay.h>
int i;
int main(void)
{
    DDRB=0XFF;
	DDRA=0XFF;
    while (1) 
    {
		
		PORTB=0X80;
		_delay_ms(200);
		for(i=0;i<8;i++)
		{
			PORTB=PORTB>>1;
			_delay_ms(200);
		}
		
		PORTA=0X80;
		_delay_ms(200);
		for(i=0;i<8;i++)
		{
			PORTA=PORTA>>1;
			_delay_ms(200);
		}
		
		
    }
}


