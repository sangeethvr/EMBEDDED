#include<pic.h>

void init(void)
{
TRISC=0x20;
PORTC=0x00;
TRISB=0x00;
PORTB=0x00;
}

void sw(void)
{
if(RC5==1)
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
}

void main()
{
init();
while(1)
{
sw();
}
}

