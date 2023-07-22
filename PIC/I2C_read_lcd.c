#include<pic.h>
void init(void)
{
	TRISC=0x18;//
	PORTC=0x00;
	TRISB=0x00;
	PORTB=0x00;
	TRISD=0x00;
	PORTD=0x00;
	SSPADD=2;//set scl=100Khz
	SSPCON=0x28;//enables i2c com, master
	SSPSTAT=0x00;//0
}	
void data(char a)
{
	int i;
	RB0=1;
	PORTD=a;
	RB1=1;
	for(i=0;i<=1000;i++);
	RB1=0;
}
void cmd(char a)
{
	int i;
	RB0=0;
	PORTD=a;
	RB1=1;
	for(i=0;i<=1000;i++);
	RB1=0;
}	
void display(const char *p)
{
	while(*p)
	{
		data(*p++);
	}
}		
void i2c_start(void)
{
	SEN=1;
	while(SEN==1);//TO EXECUTE THE START CONDITION
}
void i2c_stop(void)
{
	PEN=1;
	while(PEN==1);
}
void i2c_write(char a)//a=0xd0   slave ad+Write
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
	init();
	cmd(0x01);//clear lcd
	cmd(0x0c);//turn on lcd
	cmd(0x38);//enable 2 lines display

	while(1)
	{
		char sec,min,hour,ap,day,date,mon,year;
		i2c_start();//start condition
		i2c_write(0xd0);//slave+write
		i2c_write(0x00);//pointing to sec mem
		i2c_rstart();//repeated start 
		i2c_write(0xd1);//slave+read
		sec=i2c_read(0);//reading 0(sec) mem returning ack
		min=i2c_read(0);//reading 1(min) mem returning ack
		hour=i2c_read(0);//reading 2(hour) mem returning ack
		day=i2c_read(0);//reading 3(day) mem returning ack
		date=i2c_read(0);//reading 4(date) mem returning ack
		mon=i2c_read(0);//reading 5(month) mem returning ack
		year=i2c_read(1);//reading 6(year) mem returning nack
		i2c_stop();//stop
		sec=sec&0x7f;
		min=min&0x7f;
		ap=hour&0x20;
		hour=hour&0x1f;
		cmd(0x84);
		data(hour/16+0x30);
		data(hour%16+0x30);
		data(':');
		data(min/16+0x30);
		data(min%16+0x30);
		data(':');
		data((sec/16)+0x30);
		data((sec%16)+0x30);
		if(ap==0)
		{
			display("am");
		}
		else
		{
			display("pm");
		}
		cmd(0xC0);
		date&=0x3f;//date=date&0x3f;
		data(date/16+0x30);
		data(date%16+0x30);
		mon&=0x1f;
		switch(mon)
		{
			case 1:
			display(" Jan ");
			break;		
			case 2:
			display(" Feb ");
			break;
			case 3:
			display(" Mar ");
			break;		
			case 4:
			display(" Apr ");
			break;
			case 5:
			display(" May ");
			break;		
			case 6:
			display(" Jun ");
			break;
			case 7:
			display(" Jul ");
			break;		
			case 8:
			display(" Aug ");
			break;
			case 9:
			display(" Sep ");
			break;		
			case 0x10:  //10
			display(" Oct ");
			break;
			case 0x11:
			display(" Nov ");
			break;		
			case 0x12:
			display(" Dec ");
			break;
		}	
		display("20");
		data(year/16+0x30);
		data(year%16+0x30);
		switch(day&0x07)
		{
			case 1:
			display(" Sun");
			break;
			case 2:
			display(" Mon");
			break;
			case 3:
			display(" Tue");
			break;
			case 4:
			display(" Wed");
			break;
			case 5:
			display(" Thu");
			break;
			case 6:
			display(" Fri");
			break;
			case 7:
			display(" Sat");			
		}	
	}
}	