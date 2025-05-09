#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/stat.h>
#include "cc.h"

// ccedit.c - Edit an item in the database

int main(int argc, char* argv[]) {
	CComp editcomp;
	FILE* fp;
	int id;
	char input[200];

	if (argc != 2) {
		fprintf(stderr, "Usage: ccedit [ID]\n");
		return 1;
	}

	id = atoi(argv[1]);

	fp = fopen("ccdb", "r+");
	if (fp == NULL) {
		perror("ccdb");
		return 2;
	}

	flock(fileno(fp), LOCK_EX);

	fseek(fp, id * CCsize, SEEK_SET);
	fread(&editcomp, CCsize, 1, fp);
	
	printf("Edit item ID: %d\n", id);
	printf("Maker: %s\n", editcomp.maker);
	printf("Enter a new maker or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		strncpy(editcomp.maker, input, 15);
		editcomp.maker[strcspn(editcomp.maker, "\n")] = '\0';
	}

	printf("Model: %s\n", editcomp.model);
	printf("Enter a new model or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		strncpy(editcomp.model, input, 15);
		editcomp.model[strcspn(editcomp.model, "\n")] = '\0';
	}

	printf("Year: %d\n", editcomp.year);
	printf("Enter a new year or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		editcomp.year = atoi(input);
	}

	printf("CPU: %s\n", editcomp.cpu);
	printf("Enter a new CPU or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		strncpy(editcomp.cpu, input, 7);
		editcomp.cpu[strcspn(editcomp.cpu, "\n")] = '\0';
	}

	printf("Memory: %s\n", editcomp.memory);
	printf("Enter a new memory or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		strncpy(editcomp.memory, input, 7);
		editcomp.memory[strcspn(editcomp.memory, "\n")] = '\0';
	}

	printf("Description: %s\n", editcomp.desc);
	printf("Enter a new description or press enter to skip: ");
	fgets(input, sizeof(input), stdin);
	if (strlen(input) > 1) {
		strncpy(editcomp.desc, input, 199);
		editcomp.desc[strcspn(editcomp.desc, "\n")] = '\0';
	}

	fseek(fp, id * CCsize, SEEK_SET);
	fwrite(&editcomp, CCsize, 1, fp);

	flock(fileno(fp), LOCK_UN);
	fclose(fp);

	return 0;
}
