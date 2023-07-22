/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
SemaphoreHandle_t xMutex;
QueueHandle_t xQueue;

void trans(char);
void trans_string(const char *p);

static void vReceiverTask( void *pvParameters )
{
int32_t lReceivedValue;
BaseType_t xStatus;
const TickType_t xTicksToWait = pdMS_TO_TICKS( 100 );
 for( ;; )
 {

 //if( uxQueueMessagesWaiting( xQueue ) != 0 )
 //{
//	  if(xSemaphoreTake(xMutex,2000)){
 //trans_string( "Queue should have been empty!\r\n" );}xSemaphoreGive(xMutex);
// }
 xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait );
 if( xStatus == pdPASS )
 {
	  if(xSemaphoreTake(xMutex,2000)){
 trans_string( " Received = ");
 trans( lReceivedValue );}xSemaphoreGive(xMutex);
 }
 else
 {
	 	 if(xSemaphoreTake(xMutex,2000)){
 trans_string( "Could not receive from the queue.\r\n" );}xSemaphoreGive(xMutex);
 }
 }
}
static void vSenderTask( void *pvParameters )
{
int32_t lValueToSend;
BaseType_t xStatus;
 lValueToSend=(int32_t)pvParameters;
 for( ;; )
 {

 xStatus = xQueueSend( xQueue, &lValueToSend, 100 );   //'a' 'b' 'c' 'c' 'c'
 if( xStatus !=1 )
 {
if(xSemaphoreTake(xMutex,2000)){
 trans_string( "Could not send to the queue.\r\n" );}
 }
 else
 {
 	  if(xSemaphoreTake(xMutex,2000)){
 trans_string( "Queue updated" );
 trans( lValueToSend ) ;
 trans(13);
 
 }xSemaphoreGive(xMutex);
 }
 }
}

///////////////////////////////////////////
int main( void )
{ 
xQueue = xQueueCreate( 18, sizeof( int32_t ) );	  //
xMutex = xSemaphoreCreateMutex();

/*uart0 config*/	
PINSEL0=0x00000001;
U0LCR=0X83;
U0DLL=98;  //9600baud, 10Mhz
U0DLM=0;  //9600baud, 10Mhz
U0FDR=1<<4;
U0LCR=0X03;
	
xTaskCreate( vSenderTask, "Sender1", 100, ( void * ) 'A', 1, NULL );
xTaskCreate( vSenderTask, "Sender2", 100, ( void * ) 'B', 1, NULL );
xTaskCreate( vSenderTask, "Sender3", 100, ( void * ) 'C', 1, NULL );

xTaskCreate( vReceiverTask, "Receiver", 100, NULL, 3, NULL );                 //Receiver task should be of higher prioroty

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

void trans_string(const char *p)
{
while(*p!='\0')
{
trans(*p);
p++;
}
}
