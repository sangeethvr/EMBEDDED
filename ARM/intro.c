#include<lpc214x.h>
void main()
{
long i;
PINSEL0=0;	 //PISEL0= pin usage selct 
PINSEL1=0;
IO0DIR=~0;
IO1DIR=~0;													 
while(1)
	{

	IO0SET=0x5555
		IO1SET=IO0SET; //0XAAAAAA
	for(i=0;i<=200000;i++)
	{}

	IO0CLR=IO0SET;//0XAAAAAAA
		IO1CLR=IO1SET;		 //IO1SET 0XAAAA   
	for(i=0;i<=200000;i++)
	{}
	
	}
}

