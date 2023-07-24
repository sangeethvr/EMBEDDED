#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
void data(char a);
void cmd(char a);
void display(const char *p);
char k[100];
char p[]="2255";

int i=0,c=0;
int main(void)
{
    DDRC=0XFF;
	DDRD=0XFF;
	DDRB=0X0F;
	cmd(0X01);
	cmd(0X0E);
	cmd(0X06);
	cmd(0X38);
	cmd(0X80);
	

	
	while(1)
	{
		PORTB=0XFE;
		{
			
			if ((PINB & 0X10)==0)
			
				data('1');
	
			if((PINB & 0X20)==0)
			
				data('2');
	
			if((PINB & 0X40)==0)
			
				data('3');
		
			if((PINB & 0X80)==0)
			
				data('4');
		
		}
		
		
		PORTB=0XFD;
		{
			if ((PINB & 0X10)==0)
	
				data('5');

			if((PINB & 0X20)==0)

				data('6');

			if((PINB & 0X40)==0)
			
				data('7');

			if((PINB & 0X80)==0)
	
				data('8');

		}
		 if(i==4)
		 {
			 
			 
			 
			 for(i=0;i<4;i++)
			 {
				 if(k[i]== p[i])
				 {
					 c++;
				 }
				 
			 }
			 if(c==4)
			 {
				 display("success!");
				 
			 }
			 else
			 {
				 display("failed!");
			 }
		 }
	
		
	}
  
}

void data(char a)
{
	PORTC=a;
	PORTD=0X03;
	_delay_ms(100);
	PORTD=0X01;
	k[i]=a;
	i++;
	while((PINB & 0X10)==0||(PINB & 0X20)==0||(PINB & 0X40)==0||(PINB & 0X40)==0||(PINB & 0X80)==0);
	
}
void cmd(char a)
{
	PORTC=a;
	PORTD=0X02;
	_delay_ms(100);
	PORTD=0X00;
	
	
}
void display(const char *p)
{
	while(*p)
	{
		data(*p);
		p++;
	}
}