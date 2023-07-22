/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
SemaphoreHandle_t xsem;

void blink1(void *pvParameters)
{

    while(1) 
		{	
			if(xSemaphoreTake(xsem,1000))
			{
			IOSET1=0x10000;
      vTaskDelay(500);
    
				
      IOCLR1=0x10000;
			vTaskDelay(500);
			   
    		}
			 IOSET1=0x20000;
			vTaskDelay(50);
			IOCLR1=0x20000;
			vTaskDelay(50);
	    }
}


void swt(void *pvParameters)
{
      while(1)
		{
		if((IO0PIN&0X00004000)==0)
	{	xSemaphoreGive(xsem); 
		vTaskDelay(200);}		   
    }
}





///////////////////////////////////////////
int main( void )
{
xsem=xSemaphoreCreateBinary();
IODIR1 = 0xff0000;
IODIR0 = 0X00000000;
	




xTaskCreate(blink1, (const char *)"Blink1", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(swt, (const char *)"swt", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);

vTaskStartScheduler();

/* Should never reach here!  If you do then there was not enough heap
available for the idle task to be created. */
for( ;; );
}


