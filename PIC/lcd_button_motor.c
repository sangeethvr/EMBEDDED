#include<pic.h>
void init(void)
{
TRISC=0x60;//DATA DIRECTION REGISTER INPUT OUTPUT  PIC TO LCD
PORTC=0x00;//
TRISD=0x00;
PORTD=0x00;
PORTB=0x00;
TRISB=0x00;
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
init();
cmd(0x01);//clear lcd
cmd(0x06);//increment cursor position
cmd(0x0E);//turn on lcd display cursor on blink off
cmd(0x80);//set cursor location to the 0th colomn
while(1)
{
if(RC5==1)
{
while(RC5==1);
RB1=1;
RB2=0;
cmd(0x01);
data('c');
data('l');
data('o');
data('c');
data('k');
data('w');
data('i');
data('s');
data('e');
}
if(RC6==1)
{
while(RC6==1);
RB1=0;
RB2=1;
cmd(0x01);
data('a');
data('n');
data('t');
data('i');
data('c');
data('l');
data('o');
data('c');
data('k');
data('w');
data('i');
data('s');
data('e');
}
}
}