#include <pic.h>
void init(void)
{
TRISB=0X00;
PORTB=0X00;
TRISC=0x80;//
PORTC=0X00;
TXSTA=0X00;//8 low,async,8bit
RCSTA=0X90;//enabled serial port
SPBRG=25;
}

void main()
{
init();
while(1)
{
char rec;
while(RCIF==0);
rec=RCREG;
switch(rec)
{
case 'a':
RB0=0;
RB1=1;
break;
case 'c':
RB0=1;
RB1=0;
break;
case 's':
RB0=0;
RB1=0;
break;
}
}
}