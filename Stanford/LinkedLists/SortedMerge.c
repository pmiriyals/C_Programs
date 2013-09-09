#include<stdio.h>
#include "Util.h"



void main()
{
	struct node* a = BuildList();
	struct node* b = PushAtTailbyTail(5);

	a = SortedMerge(a, b);
	PrintList(a);
}
