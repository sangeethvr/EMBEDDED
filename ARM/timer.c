#include<lpc213x.h>
void main()
{
	IO0DIR=~0;
	T0TCR=2;			//COUNTER RESET 
	T0TCR=1;			 // COUNTER ENABLE
	T0CTCR=0;	  		// TIMER MODE EVERY PCLK EDGE RISING 
	T0PR=14999999;	  	// INCREMENT T0PC TO T0PR , TOTC++
	T0TC=0;	// incremented when the Prescale Counter (PC) reaches its maximum value held by Prescaler Register (PR).
	T0PC=0;
	while(1)
	{
		
			if(T0TC%2==0)
			{
				IO0SET=~0;
			}
			else
			{
				IO0CLR=~0;
			}
			
		}
	}


