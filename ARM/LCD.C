			  #include<lpc214x.h>
void cmd(char a)
{
int i=0;
IO0CLR=1;		//rs=0
IO0CLR=0XFF<<3;		  //0.3 to 0.10 0v o/p
IO0SET=a<<3;		  //
 IO0SET=1<<2;			//e=1 
	  for(i=0;i<1000;i++)	  //220ns
     {} 
 IO0CLR=1<<2;			 //e=0
			  
}
  void data(char a)
{
int i=0;
IO0SET=1;		//rs=1
IO0CLR=0XFF<<3;		  //0.3 to 0.10 0v o/p
IO0SET=a<<3;		  //
 IO0SET=1<<2;			//e=1 
	  for(i=0;i<1000;i++)	  //220ns
     {} 
 IO0CLR=1<<2;			 //e=0
			  
}
void display(const char p[])//p=?   *p	 *p
{
int i=0;
while(p[i])
{
   data(p[i]);
   i++;
}
}
 void main()
 {
 long i;
PINSEL0=0;
IO0DIR=~0;
IO1DIR=~0;
cmd(0x0f);
cmd(0x01);//clear
cmd(0x0c);//lcd on cursor on cursor blink on
cmd(0x06);//inc cursor position after evry display
while(1)
{
int j;
	cmd(0x01);
	 cmd(0x8f);
	display("Welcome");
for(j=1;j<=16+(4-1);j++)
{
 for(i=0;i<=100000;i++);
 cmd(0x18);

 }
 for(i=0;i<=100000;i++);

 }
  }