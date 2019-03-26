; SUM OF 1ST N NATURAL NUMBER

ORG 00H
    SJMP 30H
ORG 30H
          N   EQU 32H	 ;HERE WE NAMING THE 32H MEMOREY LOCATION AS N [nth natural NUM] 
	      SUM EQU 34H	 ;------"----------- 34H ------------------- SUM [to store the sum of n natural number]
		  MOV N,#10
		  MOV SUM,#00
		  MOV R0,SUM
COUNT :	  INC R0
		  MOV A,SUM
		  ADD A,R0
		  MOV SUM,A
		  DJNZ N,COUNT	;DJNZ [DECREMENT AND JUMP IF N IF NOT EQUAL TO ZERO] LOOPING WILL OCCURE
LOOP :    SJMP LOOP
END