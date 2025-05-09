#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/stat.h>
#include "cc.h"

// ccadd.c - Add an item to the database

int main(int argc, char* argv[]) {
	struct stat ccstat;
	CComp newcomp;
	FILE* fp;

	if (argc != 8) {
		fprintf(stderr, "Usage: ccadd [ID] [maker] [model] [year] [cpu] [memory] [description]\n");
		return 1;
	}

	memset(&newcomp, 0, CCsize);

	if (strcmp(argv[1], "-a") == 0) {
		stat("ccdb", &ccstat);
		newcomp.id = ccstat.st_size / CCsize;
	}
	else {
		newcomp.id = atoi(argv[1]);
	}
	strncpy(newcomp.maker, argv[2], 15);
	strncpy(newcomp.model, argv[3], 15);
	newcomp.year = atoi(argv[4]);
	strncpy(newcomp.cpu, argv[5], 7);
	strncpy(newcomp.memory, argv[6], 7);
	strncpy(newcomp.desc, argv[7], 199);

	fp = fopen("ccdb", "r+");
	if (fp == NULL) {
		fp = fopen("ccdb", "w");
		if (fp == NULL) {
			perror("ccdb");
			return 2;
		}
	}

	flock(fileno(fp), LOCK_EX);

	fseek(fp, newcomp.id * CCsize, SEEK_SET);
	fwrite(&newcomp, CCsize, 1, fp);

	flock(fileno(fp), LOCK_UN); 
	fclose(fp);

	return 0;
}
