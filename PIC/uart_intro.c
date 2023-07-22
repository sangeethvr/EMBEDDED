#include <pic.h>
void main()
{
TXSTA=0x20;
SPBRG=25;
RCSTA=0x80;
TRISC=0x00;
PORTC=0x00;
while(1)
{
	int i;
	while(TXIF==0);//TXIF=0 when data i loaded TXIF=1
	TXREG=97;
	for(i=0;i<=10000;i++);
}
}