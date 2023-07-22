#include<lpc213x.h>
void main()
{
PINSEL0=1|1<<2;
U0LCR=0x83;
U0DLL=98;
U0DLM=0;
U0FDR=1<<4;
U0FCR=6;
U0FCR=1;
U0LCR=0x03;
while(1)
{
char a;
while(!(U0LSR&(1)));
a=U0RBR;
while(!(U0LSR&(1<<5)));
U0THR=a;

}
}
