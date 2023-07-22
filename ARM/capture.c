#include<lpc213x.h>
void main()
{

long i=0,flag=-1;
PINSEL0=1<<5;
IO0DIR=~0;
T0TCR=2;
T0TCR=1;
T0CTCR=0;
T0PR=14930; 
T0TC=0;	   
T0PC=0;
T0CCR=1;
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
