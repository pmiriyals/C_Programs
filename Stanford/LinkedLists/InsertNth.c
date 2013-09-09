#include<stdio.h>
#include "Util.h"

void InsertNth(struct node** head, int ndx, int data)
{
	if(ndx == 0)
	{
		Push(head, data);
	}
	else
	{
		int i = 0;
		struct node* cur = *head;
		for(i = 0; i < ndx -1; i++)
		{
			cur = cur->next;
		}
		if(cur != NULL)
		{
			Push(&(cur->next), data);
		}
	}
}

void main()
{
	struct node* head = NULL;

	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	PrintList(head);
}
