#include<pic.h>
void init(void)
{
OPTION=0xc7;
TRISB=0x00;
PORTB=0x00;
}
void main()
{
init();
while(1)
{
PORTB=0x00;
TMR0IF=0;
while(TMR0IF==0);
PORTB=0xff;
TMR0IF=0;
while(TMR0IF==0);
}
}