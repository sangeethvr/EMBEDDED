 #include<lpc214x.h>
 void main()
 {
 long i;
PINSEL0=0;
PINSEL1=0;
IO0DIR=~0;
IO1DIR=~0;
while(1)
{
IO0SET=0X55555555;
IO1SET=IO0PIN;
    for(i=0;i<2000000;i++)
     {}
IO0CLR=0X55555555;
IO1CLR=~IO0PIN;
     for(i=0;i<2000000;i++)
	 {}
  
  }
  }