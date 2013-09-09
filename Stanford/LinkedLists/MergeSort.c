#include<stdio.h>
#include "Util.h"

void MergeSort(struct node** headref)
{
	if(*headref == NULL || (*headref)->next == NULL)
		return;

	struct node* head = *headref;
	struct node* a = NULL;
	struct node* b = NULL;

	FrontBackSplit(&a, &b, head);

	MergeSort(&a);
	MergeSort(&b);
	*headref = SortedMerge(a, b);	
}

void main()
{
	struct node* head = BuildList();
	MergeSort(&head);
	PrintList(head);
	DeleteList(&head);
}
