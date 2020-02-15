#ifndef SODSLINKEDLIST_H
#define SODSLINKEDLIST_H

#include "soDSGeneral.h"

typedef struct _soDSLinkedList* soDSLinkedList;

soDSLinkedList soDSLinkedListInit(size_t Typesize);
BOOL soDSLinkedListAddAtBeginning(soDSLinkedList linkedList, const void* pVal);

#endif 
