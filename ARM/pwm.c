#include<lpc213x.h>
void main()
{

long i=0,flag=-1;
PINSEL0=1<<3;
IO0DIR=~0;
PWMMR0=150;
PWMMR3=300;
PWMTCR=2;
PWMTCR=1|1<<3;
PWMMCR=1<<10;
PWMPR=14930; 
PWMTC=0;	   
PWMPC=0;
PWMPCR=1<<11;
while(1)
{
if(T0TC!=flag)
{
flag=T0TC;
i++;
if(i%2==0)
{
IO0SET=~0;
}
else
{
IO0CLR=~0;
}
}
}
}
