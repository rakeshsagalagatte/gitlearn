;BIT LEVEL 

ORG 00H 
    SJMP 30H
ORG 30H
       SETB C
	   CPL b
       ORL C,b
	   ORL C,/b
	   CPL C
	   CPL b 
	   MOV C,b
	   MOV b,C
	   SETB C
	   SETB b

      