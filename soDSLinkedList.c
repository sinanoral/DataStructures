#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soDSLinkedList.h"
#include "soDSGeneral.h"

typedef struct _soDSNode {
	
	void* Data;
	struct _soDSNode* Next;

}Node;

struct _soDSLinkedList {

	Node* head;
	Node* tail;
	size_t Typesize;
};

static Node* soDSPrepareNode(size_t Typesize) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->Data = malloc(Typesize);
	new_node->Next = NULL;

	return new_node;
}


soDSLinkedList soDSLinkedListInit(size_t Typesize) {

	soDSLinkedList linkedList;

	if (NULL == (linkedList = malloc(sizeof(struct _soDSLinkedList)))) {
		return NULL;
	}

	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->Typesize = Typesize;

	return linkedList;
}

BOOL soDSLinkedListAddAtBeginning(soDSLinkedList linkedList, const void* pVal) {
	
	Node* new_node = soDSPrepareNode(linkedList->Typesize);
	memcpy(new_node->Data, pVal, linkedList->Typesize);
	

	if (NULL == linkedList->head) {
		linkedList->head = new_node;
		linkedList->tail = new_node;
	}
	else{
		new_node->Next = linkedList->head;
		linkedList->head = new_node;
		new_node = linkedList->tail;
	}

	return TRUE;
}

BOOL soDSLinkedListAddAtEnd(soDSLinkedList linkedList, const void* pVal) {

	if (NULL == linkedList->head) {
		return FALSE;
	}

	Node* new_node = soDSPrepareNode(linkedList->Typesize);
	memcpy(new_node->Data, pVal, linkedList->Typesize);

	if (NULL == linkedList->head) {
		return soDSLinkedListAddAtBeginning(linkedList, pVal);
	}

	linkedList->tail->Next = new_node;
	new_node = linkedList->tail;

	return TRUE;
}

BOOL soDSLinkedListInsert(soDSLinkedList linkedList, size_t index, const void* pVal) {

	if (NULL == linkedList->head) {
		return FALSE;
	}

	Node* new_node = soDSPrepareNode(linkedList->Typesize);
	memcpy(new_node->Data, pVal, linkedList->Typesize);

	Node* temp, * previous = NULL;
	temp = linkedList->head;

	for (size_t i = 1; i < index; i++) {
		previous = temp;
		temp = temp->Next;
	}

	previous->Next= new_node;
	new_node->Next = temp;

	return TRUE;
}

void getitem(Node* a, void* val) {
	memcpy(val, a->Data, sizeof(int));
}

void print(soDSLinkedList ll) {

	int i;
	Node* temp;
	temp = ll->head;
	
	while (temp != NULL) 
	{
		getitem(temp, &i);
		printf("%d ", i);
		temp = temp->Next;
	}
}

int main() {

	soDSLinkedList ll;
	ll = soDSLinkedListInit(sizeof(int));

	int val = 5;
	int val1 = 6;
	int val2 = 7;
	int val3 = 11;
	int val4 = 13;
	soDSLinkedListAddAtBeginning(ll, &val);
	soDSLinkedListAddAtBeginning(ll, &val1);
	soDSLinkedListAddAtEnd(ll, &val2);
	soDSLinkedListAddAtBeginning(ll, &val3);
	soDSLinkedListInsert(ll, 2, &val4);

	print(ll);

	return 0;
}