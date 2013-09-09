#include<stdio.h>
#include "Util.h"



void main()
{
	struct node* front = NULL;
	struct node* back = NULL;
	struct node* lst1 = PushAtTailbyLocalRef(5);
	puts("\nList 1 = ");
	PrintList(lst1);
	FrontBackSplit(&front, &back, lst1);
	puts("\nFront list = ");
	PrintList(front);
	puts("\nBack list = ");
	PrintList(back);
	struct node* lst2 = PushAtTailbyLocalRef(3);
	puts("\nList 2 = ");
	PrintList(lst2);
	FrontBackSplit(&front, &back, lst2);
	puts("\nFront list = ");
	PrintList(front);
	puts("\nBack list = ");
	PrintList(back);

	struct node* lst3 = PushAtTailbyLocalRef(4);
	puts("\nList 3 = ");
	PrintList(lst3);
	FrontBackSplit(&front, &back, lst3);
	puts("\nFront list = ");
	PrintList(front);
	puts("\nBack list = ");
	PrintList(back);

}
