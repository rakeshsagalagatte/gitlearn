#include<reg51.h>

void main()
{	 unsigned int z;
   unsigned char x,y;
   P0 = 0x00;
   P1 =0xff;
   x=P1;
   y=P1;
    z=(int)x*(int)y;
   P0=(char)z;
   z=z>>8;
   P0=(char) z;
   while(1);
}