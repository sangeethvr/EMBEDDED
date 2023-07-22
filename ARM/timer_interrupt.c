#include<lpc213x.h>
int i=0;
void timer0()__irq
{
i++;
if(i%2)
{
IO0SET=~0;
}
else
{
IO0CLR=~0;
}
 T0IR=1;

}
void main()
{
long i,flag;
PINSEL0=1<<7;
IO0DIR=~0;
T0TCR=2;
T0TCR=1;
T0CTCR=0;
T0PR=14913;
T0MCR=3;
T0MR0=15;
T0TC=0;
T0PC=0;
T0EMR=1|3<<4;
  VICIntSelect=0;
  VICIntEnable=1<<4;
  VICVectCntl0=4|1<<5;
  VICVectAddr0=(unsigned long)timer0;
	while(1)
{

}
}
