#include<pic.h>
void init(void)
{
TRISC=0x60;//DATA DIRECTION REGISTER INPUT OUTPUT  PIC TO LCD
PORTC=0x00;//
TRISD=0x00;
PORTD=0x00;
}

void enable()
{
int i;
 RC2=1;
for(i=0;i<=1000;i++) //DELAY 
{}
RC2=0;
}

void data(char a)
{
PORTD=a;
RC0=1;
RC1=0;
enable();
}

void cmd(char a)
{
PORTD=a;
RC0=0;
RC1=0;
enable();
}
void main()
{
int j=0;
init();
cmd(0x01);//clear lcd
cmd(0x02); //cursor position to home 0x80th position
cmd(0x06);//increment cursor position
cmd(0x0E);//turn on lcd display cursor on blink off
cmd(0x80);//set cursor location to the 0th colomn
cmd(0x38);//Enables 2nd line.

while(1)
{
if(RC5==1)
{
while(RC5==1);
j++;
if(j%2==1)
{
cmd(0x0f);
}
else
{
cmd(0x08);
}
}
if(RC6==1)
{
while(RC6==1);
data('a');
}
}
}