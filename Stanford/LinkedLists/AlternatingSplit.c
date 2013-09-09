#include<stdio.h>
#include "Util.h"

void AlternatingSplit(struct node* head, struct node** aRef, struct node** bRef)
{
	if(head == NULL)
		return;

	struct node* cur = head;
	while(cur != NULL)
	{
		MoveNode(aRef, &cur);
		if(cur != NULL)	
			MoveNode(bRef, &cur);
	}
}

void main()
{
	struct node* head = PushAtTailbyTail(10);
	struct node* a = NULL;
	struct node* b = NULL;
	PrintList(head);

	AlternatingSplit(head, &a, &b);
	
	PrintList(a);
	PrintList(b);
}
