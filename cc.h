// Point of a header file is to have common definitions

//ifndef (if not defined): only if these are not defined, then pass these on, or else blank them out and never process them

// #ifndef __C_H__
// #define __CC_H__
// 	--- Definitions ---
// #endif

typedef struct CComp CComp;

struct CComp {
	int id; // 4 bytes
	char maker[16];
	char model[16];
	int year; // 4 bytes
	char cpu[8];
	char memory[8];
	char desc[200];
	//total: 256 bytes
};

enum {
	CCsize = sizeof(CComp),
};
