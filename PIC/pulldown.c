#include<pic.h>
void main()
{
	int i=0;
	TRISB=0x01;
	PORTB=0x01;
	while(1)
	{
		if(RB0==0)
		{
			while(RB0==0);
			if(i%2)
			{
				PORTB=0xff;
			}
			else
			{
				PORTB=0x00;
			}		
			i++;
		}
	}

}