#include<stdio.h>
#include "Util.h"

void main()
{
	struct node* head = PushAtTailbyTail(10);
	PrintList(head);
	Reverse(&head);
	PrintList(head);
}
