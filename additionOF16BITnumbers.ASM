;THIS IS ADDITION OF TWO 16BIT NUMBERS 
ORG 00H
     SJMP 30H
ORG 30H
    
		; GIVE THE VALUE TO 31H[MSB] AND 32H[LSB] FOR 1ST NUMBER 
		; GIVE THE VALUE TO 41H[MSB] AND 42H[LSB] FOR 2ND NUMBER 
		MOV A,32H
		ADD A,42H
		MOV 53H,A
		MOV A,31H
		ADDC A,41H
		MOV 52H,A
		MOV A,#00H
		ADDC A,#00H
		MOV 51H,A
LOOP:	SJMP LOOP
END