#include <stdlib.h>
#include <stdio.h>
#include "soDSDynamicArray.h"


int myfunc(const void* a, const void* b) {
	int* aa, *bb;
	int res;
	aa = (int*)a;
	bb = (int*)b;

	res = *aa - *bb;

	return res;
}

int main() {

	soDSDynamicArray* da;
	if (NULL == (da = soDSDynamicArrayFastInit(sizeof(int)))) {
		exit(0);
	}

	int i;

	for (i = 10; i > 0; i--)
	{
		soDSDynamicArrayAdd(da, &i);
	}

	soDSDynamicArrayPrint(da);

	int val = 1000;
	soDSDynamicArrayInsert(da, 5, &val);
	soDSDynamicArrayPrint(da);
	
	/*soDSDynamicArrayRemoveAt(da, 5);
	soDSDynamicArrayPrint(da);*/

	soDSDynamicArraySort(da,myfunc);
	soDSDynamicArrayPrint(da);

	soDSDynamicArrayDestroy(da);
	
	getchar();
	return 0;
}