#include<pic.h>
void init(void)
{
T1CON=0x31;
TRISB=0x00;
PORTB=0x00;
}
void main()
{
init();
while(1)
{
PORTB=0x00;
TMR1IF=0;
while(TMR1IF==0);
PORTB=0xff;
TMR1IF=0;
while(TMR1IF==0);
}
}