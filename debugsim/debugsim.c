#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "opreg.h" 		// Init_Reg.
#include "cmdtrans.h"	// cmdtrans.
#include "opmem.h"		// Write_Byte_Mem.


#define BUFFER_SIZE 	200

char *copyright = "\nThis program was writen by Bobi and Hacking.\n\
Any problem or wana to report bug please sent Email to 1932197667@qq.com.\n\
The program obe the GPL-V3, You can use the source code any time.\n\n";

char *useage = "\n\t--version\t\tShow the version.\n"
				"\t-g       \t\t-g for to run the debug.\n"
				"\t--help   \t\t--help use.\n"
				"\t -m      \t\t-m xxx.file load the file into the memmory.\n";

static char 	buffer[BUFFER_SIZE];		// bufferr for kerboad input.
extern Regrp 	regrp;						// referece pointer for generation register grup.

void load_into_memmory(char * fname);		// load the mem dump in to memmory.

int main(int argc, char *argv[])
{
	
	
	/*
	 *	Init the register, make them all to be 0.
	 */
	Init_Reg(&regrp);

	if (argc < 2) {
		printf("%s", useage);
		return 0;
	} else if (argc == 2) {

			if (!strcmp(argv[1], "--version")) {
				printf("%s", copyright);
				return 0;
			} else if (!strcmp(argv[1], "-g")) {
				;
			} else if (!strcmp(argv[1], "--help")) {
				printf("%s", useage);
				return 0;
			} else {
				printf("\n-Use error.\n");
				return 0;
			}

	} else if (argc == 3 && !strcmp("-m", argv[1])) {
		load_into_memmory(argv[2]);

	} else {
		printf("Use error.\n");
		return 0;
	}

	do {
		putchar('-');
		gets(buffer);
		cmdtrans(buffer);
	} while (strcmp(buffer, "q") != 0 &&
				strcmp(buffer, "Q") != 0);
	
	return 0;
}

void load_into_memmory(char * fname)
{
	FILE *fp;
	extern Mem mem;

	if ((fp = fopen(fname,"r")) != NULL) {
		fread((char *)&mem.mem[0], 1, MEM_SIZE * MEM_SIZE);
	} else {
		printf("Error : %s." strerror(errno));
		exit(-1);
	}

}