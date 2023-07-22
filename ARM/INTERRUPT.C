/* Standard includes. */
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "portmacro.h"

SemaphoreHandle_t xBinarySemaphore;



static void vHandlerTask( void *pvParameters );

void blink1(void *pvParameters)
{
    while(1) 
		{
			IOCLR1=0x10000;	//
			vTaskDelay(50);
			IOSET1=0x10000;
			vTaskDelay(50);
    			   
    }
}

void blink2(void *pvParameters)
{
    while(1) 
		{
		 	IOCLR1=0x20000;	//
			vTaskDelay(100);
			IOSET1=0x20000;
			vTaskDelay(50);
    }
}

void blink3(void *pvParameters)
{
    while(1) 
		{
			IOCLR1=0x40000;	 //
			for(i=0;i<=10000;i++);;
			IOSET1=0x40000;
			vTaskDelay(50);			   
    }
}
void trans(char);
void uart0(void *pvParameters)
{
    while(1) 
		{
			trans('A');
			trans('B');
			vTaskDelay(100);
		}
		
}



 void vIntrHandler( void ) __irq
{
	char i;
	BaseType_t xHigherPriorityTaskWoken;
	for(i='A';i<='z';i++)
	trans(i);
	vTaskSuspendAll();
	xHigherPriorityTaskWoken = pdFALSE;	  //0
	xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken );
	
	 	EXTINT=0x02;
	xTaskResumeAll();
	
}
int main( void )
{
	IO0DIR=0x00000000;
	IO1DIR=0xFFFFFFFF;
	PINSEL0=1|1<<29;
	VICIntEnable=1<<15;
	VICVectCntl3=1<<5|15;
	VICVectAddr3=(unsigned long)vIntrHandler;  //	16

	EXTMODE=1<<1;//	 
	EXTPOLAR=0; //
	EXTINT=2;

U0LCR=0X83;
U0DLL=98;  //9600baud, 10Mhz
U0DLM=0;  //9600baud, 10Mhz
U0LCR=0X03;
trans('U');
xBinarySemaphore = xSemaphoreCreateBinary();
//portENABLE_INTERRUPTS();

xTaskCreate(blink1, (const char *)"Blink1", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(blink2, (const char *)"Blink2", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(blink3, (const char *)"Blink3", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(uart0,  (const char *)"uart0",  configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate( vHandlerTask, "Handler", 256, NULL, 3, NULL );
//vPortSetInterruptHandler( mainINTERRUPT_NUMBER, ulIntrHandler );
 
vTaskStartScheduler();

/* Should never reach here!  If you do then there was not enough heap
available for the idle task to be created. */
for( ;; );
}

static void vHandlerTask( void *pvParameters )
{
   for(;;)
   {
		xSemaphoreTake( xBinarySemaphore, 2000 );
		IO1SET=0x00F00000;
		vTaskDelay(20);
		IO1CLR=0x00F00000;
		trans('D');	
   }

}

void trans(char b)
{
U0THR=b;
while((U0LSR&0X20)==0);
}
