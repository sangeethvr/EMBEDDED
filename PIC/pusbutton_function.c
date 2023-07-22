#include<pic.h>
void init(void);
int sw(int);

void main()
{
int c=0;
init();
while(1)
{
c=sw(c);
}
}

void init(void)
{
TRISC=0x20;
PORTC=0x00;
TRISB=0x00;
PORTB=0x00;
}

int sw(int d)
{
if(RC5==1)
{
while(RC5==1)
{
}
if(d%2==0)
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
d++;
}
return d;
}