#include<pic.h>
void i2c_start(void)
{
	SEN=1;
	while(SEN==1);
}
void i2c_stop(void)
{
	PEN=1;
	while(PEN==1);
}
void i2c_write(char a)
{
	SSPBUF=a;//slave ad
	SSPIF=0;
	while (SSPIF==0);
}
void  i2c_rstart()
{
	RSEN=1;
		while(RSEN==1);
}		
char i2c_read(char a)
{
	RCEN=1;
	while(RCEN==1);//REC
	ACKDT=a;
	ACKEN=1;
	while(ACKEN==1);
	return SSPBUF;
}	
void main()
{
	TRISC=0x18;
	PORTC=0x00;
	SSPADD=2;
	SSPCON=0x28;
	SSPSTAT=0x00;
	i2c_start();  //Start condition
	i2c_write(0xd0);	//waiting to end start condition
	i2c_write(0x00);//sec memory
	i2c_write(0x05);//data to sec
	i2c_write(0x10);//data to min 01
	i2c_write(0x51);//data to hour 02
	i2c_write(0x01);//data to day 03
	i2c_write(0x02);//data to date 04
	i2c_write(0x08);//data to mnth 05
	i2c_write(0x20);//data to year 06
	i2c_stop();
	while(1)
	{
		i2c_start();
		i2c_write(0xd0);
		i2c_write(0x01);
		i2c_rstart();
		i2c_write(0xd1);
		i2c_read(0);
		i2c_read(1);
		i2c_stop();
	
		
	}
}	