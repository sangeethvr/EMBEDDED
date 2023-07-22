#include<pic.h>
void init(void)
{
TRISC=0x00;//DATA DIRECTION REGISTER INPUT OUTPUT  PIC TO LCD
PORTC=0x00;//
TRISB=0x00;
PORTB=0x00;
}

void enable()
{
int i;
 RB2=1;
for(i=0;i<=1000;i++) //DELAY 
{}
RB2=0;
}

void data(char a)
{
PORTC=a;
RB0=1;
RB1=0;
enable();
}

void cmd(char a)
{
PORTC=a;
RB0=0;
RB1=0;
enable();
}
void display(const char *p)
{
while(*p)
{
data(*p);
p++;
}
}
void main()
{
int i;
init();
cmd(0x01);//clear lcd
cmd(0x02); //cursor position to home 0x80th position
cmd(0x06);//increment cursor position
cmd(0x0E);//turn on lcd display cursor on blink off
//cmd(0x80);//set cursor location to the 0th colomn
cmd(0x38);//Enables 2nd line.
cmd(0xc2);
data('e');
display("Welcome");

while(1)
{
//cmd(0x1c);

}
}