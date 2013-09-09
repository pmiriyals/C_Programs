#include<stdio.h>
#include<stdlib.h>
#include "Util.h"

void PopNode(struct node* temp)
{
	printf("\n deleting node %d\n", temp->data);
	free(temp);
}

void RemoveDuplicates(struct node* head)
{
	if(head == NULL)
		return;

	struct node* cur = head;
	struct node* nextN = cur->next;
	while(nextN != NULL)
	{
		if(cur->data == nextN->data)
		{
			cur->next = nextN->next;
			PopNode(nextN);
			nextN = cur->next;
		}
		else
		{
			cur = cur->next;
			nextN = nextN->next;
		}
	}
}

void main()
{
	struct node* head = BuildList();	
	RemoveDuplicates(head);
	PrintList(head);
	DeleteList(&head);
}
