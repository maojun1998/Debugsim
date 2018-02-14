#include <string.h>
#include <stdio.h>

#include "cmdtrans.h"
#include "assember.h"
#include "disassember.h"


static Status asm_mode(char *buffer);
static Status date_mode(char *buffer);
static Status modify_mode(char *buffer);
static Status reg_mod(char *buffer);
static Status sgle_mod(char *buffer);
static Status disasm_mod(char *buffer);

void cmdtrans(char *buffer)
{
	unsigned short  len;
	int				counter;
	
	len = strlen(buffer);
	counter = 0;

	// Sklep the space in the buffer.
	while (buffer[counter] == BLANK &&
			counter < len) {
		counter++;
	}
		
	if (counter == len && len > 1) {
		
		goto Return_Flag;
	}
	
	// As the tradtional debug usesage. A is for asmmber mode,
	// D is in data mod...
	switch (buffer[counter]) {
		case 'A' :
		case 'a' : 	if (asm_mode(&buffer[counter + 1]) == STATUS_FL)
						goto Flag_Error;
				
					break;
		case 'D' :
		case 'd' :	if (date_mode(&buffer[counter + 1]) == STATUS_FL)
						goto Flag_Error;
					break;
		case 'E' :
		case 'e' :	if (modify_mode(&buffer[counter + 1]) == STATUS_FL)
						goto Flag_Error;
					break;
		case 'L' :
		case 'l' :	
					break;
		case 'R' :
		case 'r' :	if (reg_mod(&buffer[counter + 1]) == STATUS_FL)
						goto Flag_Error;
					break;
		case 'T' :
		case 't' :	if (sgle_mod(&buffer[counter + 1]) == STATUS_FL);
						goto Flag_Error;
					break;
		case 'U' :
		case 'u' :	if (disasm_mod(&buffer[counter + 1]) == STATUS_FL)
						goto Flag_Error;
					break;
		default  :	goto Flag_Error;
	}

//	Return successfull.
Return_Flag:

	return;

//	Error Flag, Return the call.
Flag_Error:
	printf("-No such command.\n");
	return ;
}

static Status asm_mode(char *buffer)
{
	return STATUS_FL;

}

static Status date_mode(char *buffer)
{
	return STATUS_FL;

}

static Status modify_mode(char *buffer)
{
	return STATUS_FL;

}

static Status reg_mod(char *buffer)
{
	return STATUS_FL;

}

static Status sgle_mod(char *buffer)
{
	return STATUS_FL;

}

static Status disasm_mod(char *buffer)
{
	return STATUS_FL;

}


