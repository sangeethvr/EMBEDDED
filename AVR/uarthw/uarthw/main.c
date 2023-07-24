#define F_CPU 8000000UL
#include <avr/io.h>
void txr(char b);
char rxr();
char a;
int x;

int main(void)
{
	DDRD=0X02;
	UCSRA=0X00;
	UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=51;
	while (1)
	{
		a=rxr();
		txr(a);
	
		
		
	}
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
	while((UCSRA=0X40)==0);
	UCSRA=0X40;
}
