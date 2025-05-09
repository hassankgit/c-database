#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include "cc.h"

// ccitem.c - Returns item information given an ID.

int main (int argc, char* argv[]) {
	CComp item;
	int id;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Usage: ccitem [id]\n");
		return 1;
	}

	id = atoi(argv[1]);
	fp = fopen("ccdb", "r");
	if (fp == NULL) {
		fprintf(stderr, "No database found.\n");
		return 2;
	}
	flock(fileno(fp), LOCK_EX);
	fseek(fp, id * CCsize, SEEK_SET);
	fread(&item, CCsize, 1, fp);

	if (item.id != 0) {
		printf("ID: %d\n", item.id);
		printf("Maker: %s\n", item.maker);
		printf("Model: %s\n", item.model);
		printf("Year: %d\n", item.year);
		printf("CPU: %s\n", item.cpu);
		printf("Memory: %s\n", item.memory);
		printf("Description: %s\n", item.desc);
	}
	flock(fileno(fp), LOCK_UN);
	fclose(fp);

	return 0;
}
