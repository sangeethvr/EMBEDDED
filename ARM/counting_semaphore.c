/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

//#define configUSE_COUNTING_SEMAPHORES 1				  //copy in freertos.h
int i;
char x;
void trans(char b);

SemaphoreHandle_t xcountingsemaphore;
SemaphoreHandle_t xmutex;

void fnA(void *pvParameters)
{
while(1) 
{	
if(xSemaphoreTake(xcountingsemaphore,2000))
{
i=uxSemaphoreGetCount(xcountingsemaphore);
if(xSemaphoreTake(xmutex,portMAX_DELAY))
{
x=i+48;
trans('A');
trans('-');
trans(x);
trans(0X0D);
xSemaphoreGive(xmutex);
}	
vTaskDelay(100);
IO1SET=0x00010000; //p1.16
vTaskDelay(500);
IO1CLR=0x00010000;
vTaskDelay(500);
}
}
}

void fnB(void *pvParameters)
{
while(1) 
{	
if(xSemaphoreTake(xcountingsemaphore,2000))
{
i=uxSemaphoreGetCount(xcountingsemaphore);
if(xSemaphoreTake(xmutex,portMAX_DELAY))
{
x=i+48;
trans('B');
trans('-');
trans(x);
trans(0X0D);
xSemaphoreGive(xmutex);
}	
vTaskDelay(100);			   //p1.17
IO1SET=0x00020000;
vTaskDelay(500);
IO1CLR=0x00020000;
vTaskDelay(500);
}
}
}

void fnC(void *pvParameters)
{
while(1) 
{	
if(xSemaphoreTake(xcountingsemaphore,2000))
{
i=uxSemaphoreGetCount(xcountingsemaphore);
if(xSemaphoreTake(xmutex,portMAX_DELAY))
{
x=i+48;
trans('C');
trans('-');
trans(x);
trans(0X0D);
xSemaphoreGive(xmutex);
}	
vTaskDelay(100);
IO1SET=0x00040000; //p1.18
vTaskDelay(500);
IO1CLR=0x00040000;
vTaskDelay(500);
}
}
}

void fnD(void *pvParameters)
{
while(1) 
{	
if(xSemaphoreTake(xcountingsemaphore,20))
{
i=uxSemaphoreGetCount(xcountingsemaphore);
if(xSemaphoreTake(xmutex,portMAX_DELAY))
{
x=i+48;
trans('D');
trans('-');
trans(x);
trans(0X0D);
xSemaphoreGive(xmutex);
}	
vTaskDelay(100);
IO1SET=0x00080000;			  //p1.19
vTaskDelay(50);
IO1CLR=0x00080000;
vTaskDelay(50);
}
}
}

void fnE(void *pvParameters)
{
while(1) 
{	
if(xSemaphoreTake(xcountingsemaphore,20))
{
i=uxSemaphoreGetCount(xcountingsemaphore);
if(xSemaphoreTake(xmutex,portMAX_DELAY))
{
x=i+48;
trans('E');
trans('-');
trans(x);
trans(0X0D);
xSemaphoreGive(xmutex);
}	
vTaskDelay(100);				//p1.20
IO1SET=0x00100000;
vTaskDelay(50);
IO1CLR=0x00100000;
vTaskDelay(50);
}
}
}
			  
void semgive(void *pvParameters)
{
 while(1) 
	{
		if((IO1PIN&(1<<31))==0) // pull
		{	
	     xSemaphoreGive(xcountingsemaphore);
		 //xSemaphoreGive(xcountingsemaphore);
		// trans('o');
	     vTaskDelay(200);
	    }
	}
	  
}
			 
	  
///////////////////////////////////////////
int main( void )
{
xcountingsemaphore = xSemaphoreCreateCounting( 3,2 );
xmutex = xSemaphoreCreateMutex();
IODIR1 = ~(1<<31);
IODIR0 = 0X00000000;

PINSEL0=0x00000001;
U0FCR=3<<1;
U0FCR=1;
U0LCR=0X83;
U0DLL=98;  //9600baud, 10Mhz
U0DLM=0;  //9600baud, 10Mhz
U0FDR=1<<4;
U0LCR=0X03;	
//xTaskCreate(fnA, (const char *)"FunctionA", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
//xTaskCreate(fnB, (const char *)"FunctionB", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
//xTaskCreate(fnC, (const char *)"FunctionC", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(fnD, (const char *)"FunctionD", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(fnE, (const char *)"FunctionE", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(semgive, (const char *)"Sem_Give", configMINIMAL_STACK_SIZE, (void *)NULL, tskIDLE_PRIORITY, NULL);

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

