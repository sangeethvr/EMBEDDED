#include<lpc213x.h>

void adc(void)__irq
{
char a=U0RBR;
while((U0LSR&(1<<5))==0);
U0THR=a;
}
void main()
{
long i,flag;
PINSEL0=1|1<<2;
PINSEL1=0;
U0LCR=0x83;
U0DLL=98;
U0DLM=0;
U0FDR=1<<4;
U0FCR=6;
U0FCR=1;
U0LCR=0x03;
U0IER=1;
VICIntSelect=0;
VICIntEnable=1<<6;
VICVectCntl0=6|1<<5;
VICVectAddr0=(unsigned long)adc;
	while(1)
{
	
}
}
