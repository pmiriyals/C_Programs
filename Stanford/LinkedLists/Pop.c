#include<stdio.h>
#include "Util.h"

void main()
{
	struct node* head = PushAtTailbyLocalRef(10);
	while(head != NULL)
	{
		Pop(&head);	
	}
}
