#include<pic.h>
void delay(int);
void init()
{
TRISB=0x00;
PORTB=0X00;
TRISC=0x00;
PORTC=0x00;
}
void main()
{
init();
while(1)
{
PORTB=0X0C;
PORTC=0X01;
delay(15000);
PORTB=0X12;
PORTC=0X01;
delay(5000);
PORTB=0X21;
PORTC=0X01;
delay(15000);
PORTB=0X11;
PORTC=0X02;
delay(5000);
PORTB=0X09;
PORTC=0X04;
delay(15000);
PORTB=0X0A;
PORTC=0X02;
delay(5000);
}
}

void delay(int a)
{int i;
for(i=0;i<=a;i++)
{}
}