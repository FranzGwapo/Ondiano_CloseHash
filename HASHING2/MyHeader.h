#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define EMPTY 0
#define DELETED -1

typedef struct {
	int elem;
	int link;
} Data;

typedef struct {
	Data *data;
	int avail;
	int count;
	int max;	
} VSpace;


VSpace newVSpace(int max);
int allocSpace(VSpace *vs);
int hash(int val, int size);
//void freeSpace(VSpace *vs, int loc);
bool addElement(VSpace *vs, int elem);
bool removeElement(VSpace *vs, int elem);
void visualize(VSpace vs); 

#endif
