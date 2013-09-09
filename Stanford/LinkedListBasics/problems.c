#include<stdio.h>
#include<math.h>
#include "util.h"

//LINKED LIST PROBLEMS (STANFORD)

int getnth(struct node* head, int n)
{
	if(head == NULL)
		return -1;

	int i = 1;
	while(head != NULL)
	{
		if(i == n)
			return head->data;
		i++;
		head = head->next;
	}
	return -1;
}

void insertnth(struct node** headRef, int data, int ndx)
{
	if(ndx == 0)
		push(headRef, data);
	else{
		int i = 0;
		struct node* cur = (*headRef);
		while(cur != NULL && i < ndx-1)
		{
			cur = cur->next;
			i++;
		}
		push(&(cur->next), data);
	}
}

void sortedinsert(struct node** headRef, struct node* nn)
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

void frontbacksplit(struct node* src, struct node** f, struct node** b)
{
	int len = size(src);
	if(len < 2)
		return;

	int mid = ceil(len/2);
	*f = src;
	struct node* front = *f;
	int i = 0;
	while(i < mid)
	{
		front = front->next;
	}
	*b = front->next;
	front->next = NULL;
}

void movenode(struct node** src, struct node**destn)
{
	if(*src == NULL)
		return;

	struct node* temp = *src;
	struct node* next = temp->next;

	temp->next = *destn;
	*destn = temp;
	*src = next;
}

//using movenode
void alternatingsplit(struct node* src, struct node** aref, struct node** bref)
{
	if(src == NULL)
		return;
	struct node* a = NULL;
	struct node* b = NULL;
	while(src != NULL)
	{
		movenode(&src, &a);
		if(src != NULL)
			movenode(&src, &b); 
	}
	*aref = a;
	*bref = b;
}

struct node* sortedmerge(struct node* a, struct node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	struct node* result = NULL;
	if(a->data <= b->data)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return result;
}

void mergesort(struct node** aref)
{
	struct node* a = *aref;

	if(a == NULL || (a)->next == NULL)
		return;

	struct node* x = NULL;
	struct node* y = NULL;

	frontbacksplit(a, &x, &y);

	mergesort(&x);
	mergesort(&y);
	printf(" \n x = %d\n", x->data);
	*aref = sortedmerge(x, y);
}

struct node* shufflemerge(struct node** aref, struct node** bref)
{
	if(*aref == NULL)
		return *bref;
	if(*bref == NULL)
		return *aref;

	struct node dummy;
	dummy.next = NULL;
	struct node* res =  &dummy;
	struct node* a = *aref;
	struct node* b = *bref;
	struct node* next;
	while(a && b)
	{
		next = a->next;
		a->next = NULL;
		res->next = a;
		res = res->next;
		a = next;
		next = b->next;
		b->next = NULL;
		res->next = b;
		res = res->next;
		b = next;
	}
	if(a)
	{
		res->next = a;
	}
	if(b)
	{
		res->next = b;
	}
	*aref = NULL;
	*bref = NULL;
	return dummy.next;
}

void asplit(struct node* src, struct node** aref, struct node** bref)
{
	if(src == NULL)
		return;

	int i = 1;
	struct node* temp = src;
	struct node* next = NULL;
	struct node* a = NULL;
	struct node* b = NULL;

	while(temp != NULL)
	{

		next = temp->next;

		if(i % 2)
		{
			temp->next = a;
			a = temp;
		}
		else
		{
			temp->next = b;
			b = temp;
		}
		temp = next;	
		i++;		
	}

	*aref = a;
	*bref = b;
}



