#include<stdio.h>
#include<stdlib.h>
#include "Util.h"

struct node* newNode(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = data;
}

void Push(struct node** head, int data)
{
	struct node* temp = newNode(data);
	temp->next = *head;
	*head = temp;
}

int len(struct node* head)
{
	struct node* cur = head;
	int len = 0;
	while(cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

void PrintList(struct node* head)
{
	if(head == NULL)
		return;
	while(head != NULL)
	{
		printf(" %d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct node* BuildList()
{
	int num;	
	printf("Build List. Enter list elements:\n");	
	struct node* head = NULL;
	while((num = getchar()) != 'q')
	{
		putchar(num);		
		Push(&head, (num-'0'));
	}

	printf("\nList built is: ");
	PrintList(head);
	return head;
}

struct node* PushAtHead(int numNodes)
{
	struct node* head = NULL;
	int i = 1;
	while(i < numNodes)
	{
		Push(&head, i++);
	}
	return head;
}

struct node* PushAtTailbyTail(int numNodes)
{
	struct node* head = NULL;
	Push(&head, 1);
	struct node* tail = head;

	int i = 2;
	while(i < numNodes)
	{
		Push(&(tail->next), i++);
		tail = tail->next;
	}
	return head;
}

struct node* PushAtTailbyLocalRef(int numNodes)
{
	struct node* head = NULL;
	struct node** localRef = &head;
	
	int i = 1;
	while(i < numNodes)
	{
		Push(localRef, i++);
		localRef = &((*localRef)->next);
	}
	return head;
}

struct node* PushAtTailbyDummy(int numNodes)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* tail = &dummy;

	int i = 1;
	while(i < numNodes)
	{
		Push(&(tail->next), i++);
		tail = tail->next;
	}
	return dummy.next;
}

void MoveNode(struct node** a, struct node** b)
{
	if(*b == NULL)
		return;
	struct node* cur = *b;
	*b = (*b)->next;
	cur->next = *a;
	*a = cur;
}

void Pop(struct node** head)
{
	if(*head == NULL)
		return;
	struct node* cur = (*head)->next;
	printf("\nPopping %d\n", (*head)->data);
	free(*head);
	*head = cur;
	printf("\nList after popping is = \n");
	PrintList(*head);
}

void DeleteList(struct node** head)
{
	struct node* cur = *head;
	struct node* temp = cur;
	printf("\nDeleting List: \n");

	while(cur != NULL)
	{
		temp = temp->next;
		printf(" Deleting %d ", cur->data);
		free(cur);
		cur = temp;
	}
	*head = NULL;
}

void FrontBackSplit(struct node** front, struct node** back, struct node* lst)
{
	if(lst == NULL)
		return;
	int size = len(lst);
	int blen = size/2;
	int flen = size-blen;

	struct node* flst = lst;

	struct node* prev;

	while(flen > 0 && flst != NULL)
	{
		prev = flst;
		flst = flst->next;
		flen--;
	}
	if(flen == 0)
	{
		prev->next = NULL;
		*front = lst;
		*back = flst;
	}
	else
	{
		*front = NULL;
		*back = NULL;
	}
}

struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = NULL;

	while(1)
	{
		if(a == NULL)
		{
			tail->next = b;
			break;
		}
		else if(b == NULL)
		{
			tail->next = a;
			break;
		}
		else
		{
			if(a->data <= b->data)
			{
				MoveNode(&(tail->next), &a);
			}
			else
			{
				MoveNode(&(tail->next), &b);
			}
			tail = tail->next;
		}
	}
	return dummy.next;
}

void Reverse(struct node** href)
{
	if(*href == NULL)
		return;
	struct node* cur = *href;
	struct node* prev = NULL;
	struct node* nn;

	while(cur != NULL)
	{
		nn = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nn;
	}
	*href = prev;
}
