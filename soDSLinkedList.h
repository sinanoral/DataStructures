#ifndef SODSLINKEDLIST_H
#define SODSLINKEDLIST_H

#include "soDSGeneral.h"

typedef struct _soDSLinkedList* soDSLinkedList;

soDSLinkedList soDSLinkedListInit(size_t Typesize);
BOOL soDSLinkedListAddAtBeginning(soDSLinkedList linkedList, const void* pVal);
BOOL soDSLinkedListAddAtEnd(soDSLinkedList linkedList, const void* pVal);
BOOL soDSLinkedListInsert(soDSLinkedList linkedList, size_t index, const void* pVal);
//BOOL soDSLinkedListRemoveAt(soDSLinkedList linkedList, size_t index);
BOOL soDSLinkedListRemoveFromBeginning(soDSLinkedList linkedList);
BOOL soDSLinkedListRemoveFromEnd(soDSLinkedList linkedList);
BOOL soDSLinkedListIsEmpty(soDSLinkedList linkedList);
//void soDSLinkedListGetItem(soDSLinkedList linkedList, Node* node, void* pVal);

#endif 
