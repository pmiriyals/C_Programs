#include<stdio.h>
#include<stdlib.h>
#include "Util.h"

void main()
{
	struct node* head = PushAtHead(5);
	PrintList(head);

	struct node* tail = PushAtTailbyTail(3);
	PrintList(tail);

	struct node* tailbyRef = PushAtTailbyLocalRef(4);
	PrintList(tailbyRef);

	struct node* tailbyDummy = PushAtTailbyDummy(6);
	PrintList(tailbyDummy);
	
	getchar();

	DeleteList(&head);
	DeleteList(&tail);
	DeleteList(&tailbyRef);
	DeleteList(&tailbyDummy);
}
