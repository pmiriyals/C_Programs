#include<stdio.h>
#include "Util.h"

struct node* SortedIntersect(struct node* a, struct node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	struct node dummy;
	dummy.next = NULL;
	struct node* tail = &dummy;

	while(a != NULL && b != NULL)
	{
		if(a->data == b->data)
		{
			Push(&(tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if(a->data < b->data)
		{
			a = a->next;
		}
		else
		{
			b = b->next;
		}
	}
	return dummy.next;
}

void main()
{
	struct node* a = BuildList();
	struct node* b = PushAtTailbyTail(5);
	PrintList(b);
	struct node* result = SortedIntersect(a, b);
	PrintList(result);
}
