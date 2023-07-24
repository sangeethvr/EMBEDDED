#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRA=0XFF;
	DDRB=0X00;
	PORTB=0XFF;
    while (1) 
    {
		int i;
		
		if ((PINB & 0X01 )==0)
		{
			PORTA=0X80;
			_delay_ms(200);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA>>1;
				_delay_ms(200);
			}
		}
		
		if((PINB & 0X02)==0)
		{
			PORTA=0X01;
			_delay_ms(200);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA<<1;
				_delay_ms(200);
			}
		}
		if((PINB & 0X04)==0)
		{
			PORTA=0X80;
			_delay_ms(100);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA>>1;
				_delay_ms(100);
			}
			PORTA=0X01;
			_delay_ms(100);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA<<1;
				_delay_ms(100);
			}
		}
		
		if((PINB & 0X08)==0)
		{
			PORTA=0XC0;
			_delay_ms(100);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA>>1;
				_delay_ms(100);
			}
			PORTA=0X03;
			_delay_ms(100);
			for(i=0;i<8;i++)
			{
				PORTA=PORTA<<1;
				_delay_ms(100);
			}
		}
			
    }
}

