#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* nn(int data)
{
	struct node* cur = malloc(sizeof(struct node));
	cur->data = data;
	cur->next = NULL;
	return cur;
}

//at head
void push(struct node** href, int data)
{
	struct node* cur = nn(data);
	cur->next = *href;
	*href = cur;
}

struct node* buildlistathead(int n)
{
	int i;
	struct node* head = NULL;

	for(i = 1; i<= n; i++)
	{
		push(&head, i);
	}
	return head;
}

struct node* buildlistattail(int n)
{
	int i;
	struct node dummy;
	dummy.next = NULL;
	struct node* tail = &dummy;

	for(i = 1; i<= n; i++)
	{
		push(&(tail->next), i);
		tail = tail->next;
	}
	return dummy.next;
}

void print(struct node* head)
{
	printf("\nlist = ");
	while(head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}

int len(struct node* node)
{
	int cnt = 0;
	while(node != NULL)
	{
		cnt++;
		node = node->next;
	}
	return cnt;	
}

int getnth(struct node* node, int n)
{
	int i = 0;
	while(node != NULL)
	{
		if(i == n)
			return node->data;
		i++;
		node = node->next;
	}
	return -1;
}

void del(struct node** node)
{
	struct node* cur = *node;
	printf("\ndeleting list = ");
	struct node* next;
	while(cur != NULL)
	{
		next = cur->next;
		printf(" %d ", cur->data);
		free(cur);
		cur = next;
	}
	*node = NULL;
}

void insertnth(struct node** node, int data, int n)
{
	struct node dummy;
	dummy.next = *node;
	struct node* cur = &dummy;
	int i = 1;
	while(i < n-1)
	{
		
	}
}

struct node* rev(struct node* node)
{
	struct node* prev = NULL;
	struct node* next;

	while(node != NULL)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	return prev;
}

void revrecur(struct node** node)
{
	if(*node == NULL)
		return;

	struct node* first = *node;
	struct node* rest = first->next;

	if(rest == NULL)
		return;

	revrecur(&rest);

	first->next->next = first;
	first->next = NULL;

	*node = rest;
}

int getnthfromend(struct node* node, int n)
{
	struct node* fast = node;
	struct node* slow = node;
	int i = 1;

	while(fast != NULL)
	{
		if(i == n)
			break;
		i++;
		fast = fast->next;
	}

	if(fast == NULL)
		return -1;

	while(fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;

}

int getmiddle(struct node* node)
{
	if(node == NULL)
		return -1;

	struct node* fast = node;
	struct node* slow = node;
	while(fast->next != NULL)
	{
		fast = fast->next;
		if(fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	printf("\nmiddle = %d\n", slow->data);
	return slow->data;
}

void main()
{
	struct node* a = buildlistattail(10);
	struct node* b = buildlistathead(10);

	print(a);
	printf("\nlen(a) = %d\n", len(a));
	print(b);
	printf("\nlen(b) = %d\n", len(b));
	printf("\ngetnthfromend = %d\n", getnthfromend(a, 9));
	getmiddle(a);
}




