#include<lpc213x.h>
void data(char a)
{
int i;
IO0SET=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=100000;i++);
IO0CLR=1<<9;
}
void cmd(char  a)
{
long i;
IO0CLR=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=100000;i++);
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
void adc(void)__irq
{
char num[4];			
int a,j,i;
a=(AD0GDR>>6)&0x3ff;
cmd(0x85);
if(a==0)
{
data('0');
}
else
{  for(i=0;a>0;a/=10)
{
num[i]=((a%10));
i++;
}
for(j=0;j<=10000;j++);
for(i--;i>=0;i--)
{
data(num[i]+0x30);
}
}
data(' ');
for(j=0;j<=10000;j++);
data(' ');
for(j=0;j<=10000;j++);
data(' ');
for(j=0;j<=10000;j++);
data(' ');
}
void main()
{
long i,flag;
PINSEL0=3<<8;
PINSEL1=0;
IO0DIR=~0;
cmd(0x01);
  for(i=0;i<=10000;i++);
cmd(0x0f);
VICIntSelect=0;
VICIntEnable=1<<18;
VICVectCntl0=18|1<<5;
VICVectAddr0=(unsigned long)adc;

 AD0CR=1<<21|4<<8|1<<6|1<<16;
	while(1)
{
	
}
}
