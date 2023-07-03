#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VSpace space = newVSpace(10);

	bool result;
	result = addElement(&space, 10);
	result = addElement(&space, 20);
	result = addElement(&space, 11);
	result = addElement(&space, 10);
	result = addElement(&space, 20);
	result = addElement(&space, 11);
	visualize(space);
	return 0;
}
