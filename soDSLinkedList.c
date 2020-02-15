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

	Node* new_node = soDSPrepareNode(linkedList->Typesize);
	memcpy(new_node->Data, pVal, linkedList->Typesize);

	if (NULL == linkedList->head) {
		return soDSLinkedListAddAtBeginning(linkedList, pVal);
	}

	linkedList->tail->Next = new_node;
	new_node = linkedList->tail;

	return TRUE;
}

int main() {

	soDSLinkedList ll;
	ll = soDSLinkedListInit(sizeof(int));

	int val = 5;
	int val1 = 6;
	int val2 = 7;
	soDSLinkedListAddAtBeginning(ll, &val);
	soDSLinkedListAddAtBeginning(ll, &val1);
	soDSLinkedListAddAtEnd(ll, &val2);

	int a,b,f;
	void* c = &b;
	void* d = &a;
	void* g = &f;
	memcpy(c,ll->head->Data,sizeof(int));
	memcpy(d, ll->head->Next->Data, sizeof(int));
	memcpy(g, ll->head->Next->Next->Data, sizeof(int));
	printf("%d->%d->%d",b, a, f);

	return 0;
}