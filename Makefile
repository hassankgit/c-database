C = gcc
TARGETS = ccadd ccdel ccitem cclist ccmatch ccyear ccedit

all: $(TARGETS)

ccadd: ccadd.c cc.h
	$(CC) -o ccadd ccadd.c

ccdel: ccdel.c cc.h
	$(CC) -o ccdel ccdel.c

ccitem: ccitem.c cc.h
	$(CC) -o ccitem ccitem.c

cclist: cclist.c cc.h
	$(CC) -o cclist cclist.c

ccmatch: ccmatch.c cc.h
	$(CC) -o ccmatch ccmatch.c

ccyear: ccyear.c cc.h
	$(CC) -o ccyear ccyear.c

ccedit: ccedit.c cc.h
	$(CC) -o ccedit ccedit.c

clean:
	rm -f $(TARGETS)
