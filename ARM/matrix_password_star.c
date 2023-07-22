#include<lpc214x.h>
int loc=0,count;
char pass[]="1234",inp[5];
char c,flag;
void data(char a)
{
int i;
IO0SET=1<<8;
IO0CLR=0xff<<10;
if(a<='9' && a>='0')
{
IO0SET='*'<<10;
}
else
{
IO0SET=a<<10;
}
IO0SET=1<<9;
for(i=0;i<=1000;i++);
IO0CLR=1<<9;
if(count<=3)
{
inp[count]=a;
}
count++;
while((IO0PIN&0xf0)!=0xf0);
}
void cmd(char a)
{
int i;
IO0CLR=1<<8;
IO0CLR=0xff<<10;
IO0SET=a<<10;
IO0SET=1<<9;
for(i=0;i<=1000;i++);
IO0CLR=1<<9;
while((IO0PIN&0xf0)!=0xf0);
}
 void display(const char *p)
 {
 while(*p)
 {
 data(*p++);
 loc++;
 count=0;
 }

 }
void main()
{
int k,i;
PINSEL0=0;
PINSEL1=0;
IO0DIR=~(0xf<<4);	//1111 1111 1111 1111 1111 1111 0000 1111
cmd(0x01);
loc=0;
cmd(0x0f);
cmd(0x06);
cmd(0x80);
cmd(0x38);//enable 2nd line
w:
for(c=0;c<=3;c++)
{
inp[c]=0;
}
cmd(0x01);
loc=0;
display("Enter Password");
cmd(0xc0);
loc=16;
c=0;
flag=0;
while(1)
{

IO0SET=0xf;
IO0CLR=1;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('7');
loc++;
break;
case 0xD0:
data('8');
loc++;
break;
case 0xB0:
data('9');
loc++;
break;
case 0x70:
goto w;

break;
}
 IO0SET=0xf;
IO0CLR=1<<1;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('4');
loc++;
break;
case 0xD0:
data('5');
loc++;
break;
case 0xB0:
data('6');
loc++;
break;
case 0x70:
if(loc>16)
{
cmd(0x10);
data(' ');
cmd(0x10);
loc--;
count-=2;
}
break;
}

 IO0SET=0xf;
IO0CLR=1<<2;
k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
data('1');
loc++;
break;
case 0xD0:
data('2');
loc++;
break;
case 0xB0:
data('3');
loc++;
break;
case 0x70:
data(' ');
loc++;
break;
}

 IO0SET=0xf;
IO0CLR=1<<3;

k=(IO0PIN&(0xf0));
switch(k)
{
case 0xe0:
c++;
if(c%2)
{
cmd(0x0E);//display on, cursor off blink off
}               //lcd on off
else
{
cmd(0x08);//lcd off cursor off blink off
}
break;
case 0xD0:
data('0');
loc++;
break;
case 0xB0:
if(count==4)
{
for(c=0;c<=3;c++)
{
if(pass[c]==inp[c])
{
flag++;
}
}
}
cmd(0x01);
if(flag==4 && count==4)
{
display("Password Correct");
}
else
{
display("Password Wrong"); 
}
for(i=0;i<=30000;i++);
goto w;
break;
case 0x70:
data(' ');
loc++;
break;
}

}
}