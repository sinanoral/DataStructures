#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "soDSDynamicArray.h"

static BOOL soDSDynamicArraysetCapacity(soDSDynamicArray* dynamicArray, size_t Capacity, size_t index);

soDSDynamicArray* soDSDynamicArrayInit(size_t Typesize, size_t Capacity) {

	soDSDynamicArray* dynamicArray;

	if (NULL == (dynamicArray = (soDSDynamicArray*)malloc(sizeof(soDSDynamicArray)))) {
		return NULL;
	}

	if (NULL == (dynamicArray->pArray = malloc(Typesize * Capacity))) {
		free(dynamicArray);
		return NULL;
	}

	dynamicArray->Typesize = Typesize;
	dynamicArray->Capacity = Capacity;
	dynamicArray->Size = 0;

	return dynamicArray;

}

soDSDynamicArray* soDSDynamicArrayFastInit(size_t Typesize) {
	return soDSDynamicArrayInit(Typesize, DEFAULT_CAPACITY);
}

void soDSDynamicArrayDestroy(soDSDynamicArray* dynamicArray) {
	free(dynamicArray->pArray);
	free(dynamicArray);
}

BOOL soDSDynamicArrayAdd(soDSDynamicArray* dynamicArray, const void* pVal) {

	if (NULL == dynamicArray->pArray) {
		return FALSE;
	}

	if (dynamicArray->Size == dynamicArray->Capacity &&
		!soDSDynamicArraysetCapacity(dynamicArray, dynamicArray->Capacity * 2, dynamicArray->Size)) {
		return FALSE;
	}

	memcpy((char*)dynamicArray->pArray + dynamicArray->Typesize * dynamicArray->Size, pVal, dynamicArray->Typesize);
	++dynamicArray->Size;

	return TRUE;
}

BOOL soDSDynamicArrayInsert(soDSDynamicArray* dynamicArray, size_t index, const void* pVal) {

	if (index > dynamicArray->Size) {
		return FALSE;
	}

	char* pSrc = (char*)dynamicArray->pArray + dynamicArray->Typesize * index;
	char* pDst = (char*)dynamicArray->pArray + dynamicArray->Typesize * (index + 1);

	if (dynamicArray->Size == dynamicArray->Capacity &&
		!soDSDynamicArraysetCapacity(dynamicArray, dynamicArray->Capacity * 2, index)) {
		return FALSE;
	}

	
	memmove(pDst, pSrc, (dynamicArray->Size - index) * dynamicArray->Typesize);
	memcpy(pSrc, pVal, dynamicArray->Typesize);
	++dynamicArray->Size;

	return TRUE;
}

BOOL soDSDynamicArrayRemoveAt(soDSDynamicArray* dynamicArray, size_t index) {
	
	if (index >= dynamicArray->Size) {
		return FALSE;
	}

	char* pDst = (char*)dynamicArray->pArray + (dynamicArray->Typesize * index);
	char* pSrc = (char*)dynamicArray->pArray + dynamicArray->Typesize * (index + 1);

	memmove(pDst, pSrc, (dynamicArray->Size - index) * dynamicArray->Typesize);
	--dynamicArray->Size;

	return TRUE;
}

void soDSDynamicArrayClear(soDSDynamicArray* dynamicArray) {
	dynamicArray->Size = 0;
}

void soDSDynamicArrayGetItem(soDSDynamicArray* dynamicArray, size_t index, void* pVal) {
	char* pSrc = (char*)dynamicArray->pArray + index * dynamicArray->Typesize;
	memcpy(pVal, pSrc, dynamicArray->Typesize);
}

void soDSDynamicArraySetItem(soDSDynamicArray* dynamicArray, const void* pVal, size_t index) {
	char* pDst = (char*)dynamicArray->pArray + index * dynamicArray->Typesize;
	memcpy(pDst, pVal, dynamicArray->Typesize);
}

void* soDSDynamicArrayGetArray(soDSDynamicArray* dynamicArray) {
	return dynamicArray->pArray;
}

size_t soDSDynamicArrayGetSize(soDSDynamicArray* dynamicArray) {
	return dynamicArray->Size;
}

size_t soDSDynamicArrayGetCapacity(soDSDynamicArray* dynamicArray) {
	return dynamicArray->Capacity;
}

BOOL soDSDynamicArraySetCapacity(soDSDynamicArray* dynamicArray, size_t Capacity) {
	
	if (Capacity < dynamicArray->Size) {
		return FALSE;
	}

	if (Capacity != dynamicArray->Capacity) {
		return soDSDynamicArraysetCapacity(dynamicArray, Capacity, dynamicArray->Size);
	}

	return TRUE;
}

static BOOL soDSDynamicArraysetCapacity(soDSDynamicArray* dynamicArray, size_t Capacity, size_t index) {
	
	void* pTemp;

	if (index > dynamicArray->Size) {
		return FALSE;
	}

	pTemp = malloc(dynamicArray->Typesize * (Capacity >= DEFAULT_CAPACITY ? Capacity : DEFAULT_CAPACITY));

	if (NULL == pTemp) {
		return FALSE;
	}

	if (dynamicArray->Size) {
		memcpy(pTemp, dynamicArray->pArray, index * dynamicArray->Typesize);
		memcpy((char*)pTemp + (index + 1) * dynamicArray->Typesize,
			(char*)dynamicArray->pArray + index * dynamicArray->Typesize,
			(dynamicArray->Size - index) * dynamicArray->Typesize);
	}

	free(dynamicArray->pArray);
	dynamicArray->pArray = pTemp;
	dynamicArray->Capacity = Capacity >= DEFAULT_CAPACITY ? Capacity : DEFAULT_CAPACITY;

	return TRUE;
}

void soDSDynamicArrayPrint(soDSDynamicArray* dynamicArray) {
	size_t i;
	int val;
	for (i = 0; i < soDSDynamicArrayGetSize(dynamicArray); i++) {
		soDSDynamicArrayGetItem(dynamicArray, i, &val);
		printf("%d ", val);
	}

	printf("\nSize = %lu, Capacity = %lu\n",
		(unsigned long)soDSDynamicArrayGetSize(dynamicArray), (unsigned long)soDSDynamicArrayGetCapacity(dynamicArray));

	printf("---------------------------------------\n");
}
