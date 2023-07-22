#include<pic.h>
void init(void)
{
T1CON=0x31;
CCP1CON=0x04;
TRISB=0x00;
PORTB=0x00;
}
void main()
{
init();
while(1)
{

}
}