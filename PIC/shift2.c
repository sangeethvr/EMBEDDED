#include<pic.h>
void main()
{
int i;
TRISB=0x00;

while(1)
{
int j;
for(j=8;j>=0;j=j-1)
{
PORTB=0xff>>j;
for(i=0;i<=10000;i++)
{}
}
for(j=1;j<=7;j=j+1)
{
PORTB=0xff>>j;
for(i=0;i<=10000;i++)
{}
}

}

}