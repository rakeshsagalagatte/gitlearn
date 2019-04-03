	#include<reg51.h>
void main()
{
 unsigned char x,count=0,i;
 P0=0x00;
 P1=0xff;
 x=P1;
 for(i=0;i<8;i++)
 {
  if(x&0x01==1)
  {
   count++;
  }
  x=x>>1;
 }
 if(count%2==0)
  P0=0xff;
 else
  P0=0x00;
 P0=count;
 while(1);
}