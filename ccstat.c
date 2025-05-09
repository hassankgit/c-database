#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cc.h"

int main() {
	struct stat ccstat;
	
	stat("ccdb", &ccstat);
	printf("Inode: %ld\n", ccstat.st_ino);
	printf("Mode: %o\n", ccstat.st_mode);
	printf("Number of links: %ld\n", ccstat.st_nlink);
	printf("UID: %d\n", ccstat.st_uid);
	printf("GID: %d\n", ccstat.st_gid);
	printf("Size: %ld\n", ccstat.st_size);
	printf("Highest ID that is available: %ld\n", ccstat.st_size / CCsize);
}
