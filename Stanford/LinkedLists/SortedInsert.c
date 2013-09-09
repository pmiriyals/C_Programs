#include<stdio.h>
#include "Util.h"

void SortedInsert(struct node** headRef, struct node* nn)
{
	if(*headRef == NULL || (*headRef)->data >= nn->data)
	{
		nn->next = *headRef;
		*headRef = nn;
	}
	else
	{
		struct node* cur = *headRef;
		int i = 0;
		while(cur->next != NULL && cur->next->data < nn->data)
		{
			cur = cur->next;
		}
		nn->next = cur->next;
		cur->next = nn;
	}
}

void InsertSort(struct node** headRef)
{
	struct node* result = NULL;
	struct node* cur = *headRef;
	struct node* temp;
	while(cur != NULL)
	{
		temp = cur->next;
		SortedInsert(&result, cur);
		cur = temp;
	}
	*headRef = result;
}

void main()
{

	struct node* head = PushAtHead(10);
	PrintList(head);
	InsertSort(&head);
	PrintList(head);
	DeleteList(&head);
}
