/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
void data(char);
void trans(char);
void cmd(char);
void delay(void);
void cmd1(char);
void blink1(void *pvParameters)
{
    while(1) 
		{
			IOSET1=0x10000;
      vTaskDelay(500);
    
				
      IOCLR1=0x10000;
			vTaskDelay(500);
			   
    }
}

void blink2(void *pvParameters)
{
    while(1) 
		{
			IOSET1=0x20000;
			vTaskDelay(500);
				
      IOCLR1=0x20000;
			vTaskDelay(1000);
			   
    }
}

void blink3(void *pvParameters)
{
    while(1) 
		{
			IOSET1=0x40000;
			vTaskDelay(500);
				
      IOCLR1=0x40000;
			vTaskDelay(1500);
			   
    }
}

void uart0(void *pvParameters)
{
    while(1) 
		{
			trans('A');
			trans('B');
			vTaskDelay(1000);
		}
		
}
void temperature(void *pvParameters)
{
int a1;
while(1)
{
cmd(0xC0);
data('T');
data('e');
data('m');
data('p');
data(':');
 AD0CR=1<<21|1<<0|4<<8;
delay();
AD0CR|=1<<24;  //F since vpbdiv=1  0000 0001 0010  0000 0000 1111 0000 0001	  15/(15+1)=1Mhz
while(!(AD0GDR&(1<<31))) ;
a1=AD0GDR&0XFFC0;
a1=a1>>6;
cmd(0X80);
data((a1/1000)+48);
data(((a1/100)%10)+48);
data((a1%100)/10+48);
data(a1%10+48);
vTaskDelay(100);
}		
}

void message(void *pvParameters)
{
while(1)
{
cmd(0X83);
data('H');
data('E');
data('L');
data('L');
data('O');
vTaskDelay(1000);
cmd(0X83);
data(' ');
data(' ');
data(' ');
data(' ');
data(' ');
vTaskDelay(1000);
}		
}

///////////////////////////////////////////
int main( void )
{
/* LED/LCD pins need to be output. */
IO1DIR=~0;
PINSEL1=1<<22;   //ADc
/*uart0 config*/	
PINSEL0=1;
U0FCR=3<<1;
U0FCR=1;
U0LCR=0X83;
U0DLL=97;  //9600baud, 10Mhz
U0DLM=0;  //9600baud, 10Mhz
U0FDR=1<<4;
U0LCR=3;
/*LCD config*/
cmd1(0x3);
delay();
cmd1(0x3);
delay();
cmd(0x32);
cmd(0X28);
cmd(0X01);
cmd(0X06);
cmd(0x0f);

//xTaskCreate(blink1, (const char *)"Blink1", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
//xTaskCreate(blink2, (const char *)"Blink2", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
//xTaskCreate(blink3, (const char *)"Blink3", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(uart0,  (const char *)"uart0",  configMINIMAL_STACK_SIZE, (void *)NULL, 3, NULL);
xTaskCreate(temperature,  (const char *)"temperature",  configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(message,  (const char *)"message",  configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);

vTaskStartScheduler();

/* Should never reach here!  If you do then there was not enough heap
available for the idle task to be created. */
for( ;; );
}

void trans(char b)
{
while(!(U0LSR&(1<<5)));
U0THR=b;

}


void cmd1(char a)
{

IO1CLR=0XFFFFFFFF;

IO1SET=a<<20;
IO1SET=0X80000;
delay();
IO1CLR=0X80000;
}
void cmd(char a)
{
int temp,i,j;
IO1CLR=0XFFFFFFFF;
temp=a&0XF0;
temp=temp>>4;
IO1SET=temp<<20;
IO1SET=0X80000;
delay();
IO1CLR=0X80000;
   
IO1CLR=0XFFFFFFFF;
temp=a&0X0F;
IO1SET=temp<<20;
IO1SET=0X80000;//e=1 rs=0
delay();
IO1CLR=0X80000;
}
void data(char b)
{
int temp;
IO1CLR=0XFFFFFFFF;
temp=b&0XF0;	//msb
temp=temp>>4;
IO1SET=temp<<20;
IO1SET=0XA0000;	  //1010 0000 0000 0000 0000		 rs =1 e=1
delay();
IO1CLR=0X80000;

	
IO1CLR=0XFFFFFFFF;
temp=b&0X0F;
IO1SET=temp<<20;
IO1SET=0XA0000;
delay();
IO1CLR=0X80000;
}

void delay()
{
int i,j;
for(i=0;i<600;i++)
for(j=0;j<600;j++);
}
	
