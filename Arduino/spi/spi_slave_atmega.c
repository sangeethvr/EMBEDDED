/*
 * spi_slave.c
 *
 * Created: 9/16/2020 11:56:32 AM
 * Author : Akshay
 */ 

#include <avr/io.h>


int main(void)
{
	DDRC=~0;
    DDRB=1<<6;
	SPCR=1<<SPE|1<<CPHA|1<<CPOL;
    while (1) 
    {
		while(!(SPSR & (1<<SPIF)));
		PORTC=SPDR;
		SPDR=0x20;
		SPSR=1<<SPIF;
    }
}

