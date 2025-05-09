#include <stdio.h>
#include <string.h>
#include "cc.h" // <-- your own header files will be in quotes to distinguish between global header files

int main() {
	
	FILE* fp;
	CComp newcomp; // <-- this allocates space for the whole structure, if  you declare a pointer
						//     you'll have to manually allocate space for the structure
	
	memset(&newcomp, 0, CCsize);
	newcomp.id = 6;
	strcpy(newcomp.maker, "Apple");
	strcpy(newcomp.model, "Apple ][");
	newcomp.year = 1977;
	strcpy(newcomp.cpu, "6502");
	strcpy(newcomp.memory, "48k");
	strcpy(newcomp.desc, "The classic Apple computer");

	// fseek(file you're operating on, offset, whence);
	//		offset: in bytes
	//		whence options:
	//			SEEK_SET: operates from the offset from the beginning
	//			SEEK_CUR: operates from the offset
	//			SEEK_END: operates from the offset from the end of file
	// fseek(fp the file, the id/index multiplied by the size of the structure in bytes to offset correctly, and seek
	// from the offset from the beginning)
	
	// man fopen --> to see what all the flags do
	// fdopen: used to attach buffering ot fopen
	//
	fp = fopen("ccdb", "r+");
	if (fp == NULL) {
		fp = fopen("ccdb", "w");
		if (fp == NULL) {
			perror("test");
			return 1;
		}
	}

	fseek(fp, newcomp.id * CCsize, SEEK_SET);
	
	// fwrite(address of thing, size of thing, how many of thing, and to what file);
	fwrite(&newcomp, CCsize, 1, fp);
	fclose(fp);

	return 0;
}


