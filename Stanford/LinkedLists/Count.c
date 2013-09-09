#include<stdio.h>
#include<stdlib.h>
#include "Util.h"

int Count(struct node* head, int key)
{
	if(head == NULL)
		return 0;
	struct node* cur = head;
	int cnt = 0;	
	while(cur != NULL)
	{
		if(cur->data == key)
			cnt++;
		cur = cur->next;
	}

	return cnt;
}

void main()
{
	int num;
	struct node* head = NULL;

	head = BuildList();

	printf("\nEnter key = ");
	scanf("%d", &num);
	printf("\nCount of key = %d\n", Count(head, num));
}
