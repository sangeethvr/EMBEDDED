#include <pic.h>
void init(void)
{
TRISC=0xb0;//
PORTC=0X00;
TXSTA=0X20;//8 low,async,8bit,txen
RCSTA=0X90;//enabled serial port
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
while(1)
{
char a;
while(RCIF==0)
{
}
a=RCREG;
while(TXIF==0)
{}
TXREG=a;
}
}