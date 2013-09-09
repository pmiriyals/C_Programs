#include<stdio.h>
#include<stdlib.h>
#include "util.h"

struct node* nn(int data)
{
	struct node*  newNode = malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

void nl()
{
	printf("\n");
}

//O(1)
void push(struct node** node, int data)
{
	struct node* temp = nn(data);
	temp->next = *node;
	*node = temp;
}

int* builduniqueEle(int numEle)
{
	int* cnt = calloc(numEle+21, sizeof(int));
	int* arr = malloc(sizeof(int) * numEle);
	int num = 0;
	int i = 0;
	printf("\n Generating unique elements = ");
	while(i < numEle)
	{
		num = rand() % (numEle + 20);		
		if(!cnt[num])
		{
			cnt[num] = 1;
			arr[i] = num;
			i++;		
			printf(" %d ", num);	
		}
	}
	nl();
	return arr;
}

//O(n)
void buildlistathead(struct node** head, int numEle)
{
	int* arr = builduniqueEle(numEle);
	struct node* node = NULL;
	int ndx = 0;
	while(ndx < numEle)
	{
		push(&node, arr[ndx]);
		ndx++;
	}
	*head = node;
}

//O(n)
struct node* buildlistattailbydummy(int numEle)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* local = &dummy;
	int* arr = builduniqueEle(numEle);
	int ndx = 0;
	while(ndx < numEle)
	{
		push(&(local->next), arr[ndx]);
		ndx++;
		local = local->next;
	}
	return dummy.next;
}

//O(n)
struct node* buildlistattailbyref(int numEle)
{
	struct node* head = NULL;
	struct node** localRef = &head;
	int ndx = 0;
	int* arr = builduniqueEle(numEle);

	while(ndx < numEle)
	{
		push(localRef, arr[ndx++]);
		localRef = &((*localRef)->next);
	}
	return head;
}

//O(n)
int listlen(struct node* node)
{
	int cnt = 0;
	while(node != NULL)
	{
		node = node->next;
		cnt++;
	}
	printf("\nList length = %d\n", cnt);
	return cnt;
}

//O(n)
void printlist(struct node* node, char* s)
{
	printf("\nList %s = ", s);
	while(node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
	nl();
}

//O(n) interate till nth position
void insertnth(struct node** node, int n, int data)
{
	if(n == 0)
	{
		push(node, data);
	}
	else
	{
		struct node* temp = *node;
		int ndx = 0;
		while(ndx < (n-1) && temp != NULL)
		{
			temp = temp->next;
			if(temp == NULL)
			{
				printf("\n index out of bounds\n");
				return;
			}
			ndx++;
		}
		push(&(temp->next), data);
	}
}

int pop(struct node** node)
{
	int num = (*node)->data;
	struct node* temp = *node;
	*node = temp->next;
	free(temp);
	printf("\n popped node = %d\n", num);
	return num;
}

//O(n)
void sortedinsert(struct node** node, struct node* newNode)
{
	struct node dummy;
	dummy.next = *node;
	struct node* cur = &dummy;
	while(cur->next != NULL && cur->next->data < newNode->data)
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;
	*node = dummy.next;
}

//O(n)
void insertsort(struct node** href)
{
	struct node* cur = *href;
	struct node* result = NULL;
	struct node* next;

	while(cur != NULL)
	{
		next = cur->next;
		sortedinsert(&result, cur);
		cur = next;
	}
	*href = result;
}

//O(n)
void SortedInsertbydata(struct node** node, int data)
{
	struct node* temp = NULL;
	if(*node == NULL || (*node)->data > data)
	{
		temp = nn(data);
		temp->next = *node;
		*node = temp;
	}
	else
	{
		struct node* temp = *node;
		while(temp->next != NULL && temp->next->data < data)
		{
			temp = temp->next;
		}
		push(&(temp->next), data);
	}
}

//O(n)
void append(struct node** aref, struct node** bref)
{
	if(*aref == NULL)
	{
		*aref = *bref;
	}
	else
	{
		struct node* cur = *aref;
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = *bref;
	}
	*bref = NULL;
}

//O(n)
void frontbacksplit(struct node* node, struct node** front, struct node** back)
{
	struct node* next = node;
	struct node* prev = node;

	while(next != NULL)
	{
		next = next->next;
		if(next != NULL)
		{
			next = next->next;
			prev = prev->next;
		}
	}
	*back = prev->next;
	prev->next = NULL;
	*front = node;
}

//O(n)
void removeduplicates(struct node* node)
{
	if(node == NULL)
		return;
	struct node* next;
	while(node->next != NULL)
	{
		if(node->data == node->next->data)
		{
			next = node->next->next;
			free(node->next);
			node->next = next;
		}
		else
			node = node->next;
	}
}

//O(1)
void movenode(struct node** src, struct node** dest)
{
	struct node* node = *src;
	*src = (*src)->next;
	node->next = *dest;
	*dest = node;
}

void alternatingsplitinrev(struct node* src, struct node** aref, struct node** bref)
{
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* cur = src;

	while(cur != NULL)
	{
		movenode(&cur, &a);
		if(cur != NULL)
			movenode(&cur, &b);
	}
	*aref = a;
	*bref = b;
}

void alternatingsplit(struct node* src, struct node** aref, struct node** bref)
{
	struct node dummya;
	dummya.next = NULL;
	struct node* a = &dummya;
	
	struct node dummyb;
	dummyb.next = NULL;
	struct node* b = &dummyb;

	struct node* cur = src;
	while(cur != NULL)
	{
		movenode(&cur, &(a->next));
		a = a->next;
		if(cur != NULL)
		{
			movenode(&cur, &(b->next));
			b = b->next;
		}
	}
	*aref = dummya.next;
	*bref = dummyb.next;
}

struct node* buildlistinsortedorder(int numEle)
{
	int i = 0;
	struct node* head = NULL;
	struct node** localRef = &head;

	for(i = 0; i< numEle; i++)
	{
		push(localRef, i * 2);
		localRef = &((*localRef)->next);
	}
	return head;
}

//O(n) (linked list does not provide direct access of elements)
int getNth(struct node* node, int n)
{
	int cnt = 1;
	while(node != NULL)
	{
		if(cnt == n)
			return node->data;		
		node = node->next;
		cnt++;
	}
	return -1;
}

void deletelist(struct node** node)
{
	struct node* temp = *node;
	printf("\n Deleting list = ");
	struct node* next;
	while(temp != NULL)
	{
		printf(" %d ", temp->data);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*node = temp;
}
