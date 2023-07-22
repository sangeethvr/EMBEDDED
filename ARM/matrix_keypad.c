#include<lpc214x.h>
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
void cmd(char a)
{
int i;
IO0CLR=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=10000;i++);
IO0CLR=1<<9;
}
 void display(const char *p)
 {
 while(*p)
 {
 data(*p++);
 }
 }
void main()
{
int k;
PINSEL0=0;
PINSEL1=0;
IO0DIR=~(0xf<<4);
cmd(0x01);
cmd(0x0f);
cmd(0x06);
cmd(0x80);
while(1)
{
IO0SET=0xf;
IO0CLR=1;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('1');
break;
case 0xD0:
data('2');
break;
case 0xB0:
data('3');
break;
case 0x70:
data('4');
break;
}
 IO0SET=0xf;
IO0CLR=1<<1;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('5');
break;
case 0xD0:
data('6');
break;
case 0xB0:
data('7');
break;
case 0x70:
data('8');
break;
}

 IO0SET=0xf;
IO0CLR=1<<2;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('9');
break;
case 0xD0:
data('A');
break;
case 0xB0:
data('B');
break;
case 0x70:
data('C');
break;
}

 IO0SET=0xf;
IO0CLR=1<<3;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('D');
break;
case 0xD0:
data('E');
break;
case 0xB0:
data('F');
break;
case 0x70:
data('0');
break;
}
}
}