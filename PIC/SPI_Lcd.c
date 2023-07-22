#include<pic.h>
	char sec,min,hour,date,mon,year,day,cent;
void init(void)
{
	TRISC=0x10;//
	PORTC=0x40;
	SSPCON=0x30;
	SSPSTAT=0x00;
	TRISB=0x00;
	TRISD=0x00;
	PORTB=0x00;
	PORTD=0x00;
}
void data(char a)
{
	int i;
	RB0=1;
	PORTD=a;
	RB1=1;
	for(i=0;i<=10000;i++);
	RB1=0;
}	
void cmd(char a)
{
	int i;
	RB0=0;
	PORTD=a;
	RB1=1;
	for(i=0;i<=10000;i++);
	RB1=0;
}
void display(const char *p)
{
	while(*p)
	{
		data(*p++);
	}
}	
void main()
{
	int i;

	init();
	cmd(0x01);
	cmd(0x0c);//lcd on cursor on blibk on
	cmd(0x38);
	RC6=0;//slave select
	SSPBUF=0x3f;//burst mode
	SSPIF=0;
	while(SSPIF==0);
	SSPBUF=0x00;//sec
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x05;//min
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x11;//hours 0001 0001
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x02;//date
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x08;//mon
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x01;//day
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x21;//year
			SSPIF=0;
			while(SSPIF==0);
	RC6=1;
	for(i=0;i<=10000;i++);
	RC6=0;
		SSPBUF=0x13;//century year
			SSPIF=0;
			while(SSPIF==0);
				SSPBUF=0x20;//century year
			SSPIF=0;
			while(SSPIF==0);
			RC6=1;
			for(i=0;i<=10000;i++);
	
	while(1)
	{
			RC6=0;
			SSPBUF=0xBF;
			SSPIF=0;
			while(SSPIF==0);//sending burst read
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			sec=SSPBUF;//
			
			SSPBUF=0x00;//
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			min=SSPBUF;
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			hour=SSPBUF;
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			date=SSPBUF;
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			mon=SSPBUF;
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			day=SSPBUF;
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			year=SSPBUF;
			RC6=1;
			for(i=0;i<=10000;i++);
			RC6=0;
			SSPBUF=0x93;
			SSPIF=0;
			while(SSPIF==0);//sending century
			
			SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);//waiting to rec data
			cent=SSPBUF;//
			RC6=1;
	for(i=0;i<=10000;i++);
	sec=sec&0x7f;
		min=min&0x7f;
		hour=hour&0x1f;
	cmd(0x84);
	data(hour/16+0x30);
	data(hour%16+0x30);
	data(':');
	data(min/16+0x30);
	data(min%16+0x30);
	data(':');
	data(sec/16+0x30);
	data(sec%16+0x30);
	data(' ');
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
		data(cent/16+0x30);
		data(cent%16+0x30);
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