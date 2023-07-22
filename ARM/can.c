/******************************************************************************************************
*                                       CAN PROGRAM                                                   *
*******************************************************************************************************
*                                      HEADER FILES                                                   *
******************************************************************************************************/
#include<lpc21xx.h>

#define RS  0x00020000                  /*   17th pin RS                                             */
#define RW  0X00040000                  /*   18th pin R/W                                            */
#define EN  0X00080000                  /*   19th pin EN                                             */
#define CLR 0X00FE0000
/******************************************************************************************************
*                                     VARIABLE DECLERATION                                            * 
******************************************************************************************************/
volatile unsigned char recdata;
unsigned char data;
int flag=0;
/******************************************************************************************************
* Function    : Delay
*
* Description : command for Delay
*               
* Parameter   : x
******************************************************************************************************/
int Delay(unsigned int x)
 {
    x=x*12000;
    while(x!=0){
    x--;
    }
    return 0;
 }

/******************************************************************************************************
* Function    : Lcd_Command
*
* Description : command for lcd
*               
* Parameter   : command
******************************************************************************************************/
void Lcd_Command(char command)
 {
    int Temp;
    IO1CLR = CLR;                       /* Clear ALL 16-23 Pins                                      */
    IO1SET = EN;                        /* SET   19th Pin [EN]                                       */
    IO1CLR = RS;                        /* Clear 17th Pin [RS]                                       */
    IO1CLR = RW;                        /* Clear 18th Pin [R/W]                                      */
    Temp   = (command & 0xF0) << 16;    /* Higher Nibble Extracting 0X30 [3-High] & [4-7]    
                                           Shifted To [20-23]                                        */
    IO1SET = IO1SET | Temp;             /* 0X00080000 | 0X00300000[Shifted] = 0X00380000
                                           [Only '3' Is in [20-23]pins                               */
    Delay(2);                           /* Minimum Delay Time                                        */
    IO1CLR = EN;                        /* ENABLE High-Low Transition                                */
 }

/******************************************************************************************************
* Function    : Lcd_Command1
*
* Description : command for lcd
*               
* Parameter   : command1
******************************************************************************************************/
void Lcd_Command1(char command1)
 {
    int Temp;
    IO1CLR = CLR;                       /* Clear ALL 16-23 Pins                                      */
    IO1SET = EN;                        /* SET   19th Pin [EN]                                       */
    IO1CLR = RS;                        /* Clear 17th Pin [RS]                                       */
    IO1CLR = RW;                        /* Clear 18th Pin [R/W]                                      */
    Temp   = (command1 & 0xF0) << 16;   /* Higher Nibble Extracting 0X30 [3-High] & 
                                           [4-7] Shifted To [20-23]                                  */
    IO1SET = IO1SET | Temp;             /* 0X00080000 | 0X00300000[Shifted] = 0X00380000
                                           [Only '3' Is in [20-23]pins                               */
    Delay(2);                           /* Minimum DelayTime                                         */
    IO1CLR = EN;                        /* ENABLE High-Low Transition                                */
    IO1CLR = CLR;                       /* Clear ALL 16-23 Pins                                      */
    IO1SET = EN;                        /* SET   19th Pin [EN]                                       */
    IO1CLR = RW;                        /* Clear 17th Pin  [RS]                                      */
    IO1CLR = RS;                        /* Clear 18th Pin [R/W]                                      */
    Temp   = (command1 & 0x0F) << 20;   /* Lower Nibble [0-3] Shifted To [20-23] &
                                           [0-3] Shifted To [20-23]                                  */
    IO1SET = IO1SET | Temp;             /* 0X00080000 | 0X00800000[Shifted] = 0X00880000
                                           [Only '8' Is in [20-23]pins                               */
    Delay(2);                           /* Minimum Delay Time                                        */
    IO1CLR = EN;                        /* ENABLE High-Low Transition                                */
 }

/******************************************************************************************************
* Function    : Lcd_Data
*
* Description : display command for lcd   
*               
* Parameter   : data
******************************************************************************************************/
void Lcd_Data(char data)  
 {
    int Temp;
    IO1CLR = CLR;                       /* Clear ALL 16-23 Pins                                      */
    IO1SET = EN;                        /* SET   19th Pin [EN]                                       */
    IO1CLR = RW;                        /* Clear 18th Pin [R/W]                                      */
    IO1SET = RS;                        /* Clear 17th Pin [RS]                                       */
    Temp   = (data & 0xF0) << 16;       /* Higher Nibble Extracting 0X30 [3-High] & [4-7] 
                                           Shifted To [20-23]                                        */
    IO1SET = IO1SET | Temp;             /* 0X00080000 | 0X00300000[Shifted] = 0X00380000
                                           [Only '3' Is in [20-23]pins                               */
    Delay(2);                           /* Minimum DelayTime                                         */
    IO1CLR = EN;                        /* ENABLE High-Low Transition                                */
    IO1CLR = CLR;                       /* Clear ALL 16-23 Pins                                      */
    IO1SET = EN;                        /* SET   19th Pin [EN]                                       */
    IO1CLR = RW;                        /* Clear 18th Pin [R/W]                                      */
    IO1SET = RS;                        /* Clear 17th Pin  [RS]                                      */
    Temp   = (data & 0x0F)<<20;         /* Lower Nibble [0-3] Shifted To [20-23] & 
                                           [0-3] Shifted To [20-23]                                  */
    IO1SET = IO1SET | Temp;             /* 0X00080000 | 0X00800000[Shifted] = 0X00880000
                                           [Only '8' Is in [20-23]pins                               */
    Delay(2);                           /* Minimum DelayTime                                         */
    IO1CLR = EN;                        /* ENABLE High-Low Transition                                */
 }

/*******************************************************************************************************
* Function    : Lcd_String
*
* Description : display group of data    
*               
* Parameter   : dat
*******************************************************************************************************/
void Lcd_String(unsigned char *dat)
 {
    while(*dat!='\0') 
    {
      Lcd_Data(*dat);
	  dat++;
    }
 }

/******************************************************************************************************
* Function    : Lcd_Init
*
* Description : Funtion for initialize LCD to display data    
*               
* Parameter   : None
*******************************************************************************************************/
void Lcd_Init(void)
 {
    Delay(15);                         /* Delay (1.5ms)                                               */
    Lcd_Command(0x30);                 /* Single line enable(2X16)                                    */
    Delay(10);                         /* Delay (10us)                                                */
    Lcd_Command(0x30);                 /* Single line enable(2X16)                                    */
    Delay(5);                          /* Delay (0.5ms)                                               */
    Lcd_Command(0x30);                 /* Single line enable(2X16)                                    */
    Lcd_Command(0x20);                 /* 4-bit Mode Enable                                           */
    Lcd_Command1(0x28);                /* Double line enable (2X16)                                   */
    Lcd_Command1(0x01);                /* Clear LCD                                                   */
    Lcd_Command1(0x06);                /* Automatic increment                                         */
    Lcd_Command1(0x0C);                /* Cursor OFF /Display ON                                      */
 }

/******************************************************************************************************
* Function    :  Can_Rx_Isr
*
* Description : CAN_Reception interrupt function
*               
* Parameter   : None
*******************************************************************************************************/
void Can_Rx_Isr( void )__irq
{
    data=C2RDA;
    C2CMR = 0x04;                         /* release the receive buffer                              */
    VICVectAddr =0;  
}
/******************************************************************************************************
* Function    :  Cart_Init
*
* Description : Cart_Initialization function
*               
* Parameter   : None
******************************************************************************************************/
 void Cart_Init(void)
{
    PINSEL1 |= 0X00014000;              /* select pin for can rx   PINSEL1 |= 0x00014000L;
                                           [ Set bits 14 and 16 ]                                    */
    AFMR = 0x2;                         /* All rx messages were accepted(Acceptance filter mode 
	                                   register)                                                 */
    C2MOD = 0x01;                       /* Set CAN controller into reset                             */
    C2IER = 0;                          /* disable all interrupt                                     */
    C2GSR = 0;                          /* clear all interrupts                                      */
    C2BTR = 0x001C0011;                 /* 100 kbpsc                                                 */									   	
    VICVectCntl0 = 0x0000003b;          /* Interrupt vector number of CAN 2                          */
    VICVectAddr0 = (unsigned)Can_Rx_Isr;/* Interrupt vector address                                  */
    VICIntEnable = 0x08000000;          /* Enable vectored interrupt for CAN 2 module                */
    VICIntSelect = 0x00000000;          /* Initialise as IRQ                                         */
    C2IER = 0x01;                       /* Enable the Receive interrupt                              */
    C2MOD = 0x00;                       /* Release CAN controller                                    */
}
/******************************************************************************************************
* Function    :  Can_Tx
*
* Description : CAN_DATA Transmission function
*               
* Parameter   : data
******************************************************************************************************/
void Can_Tx(int data )
{
    if((C2SR & 0X00000004)==0X00000004) /*cheking for CAN bus idle                                   */
    {
       C2TFI1 = 0x00010000;             /* DLS&RTR(Transmit frame information register,
                                           No.data bytes transmitted)                                */
       C2TID1 = 0x22;                   /* 11 bit Identefier                                         */
       C2TDA1 = data;                   /* Data                                                      */
       C2CMR  = 0X21;                   /* transmission request (command register,select 
                                           tramission-1 TX buffer)                                   */
       while((C2GSR & 0X00000004)!=0X00000004);
                                        /* wait until complete transmission                          */
    }	
}
/******************************************************************************************************
*                             FUNCTION INITIALIZATION                                                 *
******************************************************************************************************/
void Port_Initial(void);
void Can_Rx_Isr( void )__irq;
/******************************************************************************************************
*                                   CODE AREA                                                         *
******************************************************************************************************/
int main()
 {
    Port_Initial();                     /* Function to initialize the direction & pinsel of ports    */
    Lcd_Init();                         /* Initialization LCD                                        */
    Cart_Init();                        /* Initialization of CAN                                     */
    Lcd_String("Rhydo Technology");     /* Initial displays                                          */
    Lcd_Command1(0xC0);
    Lcd_String("     Cochin     ");
    Lcd_Command1(0x01);
    Lcd_Command1(0x80);
    Lcd_String("CAN checking");         /* CAN checking                                              */
    while(1)
    {  
       if(data=='T')
       {
            IO0SET=0x000E0000;          /* SET HIGH for LED's                                        */
            Delay(500);
       }	
       if(data=='G')
       {
           IO0CLR=0x000E0000;           /* CLR LED's                                                 */
           Delay(500);
       }
       if(flag==0)
       {
           flag=1;Can_Tx('T');
       }
       else
       {
           flag=0;
           Can_Tx('G');
       }	
    }
 }
/******************************************************************************************************
*                               PORT INITIALIZATION                                                   *
******************************************************************************************************/
void Port_Initial(void)	
{
    IO1DIR      =   0x00FE0000;            /* 17-23 Pins As Output                                   */
    IO0DIR      =   0x000E0001;            /* for UART0 & LED' s                                     */
    PINSEL0     =   0x00000005;
    PINSEL1     =   0x05000000;
    PINSEL2     =   0x00000000;
} 
/*********************************************END*****************************************************/