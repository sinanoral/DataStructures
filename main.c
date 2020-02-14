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

void print(soDSDynamicArray da) {
	int val;

	for (size_t i = 0; i < soDSDynamicArrayGetSize(da); i++) {
		soDSDynamicArrayGetItem(da, i, &val);
		printf("%d ", val);
	}
	printf("\n----------------------------------\n");
}

int main() {

	soDSDynamicArray da;
	if (NULL == (da = soDSDynamicArrayFastInit(sizeof(int)))) {
		exit(0);
	}

	int i;

	for (i = 10; i > 0; i--)
	{
		soDSDynamicArrayAdd(da, &i);
	}

	print(da);
	int val = 1000;
	soDSDynamicArrayInsert(da, 5, &val);
	print(da);
	
	soDSDynamicArrayRemoveAt(da, 5);
	print(da);

	//soDSDynamicArraySort(da,myfunc);
	//soDSDynamicArrayPrint(da);

	soDSDynamicArrayDestroy(da);
	
	return 0;
}