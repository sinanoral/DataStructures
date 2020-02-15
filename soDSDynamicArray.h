#ifndef SODSDYNAMICARRAY_H_
#define SODSDYNAMICARRAY_H_

#include <stddef.h>
#include "soDSGeneral.h"

#define DEFAULT_CAPACITY 10

typedef struct _soDSDynamicArray* soDSDynamicArray;

soDSDynamicArray soDSDynamicArrayInit(size_t Typesize, size_t Capacity);
soDSDynamicArray soDSDynamicArrayFastInit(size_t Typesize);
void soDSDynamicArrayDestroy(soDSDynamicArray dynamicArray);
BOOL soDSDynamicArrayAdd(soDSDynamicArray dynamicArray, const void* pVal);
BOOL soDSDynamicArrayInsert(soDSDynamicArray dynamicArray, size_t index, const void* pVal);
BOOL soDSDynamicArrayRemoveAt(soDSDynamicArray dynamicArray, size_t index);
void soDSDynamicArraySort(soDSDynamicArray dynamicArray, int sortingFunc);
void soDSDynamicArrayClear(soDSDynamicArray dynamicArray);
void soDSDynamicArrayGetItem(soDSDynamicArray dynamicArray, size_t index, void* pVal);
void soDSDynamicArraySetItem(soDSDynamicArray dynamicArray, const void* pVal, size_t index);
void* soDSDynamicArrayGetArray(soDSDynamicArray dynamicArray);
size_t soDSDynamicArrayGetSize(soDSDynamicArray dynamicArray);
size_t soDSDynamicArrayGetCapacity(soDSDynamicArray dynamicArray);

#endif