#include<stdio.h>
#include "Util.h"

struct node* ShuffleMerge(struct node* a, struct node* b)
{
	if(b == NULL)
		return a;
	if(a == NULL)
		return b;

	struct node* cur = a;
	struct node* nxt;
	int i = 1;
	while(cur->next != NULL && b != NULL)
	{
		if(i%2)
		{
			nxt = cur->next;
			cur->next = b;
			b = b->next;
			cur = cur->next;
			cur->next = nxt;
		}
		else
			cur = cur->next;
		i++;
	}
	if(b != NULL)
		cur->next = b;
	return a;
}

void main()
{
	struct node* a = BuildList();
	struct node* b = PushAtTailbyTail(5);
	puts("\nList a = ");
	PrintList(a);
	puts("\nList b = ");
	PrintList(b);
	a = ShuffleMerge(a, b);
	puts("\nAfter merge = ");
	PrintList(a);
	DeleteList(&a);
}
