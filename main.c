#include <stdlib.h>
#include <stdio.h>
#include "soDSDynamicArray.h"


int main() {

	soDSDynamicArray* da;
	if (NULL == (da = soDSDynamicArrayFastInit(sizeof(int)))) {
		exit(0);
	}

	int i;

	for (i = 0; i < 10; i++)
	{
		soDSDynamicArrayAdd(da, &i);
	}

	soDSDynamicArrayPrint(da);

	int val = 1000;
	soDSDynamicArrayInsert(da, 5, &val);
	soDSDynamicArrayPrint(da);

	soDSDynamicArrayRemoveAt(da, 5);
	soDSDynamicArrayPrint(da);

	soDSDynamicArrayDestroy(da);
	getchar();
	return 0;
}