#include<lpc213x.h>
void main()
{

long i=0,flag=-1;
PINSEL0=1<<7;
IO0DIR=~0;
T0TCR=2;
T0TCR=1;
T0CTCR=0;
T0PR=14930; 
T0TC=0;	   
T0PC=0;
T0MCR=1<<1;
T0MR0=3000;
T0EMR=1|1<<4;
while(1)
{

}
}

