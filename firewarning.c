#include<reg51.h>

sfr port2=0xA0;
sfr port1=0x90;

void display(char arr[])
{  char i,j;
   char x;
  for(i=3;i>=0;i--)
  {
    x = arr[i];
	for(j=1;j<=8;j++)
	{
	  port1=x;
	  port2=0x00;
	  port2=0xff;
	  x=x>>1;
	}
  }
}

void delay(unsigned int t)
{
  unsigned int i,j;
  for(i=0;i<t;i++)
  {
     for(j=0;j<20000;j++);
  }
}

void main()
{
  unsigned char count =0;
  char fire[]= {0x71,0x9f,0xf5,0x61};
  char help[]= {0x91,0x61,0xe3,0x31};
  port1=port2=0;

  while(count<50)
  {
    display(fire);
	delay(1);
	display(help);
	delay(1);
	count++;
  }
  while(1);
}