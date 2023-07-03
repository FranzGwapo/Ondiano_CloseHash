#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

VSpace newVSpace(int max){
	VSpace vs;
    
    vs.max = max%2 == 0? max: max + 1;
    vs.count = 0;
    vs.data = malloc(sizeof(Data) * vs.max);
    vs.avail = vs.max/2;
    
    int i;
    for(i = 0; i < vs.avail; ++i) {
        vs.data[i].elem = EMPTY;
        vs.data[i].link = -1;
    }
    
    for(; i < vs.max-1; ++i) {
        vs.data[i].elem = EMPTY;
        vs.data[i].link = i + 1;    
    }
    vs.data[i].elem = EMPTY;
    vs.data[i].link = -1;
    
    return vs;
}

void visualize(VSpace vs){
	 int i, half = vs.max/2;
    printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "","INDEX", "DATA", "LINK");
    printf("----------------------          ----------------------\n");    
    for(i = 0; i < half; ++i) {
        printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n", 
                i, vs.data[i].elem, vs.data[i].link, "",
                i + half, vs.data[i+half].elem, vs.data[i+half].link);
    }
	
}

int allocSpace(VSpace *vs){
	int retVal = vs->avail;
	
	if(retVal!=-1){
		vs->avail = vs->data[vs->avail].link;
		return retVal;
	}
}

int hash(int val, int size){
	return val%size;
}


bool addElement(VSpace *vs, int elem){
	int current, temp, hashval;
	int half = vs->max/2;
	hashval = hash(elem, vs->max/2);
	int packing = 0.70 * vs->max;
	if(vs->count%vs->max < packing && vs->avail!=DELETED){
		if(vs->data[hashval].elem == EMPTY){
			vs->data[hashval].elem = elem;
			vs->count++;
			return true;
		}
		else{
			int hehe = hashval;
			while(vs->data[hehe].elem!=elem){
				if(vs->data[hehe].link==-1){
					break;
				}
				hehe = vs->data[hehe].link;
			}
			if(vs->data[hehe].elem==elem){
				return false;
			}
			temp = allocSpace(vs);
			current = vs->data[hashval].link;
			vs->data[temp].elem = elem;
			vs->data[temp].link = current;
			vs->data[hashval].link = temp;
			vs->count++;
			return true;
		}

	}
		return false;
}
