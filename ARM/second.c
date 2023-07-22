#include <stdlib.h>
#include  "freertos.h"
#include  "task.h"
void function1(void *pvParameters)
{
 while(1)
 {
 	IO0SET=0xff;
	vTaskDelay(500);
 	IO0CLR=0xff;
	vTaskDelay(500);
 }
}
void function2(void *pvParameters)
{
 while(1)
 {
 	IO0SET=0xff<<8;		   //0xff00
	vTaskDelay(500);
 	IO0CLR=0xff<<8;//0xff00
	vTaskDelay(500);
 }
}
void trans(char a)
{
while(!(U0LSR&(1<<5)));
U0THR=a;
}
 void uart(void *pvParameters)
{
 while(1)
 {
 	trans('a');
	vTaskDelay(500);
 }
}

int main()
{
PINSEL0=1;
PINSEL1=0;
IO0DIR=~0;
U0LCR=3|1<<7;
U0FCR=3<<1;
U0FCR=1;
U0DLL=97;
U0DLM=0;
U0FDR=1<<4;
U0LCR=3;
xTaskCreate( function1,"first",90,NULL,2,NULL);
xTaskCreate( function2,"first",90,NULL,2,NULL);
xTaskCreate(uart,"u1",90,NULL,3,NULL);

vTaskStartScheduler();
while(1)
{
}
}
