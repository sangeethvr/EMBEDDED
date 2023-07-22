#include<pic.h>
void main()
{
int i;
TRISB=0x00;

while(1)
{
PORTB=0x01;
for(i=0;i<=10000;i++)
{}
PORTB=0x03;
for(i=0;i<=10000;i++)
{}
PORTB=0x07;
for(i=0;i<=10000;i++)
{}
PORTB=0x0f;
for(i=0;i<=10000;i++)
{}
PORTB=0x1f;
for(i=0;i<=10000;i++)
{}
PORTB=0x3f;
for(i=0;i<=10000;i++)
{}
PORTB=0x7f;
for(i=0;i<=10000;i++)
{}
PORTB=0xff;
for(i=0;i<=10000;i++)
{}


}

}