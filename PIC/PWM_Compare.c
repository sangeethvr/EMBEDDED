#include<pic.h>
void main()
{
TRISC=0x00;
PORTC=0x00;

CCPR1L=0xf8;
CCPR1H=0xff;
TMR1L=0;
TMR1H=0;
T1CON=0X31;
while(1)
{
	CCP1CON=0x08;
while(CCP1IF==0);
CCP1IF=0;
CCP1CON=0X09;
while(CCP1IF==0);
CCP1IF=0;
}
}