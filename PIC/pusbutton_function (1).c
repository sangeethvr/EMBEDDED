#include<pic.h>
void init(void);
void sw(void);
int c=0;
void main()
{

init();
while(1)
{
sw();
}
}

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
while(RC5==1)
{}
if(c%2==0)
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
c++;
}

}