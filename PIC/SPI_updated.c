#include<pic.h>
void init(void)
{
	TRISC=0x10;//
	PORTC=0x40;
	SSPCON=0x30;
	SSPSTAT=0x00;
}
void main()
{
	int i;
	char sec,min,hour,date;
	init();
	RC6=0;
	SSPBUF=0x3f;//burst mode
	SSPIF=0;
	while(SSPIF==0);
	SSPBUF=0x00;//sec
	SSPIF=0;
	while(SSPIF==0);
		SSPBUF=0x05;//min
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x11;//hours
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x02;//date
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x08;//month
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x01;//day
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x21;//year
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x00;//year
			SSPIF=0;
			while(SSPIF==0);
			SSPBUF=0x20;//year
			SSPIF=0;
			while(SSPIF==0);
	RC6=1;
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
			while(STAT_BF==0);
			min=SSPBUF;
				SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);
			hour=SSPBUF;
				SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			while(STAT_BF==0);
			date=SSPBUF;
				SSPBUF=0x00;
			SSPIF=0;
			while(SSPIF==0);
			RC6=1;
			for(i=0;i<=10000;i++);
	
	
	}
}	