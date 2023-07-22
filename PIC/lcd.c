#include<pic.h>
void init(void)
{
TRISC=0x00;
PORTC=0x00;
TRISD=0x00;
PORTD=0x00;
}

void enable()
{
int i;
 RC2=1;
for(i=0;i<=1000;i++)
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
cmd(0x0f);//turn on lcd display cursor on blink on
cmd(0x85);//set cursor  position on first line
cmd(0x06);//entry mode cursor will increse
cmd(0x38);//Second line
cmd(0xc0);
data('W');
data('e');
data('l');
data('c');
data('o');
data('m');
data('e');
while(1)
{


}
}