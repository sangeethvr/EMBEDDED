#include<pic.h>
void init(void)
{
TRISB=0xff;
PORTB=0x00;
TRISC=0x31;
PORTC=0x00;
TRISD=0x00;
PORTD=0x00;
TXSTA=0x20;
RCSTA=0x80;
SPBRG=25;
}

void data(char a)
{
	int i;
	RC1=1;
	RC2=0;
	RC3=1;
	PORTD=a;
	for(i=0;i<=10000;i++);
	RC3=0;

}

void cmd(char a)
{
	int i;
	RC1=0;
	RC2=0;
	RC3=1;
	PORTD=a;
	for(i=0;i<=10000;i++);
	RC3=0;

}
void main()
	{
	int a[8]={0,0,0,0,0,0,0,0};
	
	init();
	while(1)
	{
	if(RC4==1)
	{
		char c[4];
		int j,i;
		for(j=0;j<=7;j++)
	{
	if(a[j]==0)
	{
	while(TXIF==0);
TXREG='0';
	}
for(i=0;a[j]>0;i++)
{
c[i]=(a[j]%10)+0x30;   
a[j]=a[j]/10; 
}
for(i--;i>=0;i--)
{
while(TXIF==0);
TXREG=c[i];
}
while(TXIF==0);
TXREG=0x0d;
	}
	while(RC4==1);
	}
	if(RC5==1)
	{
	char symbol[]="* & % $ # @ + - >";
	int temp=1;
	cmd(0x0F);
	cmd(0x01);
	for(temp=0;symbol[temp]!=0;temp++)
	{
	data(symbol[temp]);
	}
	while(RC5==1)
		{
		if(RC0==1)//Controller election
			{
			temp=1;
			while(PORTB==0x00 || temp==1)
				{
			switch(PORTB)
				{
				case 0x01:
				a[0]++;
				temp=0;
				break;
				case 0x02:
				a[1]++;
				temp=0;
				break;
				case 0x04:
				a[2]++;
				temp=0;
				break;
				case 0x08:
				a[3]++;
				temp=0;
				break;
				case 0x10:
				a[4]++;
				temp=0;
				break;
				case 0x20:
				a[5]++;
				temp=0;
				break;
				case 0x40:
				a[6]++;
				temp=0;
				break;
				case 0x80:
				a[7]++;
				temp=0;
				break;
				}
			}
			}
		}
	}
	}
	}