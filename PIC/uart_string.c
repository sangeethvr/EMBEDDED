#include <pic.h>
void init(void)
{
TRISB=0X00;
PORTB=0X00;
TRISC=0x80;//
PORTC=0X00;
TXSTA=0X20;//8 low,async,8bit
RCSTA=0X80;//enabled serial port
SPBRG=25;
}
void trans(char a)
{
	while(TXIF==0);
	TXREG=a;
}
void display(const char *p)
{
	while(*p)
	{
		trans(*p);
		p++;
	}
}	
void main()
{
init();
display("Ascii");
while(1)
{

}
}
