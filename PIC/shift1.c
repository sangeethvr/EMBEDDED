#include<pic.h>
void main()
{
int i;
TRISB=0x00;

while(1)
{
int j;
for(j=1;j<=255;j=(j*2)+1)
{
PORTB=j;
for(i=0;i<=10000;i++)
{}
}


}

}