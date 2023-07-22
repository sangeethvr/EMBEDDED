#include<lpc213x.h>
void data(char a)
{
int i;
IO0SET=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=10000;i++);
IO0CLR=1<<9;
}
void cmd(char  a)
{
long i;
IO0CLR=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=10000;i++);
IO0CLR=1<<9;
}
void display(const char p[])
{
int i=0;
while(p[i])
{
int k;
for(k=0;k<=10000;k++);
data(p[i]);
i++;
}
}
void main()
{
long i,adc;
IO0DIR=~0;
AD0CR=1<<21|4<<8;
PINSEL0=3<<8;
PINSEL1=1<<19;

cmd(0x0c);
for(i=0;i<=100000;i++);
cmd(0x80);
for(i=0;i<=100000;i++);
cmd(0x06);
for(i=0;i<=100000;i++);
cmd(0x01);
for(i=0;i<=100000;i++);
while(1)
{

char a[10];
for(i=0;i<=10000;i++);	 //acq
AD0CR|=1<<24|1<<6;
while(!(AD0GDR&(1<<31)));
adc=(AD0GDR>>6)&0x3ff;
cmd(0x8A);
		
if(adc==0)
{
data('0');
}
for(i=0;adc>0;adc/=10)
{
 a[i]=(adc%10)+0x30;
 i++;	
}
	for(i--;i>=0;i--)
	{
	data(a[i]);
	}
	data(' ');
	data(' ');
	data(' ');
}
}




/*
for(i=0;i<=10000;i++);	 //acq
while(!(AD0GDR&(1<<31)));
adc=(AD0GDR>>6)&0x3ff;
cmd(0x04);
cmd(0x8A);
if(adc==0)
{
data('0');
}
for(i=0;adc>0;adc/=10)
{
data((adc%10)+0x30);
}
data(' ');
data(' ');
data(' ');
*/