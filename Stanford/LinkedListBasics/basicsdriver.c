#include<stdio.h>
#include "util.h"

void main()
{
	struct node* head = NULL;

	head = buildlistathead(10);

	struct node* a = NULL;
	struct node* b = NULL;

	fbsplit(head, &a, &b);
	printf("\nlist a = ");
	printList(a);
	printf("\nlist b = ");
	printList(b);

	struct node* res = sortnmerge(a, b);
	printList(res);
	printf("\nmerge sort  = ");
	MergeSort(&res);
	printList(res);
	reverse(&res);
	printf("\nafter reversing = ");
	printList(res);

	revrecur(&res);
	printf("\nrevrecur list = ");
	printList(res);
}
