#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include "cc.h"

// ccdel.c - Delete an item from the database

int main(int argc, char* argv[]) {
	CComp empty;
	CComp item;
	int id;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Usage: ccdel [ID]\n");
		return 1;
	}

	id = atoi(argv[1]);

	fp = fopen("ccdb", "r+");
	if (fp == NULL) {
		fp = fopen("ccdb", "w");
		if (fp == NULL) {
			perror("ccdb");
			return 2;
		}
	}

	flock(fileno(fp), LOCK_EX);
	fseek(fp, id * CCsize, SEEK_SET);

	empty.id = 0;
	strncpy(empty.maker, "", 15);
	strncpy(empty.model, "", 15);
	empty.year = 0;
	strncpy(empty.cpu, "", 7);
	strncpy(empty.memory, "", 7);
	strncpy(empty.desc, "", 199);
	
	fwrite(&empty, CCsize, 1, fp); 

	printf("Succesfully deleted element at ID: %d.\n", id);
	flock(fileno(fp), LOCK_UN);
	fclose(fp);

	return 0;
}


