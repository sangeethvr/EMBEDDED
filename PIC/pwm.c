#include<pic.h>
void main()
{
TRISC=0x00;
PORTC=0x00;
CCP1CON=0x1C;
CCPR1L=0x38;
T2CON=0x07;
PR2=255;
while(1)
{
}
}