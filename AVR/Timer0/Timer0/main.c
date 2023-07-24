#include <avr/io.h>

void tmr();

int main(void)
{
	DDRB = 0xFF;		
	TCCR0 = (1<<WGM01)|(1<<CS02)|(1<<CS00);
	OCR0=0X4F;
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
	  
			
	while((TIFR&(1<<TOV0))==0); 
	TIFR = (1<<TOV0);  	
}




