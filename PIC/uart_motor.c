#include <pic.h>
void init(void)
{
TRISC=0xb0;//
PORTC=0X00;
TXSTA=0X20;//8 low,async,8bit,txen
RCSTA=0X80;//enabled serial port
SPBRG=25; //set baud
TRISD=0x00;
PORTD=0x00;
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
while(1)
{
if(RC4==1)
{
while(RC4==1){}
RD0=1;
RD1=0;
trans('c');
}
else if(RC5==1)
{
while(RC5==1){}
RD0=0;
RD1=1;
trans('a');
}
}
}