#include <avr/io.h>  
void i2c_init();
char i2c_statusr();
void i2c_statusw(char a);
int main(void)
{
DDRA=DDRB=0x00;
i2c_init();

i2c_statusw('S');
i2c_statusw('M');

while(1)
{

}
}

void i2c_init()
{
DDRC=0;//1111 1111
TWAR=0xd0;//  02 0   0110 1000 0x61
TWCR=0x44;//ack
TWCR|=0x80;// TWCR=TWCR|0x80
while((TWCR&(0x80))==0);//slave

}

char i2c_statusr()
{
TWCR=0x44;//
TWCR|=0x80;
while((TWCR&(0x80))==0);//slave ad+W
return TWDR;
//1 clear flag bit lpc2138/avr 0 1
}
void i2c_statusw(char a)
{
TWDR=a;
TWCR=0x44;//
TWCR|=0x80;
while((TWCR&(0x80))==0);
//1 clear flag bit lpc2138/avr 0 1
}