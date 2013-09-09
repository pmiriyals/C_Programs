#include<stdio.h>
#include "util.h"

//LINKED LIST SORTING

void fbsplit(struct node* src, struct node** aref, struct node** bref)
{
	int l = size(src);	
	int mid;
	if(l%2)
		mid = (l+1)/2;
	else
		mid = l/2;

	struct node* temp = src;
	*aref = temp;

	while(mid > 1 && temp)
	{
		temp = temp->next;
		mid--;
	}
	*bref = temp->next;
	temp->next = NULL;
}

struct node* sortnmerge(struct node* a, struct node* b)
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

void MergeSort(struct node** aref)
{
	struct node* head = *aref;
	if(head == NULL || head->next == NULL)
		return;
	
	struct node* a = NULL;
	struct node* b = NULL;

	fbsplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*aref = sortnmerge(a, b);
}

void reverse(struct node** aref)
{
	if(*aref == NULL)
		return;

	struct node* prev = NULL;
	struct node* cur = *aref;
	struct node* next;
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;		
	}	
	*aref = prev;
}

void revrecur(struct node** aref)
{
	struct node* first;
	struct node* rest;

	if(*aref == NULL)
		return;

	first = *aref;
	rest = first->next;

	if(rest == NULL)
		return;

	revrecur(&rest);

	first->next->next = first;
	first->next = NULL;
	
	*aref = rest;	
}
