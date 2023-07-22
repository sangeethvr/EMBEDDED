/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

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
void trans(char);
void uart0(void *pvParameters)
{
    while(1) 
		{
			trans('A');
			trans('B');
			vTaskDelay(1000);
		}
		
}

///////////////////////////////////////////
int main( void )
{
/* LED pins need to be output. */
IODIR1 = 0xff0000;
	
/*uart0 config*/	
PINSEL0=0x00000001;
U0LCR=0X83;
U0DLL=0X45;  //9600baud, 10Mhz
U0DLM=0X01;  //9600baud, 10Mhz
U0LCR=0X03;


xTaskCreate(blink1, (const char *)"Blink1", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(blink2, (const char *)"Blink2", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(blink3, (const char *)"Blink3", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(uart0,  (const char *)"uart0",  configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);

vTaskStartScheduler();

/* Should never reach here!  If you do then there was not enough heap
available for the idle task to be created. */
for( ;; );
}

void trans(char b)
{
U0THR=b;
while((U0LSR&0X20)==0);
}
