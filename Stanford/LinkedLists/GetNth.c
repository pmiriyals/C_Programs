#include<stdio.h>
#include "Util.h"

int GetNth(struct node* head, int ndx)
{
	if(head == NULL || ndx >= len(head))
		return -1;
	struct node* cur = head;
	while(cur != NULL && ndx--)
	{
		cur = cur->next;
	}
	return cur->data;
}

void main()
{
	struct node* head = PushAtTailbyTail(10);

	int ndx;
	scanf("%d", &ndx);
	PrintList(head);
	printf("\nData at %d is  = %d\n", ndx, GetNth(head, ndx));
}
