#include<stdio.h>
#include "Util.h"

void main()
{
	struct node* a = BuildList();
	struct node* b = PushAtTailbyTail(1);
	MoveNode(&a, &b);
	puts("\nList a = ");
	PrintList(a);
	puts("\nList b = ");
	PrintList(b);
	DeleteList(&a);
	DeleteList(&b);
}
