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
void display(const char *p)
{
while(*p)
{
data(*p++);
}
}

void main()
{
int i;
IO0DIR=~0;
CCR=2;
CCR=1|1<<4;
SEC=0;
MIN=0;
HOUR=13;
DOM=1;
DOW=3;
MONTH=7;
YEAR=2020;
cmd(0x01);
for(i=0;i<=10000;i++);
cmd(0x0c);
cmd(0x38);
while(1)
{
  cmd(0x84);
 data(HOUR/10+0x30);
 data(HOUR%10+0x30);
 data(':');
 data(MIN/10+0x30);
 data(MIN%10+0x30);
 data(':');
 data(SEC/10+0x30);
 data(SEC%10+0x30);
 cmd(0xc0);
 data(DOM/10+0x30);
 data(DOM%10+0x30);
 switch(MONTH)
 {
 case 1:
 display(" Jan ");
 break;
 case 2:
 display(" Feb ");
 break;
 case 3:
 display(" Mar ");
 break;
 case 4:
 display(" Apr ");
 break;
 case 5:
 display(" May ");
 break;
 case 6:
 display(" Jun ");
 break;
 case 7:
 display(" Jul ");
 break;
 case 8:
 display(" Aug ");
 break;
 case 9:
 display(" Sep ");
 break;
 case 10:
 display(" Oct ");
 break;
 case 11:
 display(" Nov ");
 break;
 case 12:
 display(" Dec ");
 break;
 }
 data(YEAR/1000+0x30);
 data((YEAR%1000)/100+0x30);
 data((YEAR%100)/10+0x30);
 data(YEAR%10+0x30);
 switch(DOW)
 {
 case 0:
 display("  Sun");
 break;
 case 1:
 display("  Mon");
 break;
 case 2:
 display("  Tue");
 break;
 case 3:
 display("  Wed");
 break;
 case 4:
 display("  Thu");
 break;
 case 5:
 display("  Fri");
 break;
 case 6:
 display("  Sat");
 break;
 }
}
}
