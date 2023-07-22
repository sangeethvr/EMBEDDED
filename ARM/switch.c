#include<lpc214x.h>
void main()
{
int i=0;
PINSEL0=0;
PINSEL1=0;
IO0DIR=~(1);													
while(1)
{
int k;
 if((IO0PIN&(1))==(1))
 {

 	for(k=0;k<=30000;k++);
	 while((IO0PIN&(1))==(1));
 i++;
 }
 if(i%3==0)
 {
 	    IO0CLR=~0;
 }
 else if(i%3==1)
 {
 IO0SET=~0;
 }
 else
 {
 	    IO0CLR=~0;
		for(k=0;k<=10000;k++);
 IO0SET=~0;
 for(k=0;k<=10000;k++);
 }


}
}
