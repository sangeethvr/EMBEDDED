//PIC MASTER <- ATMEGA
#include<pic18.h>
char Trans(char b)
 {
    while(TXIF==0);
    TXREG=b;
     
    TXIF=0;
    //delay(100);
 }
void i2c_init()
{
SSPSTAT=0x00;//1000
SSPCON1=0x28;//
SSPCON2=0x00;

SSPADD=49;   
}
void i2c_start()
{
SEN=1;
while(SEN==1);//
}
void i2c_stop()
{
PEN=1;
while(PEN==1);//
}
void i2c_data(char a)
{
SSPIF=0;
SSPBUF=a;
while(SSPIF==0);
}
char i2c_read(char a)
{
RCEN=1;//receive 
while(RCEN);//
ACKDT=a;//1- NACK before stopping 0->ack
ACKEN=1;
while(ACKEN);
return SSPBUF;
}
void main()
{
	int i;
    TRISC=TRISD=0x00;
    TRISC=0x18;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=129;
i2c_init();
i2c_start();//start slavead+R/w  
i2c_data(0xd1);//1101 00 d0 and 1
char m=i2c_read(0);
Trans(m);

m=i2c_read(1);
Trans(m);
i2c_stop();
while(1) 	
{

}
}

/*
Master will slave ad+r Ack slave to master 
1. Nack
2. Ack


*/
