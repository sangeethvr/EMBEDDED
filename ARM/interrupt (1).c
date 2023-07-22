#include<lpc213x.h>
void isr()__irq
{
IO0PIN=~IO0PIN;
EXTINT=1<<0;
}
void main()
{
IO0DIR=~(1<<1);
PINSEL0=1<<2|1<<3;
VICIntSelect=~(1<<14);
VICIntEnClr=1<<14;
VICIntEnable=1<<14;
VICVectCntl0=1<<5|14;// bit no:only
VICVectAddr0=(unsigned int)isr;//address of interrupt fun 
EXTINT=1<<0;   //for ext0
EXTMODE=1<<0;// edge or level
EXTPOLAR=1<<0;//rising edge or falling
while(1);
}