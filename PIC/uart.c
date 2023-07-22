#include <pic.h>
void init(void)
{
TRISC=0x80;//
PORTC=0X00;
TRISD=0x00;
PORTD=0x00;
TXSTA=0X20;//8 low,async,8bit,txen
RCSTA=0X80;//enabled serial port
SPBRG=25; //set baud
}
void delay(void)
{
int i;
for(i=0;i<=10000;i++)
{}
}
void trans(char c)
{
while(TXIF==0)
{}
TXREG=c;
}
void main()
{
init();
trans(0x61);
trans('s');
trans('c');
trans('i');
trans('i');
while(1)
{

delay();
}
}