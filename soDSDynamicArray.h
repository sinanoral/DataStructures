#ifndef SODSDYNAMICARRAY_H_
#define SODSDYNAMICARRAY_H_

#include <stddef.h>

#define FALSE 0
#define TRUE  1

#define DEFAULT_CAPACITY 5

typedef int BOOL;

typedef struct _soDSDynamicArray {
	void* pArray;
	size_t Typesize;
	size_t Size;
	size_t Capacity;
}soDSDynamicArray;

soDSDynamicArray* soDSDynamicArrayInit(size_t Typesize, size_t Capacity);
soDSDynamicArray* soDSDynamicArrayFastInit(size_t Typesize);
void soDSDynamicArrayDestroy(soDSDynamicArray* dynamicArray);
BOOL soDSDynamicArrayAdd(soDSDynamicArray* dynamicArray, const void* pVal);
BOOL soDSDynamicArrayInsert(soDSDynamicArray* dynamicArray, size_t index, const void* pVal);
BOOL soDSDynamicArrayRemoveAt(soDSDynamicArray* dynamicArray, size_t index);
void soDSDynamicArrayClear(soDSDynamicArray* dynamicArray);
void soDSDynamicArrayGetItem(soDSDynamicArray* dynamicArray, size_t index, void* pVal);
void soDSDynamicArraySetItem(soDSDynamicArray* dynamicArray, const void* pVal, size_t index);
BOOL soDSDynamicArraySetCapacity(soDSDynamicArray* dynamicArray, size_t index);
void* soDSDynamicArrayGetArray(soDSDynamicArray* dynamicArray);
size_t soDSDynamicArrayGetSize(soDSDynamicArray* dynamicArray);
size_t soDSDynamicArrayGetCapacity(soDSDynamicArray* dynamicArray);
void soDSDynamicArrayPrint(soDSDynamicArray* soDSDynamicArray);

#endif