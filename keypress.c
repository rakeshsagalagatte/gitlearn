#include<reg51.h>
#include "Lcd.h"

sfr port0 =0x80;
sfr port2 = 0xA0;
char keys[3][8] = {{'0','1','2','3','4','5','6','7'},
                 {'8','9','.','+','-','*','/','%'},
				 {'a','c','h','=','C','R','m','P'}
				};

   unsigned char scanval;
   char col,row,key;

   char msg[] = "key: ,row: ,col: ";

   char findkey()
   {
     int i;
	 for(i=0;i<8;i++)
	 {
	   key = keys[row][col];
	   return (key);
	 }
	 scanval = scanval >> 1;
	 col++;
   }

   void main()
   {
     port0 = 0x0;
	 port2=0xff;
	 InitLcd();
	 while(1)
	 {
	   col =0;
	   scanval = port0;
	   port2 = 0x06;
	   if(scanval!=0xff)
	   {
	      row =0;
		  findkey();
		  GotoXY(0,0);
		  msg[4]=key;
		  msg[10]='1';
		  msg[15]=col + 1 +30;
		  WriteString(msg);
	   }

	   col =0;
	   scanval = port0;
	   port2=0x05;
	   if(scanval!=0xff)
	   {
	     row =1;
		 key = findkey();
		 GotoXY(0,0);
		 msg[4]=key;
		 msg[10]='2';
		 msg[15]= col + 1 +30;
		 WriteString(msg);
	   }

	   col=0;
	   scanval = port0;
	   port2 = 0x03;
	   if(scanval!=0xff)
	   {
	     row =2;
		 key = findkey();
		 GotoXY(0,0);
		 msg[4]=key;
		 msg[10]='3';
		 msg[15]=col +1+30;
		 WriteString(msg);
	   }
	 }
   }