#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int data)
{
	struct node* temp = NULL;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void Push(struct node** head, int data)
{		
	struct node* temp = newNode(data);
	temp->next = *head;
	*head = temp;
}

struct node* AddAtTail()
{
	struct node* head = newNode(1);
	int i  = 2;
	struct node* tail = head;

	while(i < 6)
	{
		Push(&(tail->next), i++);
		tail = tail->next;		
	}
	return head;
}

struct node* AddAtHead()
{
	struct node* head = NULL;
	int i = 0;
	while(i < 6)
	{
		Push(&head, i++);
	}
	return head;
}

int ListLen(struct node* head)
{
	if(head == NULL)
		return 0;
	int len = 0;
	while(head != NULL)
	{
		head = head->next;
		len++;
	}
	return len;
}

struct node* BuildList()
{
	struct node* head = newNode(0);
	struct node* temp = head;
	int i = 1;
	while(i < 5)
	{
		temp->next = newNode(i);
		temp = temp->next;
		i++;
	}
	return head;
}

struct node* BuildOneTwoThree()
{
	struct node* head = NULL;
	head = malloc(sizeof(struct node));
	head->data = 1;
	head->next = malloc(sizeof(struct node));
	head->next->data = 2;
	head->next->next = malloc(sizeof(struct node));
	head->next->next->data = 3;
	head->next->next->next = NULL;	
	return head;
}

void PrintList(struct node* head)
{
	if(head == NULL)
		return;
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void DeleteList(struct node* head)
{
	if(head == NULL)
		return;
	struct node* temp = NULL;
	while(head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

void main()
{	
	struct node* head = AddAtTail();
	printf("List len = %d\n", ListLen(head));
	PrintList(head);
	DeleteList(head);
}
