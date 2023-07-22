#include<pic.h>
void init(void);
void delay(int);
void onled(void);
void  offled(void);

void main(void)
{
init();
while(1)
{
onled();
offled();
}
}

void init(void)
{
TRISB=0x00;
TRISD=0x00;
TRISC=0x00;
PORTB=0X00;
PORTC=0X00;
PORTD=0X00;
}

void delay(int a)
{
int i=0;
for(i=0;i<=a;i++)
{
}
}

void onled(void)
{
PORTB=0xff;
PORTD=0xff;
PORTC=0xff;
delay(5000);
}

void offled(void)
{
PORTB=0x00;
PORTD=0x00;
PORTC=0x00;
delay(5000);
}