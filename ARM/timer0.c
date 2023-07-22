#include<lpc213x.h>
void main()
{
long i=0,flag=-1;
IO0DIR=~0;
T0TCR=2;
T0TCR=1;
T0CTCR=0;
T0PR=14999999;
T0TC=0;
T0PC=0;
while(1)
{
if(T0TC!=flag)//0 !=0
{
flag=T0TC;//flag=0
i++;//1
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
