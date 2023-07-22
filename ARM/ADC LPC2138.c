#include<lpc21xx.h>
void delay(int);
void cmd(int);
void data(char);
void main()
{
	int a;
	
	IO1DIR=0XFFFFFFFF;
	IO0DIR=0XF0FFFFFF;
	PINSEL1=0X400000;//ad 0.0
	
	cmd(0X38);		                                          
	cmd(0X80);					 									                     
	cmd(0X01);
	cmd(0X06);
	cmd(0X0E);
	while(1)
	{
		delay(50);
		ADCR=0X01200401;	//EDGE =1 |START CONVERSION |10 BITS |  
		while((ADDR&0X80000000)==1);
		a=ADDR>>6;
		data((a/1000)+48);
		data(((a/100)%10)+48);
		data((a%100)/10+48);
		data(a%10+48);
		delay(50);
		cmd(0X01);
	
	}
}
void cmd(int a)
{

IO1CLR=0XFFFFFFFF;
IO1SET=a<<16;
IO1SET=0X20000000;
delay(50);
IO1CLR=0X20000000;
delay(50);
}



void data(char b)
{

IO1CLR=0XFFFFFFFF;
IO1SET=b<<16;
IO1SET=0X30000000;
delay(50);
IO1CLR=0X20000000;
delay(50);
}

 
void delay(int t)
{
int i,j;
for(i=0;i<t;i++)
for(j=0;j<500;j++);
}