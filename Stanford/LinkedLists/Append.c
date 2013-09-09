#include<stdio.h>
#include "Util.h"

void Append(struct node** aRef, struct node** bRef)
{
	if(*aRef == NULL)
	{
		*aRef = *bRef;
		*bRef = NULL;
		return;
	}

	struct node* cur = *aRef;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = *bRef;
	*bRef = NULL;
}

void main()
{
	struct node* a = PushAtHead(10);
	PrintList(a);
	struct node* b = PushAtHead(5);
	PrintList(b);
	Append(&a, &b);
	PrintList(a);
	PrintList(b);
	DeleteList(&a);
	DeleteList(&b);
}
