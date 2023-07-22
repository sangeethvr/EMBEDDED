#include<pic.h>
char pass[]="1234",inp[4];
int v=0;
void init(void)
{
	TXSTA=0x20;
	RCSTA=0x90;
	SPBRG=25;
	TRISC=0x80;
	PORTC=0x00;
}	
void txn(char a)
{
	while(TXIF==0);
	TXREG=a;
}	
void display(const char *a)
{
	while(*a)
	{
		txn(*a++);
	}
}
char rxn(void)
{
while(RCIF==0);
return RCREG;
}		
void main()
{
	int i;
	init();
	start:
	v=0;
	for(i=0;i<=3;i++)
	{
		inp[i]=0;
	}	
	display("Enter password");
	data(13);
	while(1)
	{
		char a;
		a=rxn();
		txn(a);
		if(v<=3)
		{
			inp[v]=a;
		}	
		v++;
		if(a==13)
		{
			int flag=0;
			for(i=0;i<=3;i++)
			{
				if(pass[i]==inp[i])
				{
					flag++;
				}
			}
			if(flag==4&&v==5)
			{
				display("Password Matched");
			}
			else
			{
				display("Wrong");
			}
			data(
			goto start;			
				
		}
	
	}
}
	