#include<pic.h>
void init(void)
{
T2CON=0x7e;
TRISB=0x00;
PORTB=0x00;
}
void main()
{
init();
while(1)
{
PORTB=0x00;
TMR2IF=0;
while(TMR2IF==0);
PORTB=0xff;
TMR2IF=0;
while(TMR2IF==0);
}
}