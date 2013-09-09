#include<stdio.h>
#include<stdlib.h>
#include "util.h"

//LINKED LIST BASICS STANFORD

struct node* NN(int data)
{
	struct node* nn = malloc(sizeof(struct node));
	nn->data = data;
	nn->next = NULL;
}

// Insertion O(1) (constant time)
void push(struct node** head, int data)
{
//3 step link
	struct node* temp = NN(data);
	temp->next = *head;
	*head = temp;
}

//O(1)
int pop(struct node** head)
{
	if(*head == NULL)
		return -1;

	int data = (*head)->data;
	struct node* temp = (*head)->next;
	free(*head);
	*head = temp;
	return data;
}

void nl()
{
	printf("\n");
}

int size(struct node* head)
{
	int cnt = 0;
	while(head != NULL)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}

void randomVal(int len, int* arr)
{
	int i = 1;
	printf("\n Random values being generated: ");
	while(i <= len)
	{
		arr[i-1] = rand()%(len+20);
		printf(" %d ", arr[i-1]);
		i++;
	}
	nl();
}

struct node* buildlistathead(int len)
{
	int vals[len];
	randomVal(len, vals);

	struct node* head = NULL;	
	int i = 0;
	printf("\n list built at head: ");
	for(i = 0; i< len; i++)
	{
		push(&head, vals[i]);
	}
	printList(head);
	nl();
	return head;
}

struct node* buildlistattailbylocalref(int len)
{
	struct node* head = NULL;
	struct node** localRef = &head;
	int i;
	int vals[len];
	randomVal(len, vals);

	printf("\nList built at tail by using local reference: ");
	for(i = 0; i< len; i++)
	{
		push(localRef, vals[i]);
		localRef = & ((*localRef)->next);
	}
	printList(head);
	nl();
	return head;
}

//O(n)
void appendnode(struct node** head, int num)
{
	if(*head == NULL)
	{
		push(head, num);
		return;
	}

	struct node* cur = *head;
	while(cur->next != NULL)
		cur = cur->next;

	push(&(cur->next), num);
	printf("\n List after appending node is: ");
	printList(*head);
}

struct node* buildlistattailbydummy(int len)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* tail = &dummy;
	int vals[len];
	randomVal(len, vals);
	printf("\n built list at tail by using a dummy node: ");
	int i;
	for(i = 0; i< len; i++)
	{
		push(&(tail->next), vals[i]);
		tail = tail->next;	
	}
	printList(dummy.next);
	nl();
	return dummy.next;
}

//O(n)
void printList(struct node* head)
{
	if(head == NULL)
		return;

	printf("\n List is: ");
	while(head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
	
}

//Delete O(n) for n nodes
void DeleteList(struct node** head)
{
	struct node* cur = *head;
	struct node* temp;
	printf("\nDeleting List: \n");
	while(cur != NULL)
	{
		printf(" %d ", cur->data);
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*head = cur;
}
