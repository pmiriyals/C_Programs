#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	int visited;
	struct node** next;
};

struct stack{
	struct node* t;
	struct stack* next;
};

void push(struct stack** stk, struct node* node)
{
	struct stack* cur = malloc(sizeof(struct stack));
	if(cur == NULL)
	{
		printf("\n stack overflow");
		return;
	}
	cur->t = node;
	cur->next = *stk;
	*stk = cur;
}

struct node* pop(struct stack** stk)
{
	if(*stk == NULL)
	{
		printf("\nstack underflow");
		return NULL;
	}
	struct stack* cur = *stk;
	*stk = cur->next;
	struct node* res = cur->t;
	free(cur);
	return res;
}

struct node** createList(int size)
{
	return (struct node**) malloc(sizeof(struct node*) * size);
}

struct node* nn(int data)
{
	struct node* cur = (struct node*) malloc(sizeof(struct node));
	cur->vertex = data;
	cur->visited = 0;
	cur->next = NULL;
	return cur;
}

int DFSIter(struct node* node, int x)
{
	struct stack* stk = NULL;
	struct node* cur = node;

	cur->visited = 1;

	while(cur != NULL)
	{
		printf("\ncur->vertex = %d\n", cur->vertex);
		if(cur->vertex == x)
			return 1;

		int ndx = 0;
		while(cur->next != NULL && cur->next[ndx] != NULL)
		{
			printf("\ncur->next[ndx] = %d\tcur->next[ndx]->visited = %d\n", cur->next[ndx]->vertex, cur->next[ndx]->visited);
			if(!cur->next[ndx]->visited)
			{
				cur->next[ndx]->visited = 1;
				push(&stk, cur->next[ndx]);
			}
			ndx++;
		}
		cur = pop(&stk);
	}
	return 0;
}

int DFSRecur(struct node* node, int x)
{
	if(node == NULL)
		return 0;
	
	if(node->vertex == x)
		return 1;

	node->visited = 1;

	int ndx = 0;
	int res = 0;

	while(node->next != NULL && node->next[ndx] != NULL)
	{
		
		if(!node->next[ndx]->visited)
		{
			node->next[ndx]->visited = 1;
			res = DFSRecur(node->next[ndx], x);
		}
		ndx++;
	}
	return res;
}

void main()
{
	struct node* start = nn(5);
	start->next = createList(5);
	
	struct node* node1 = nn(10);
	node1->next = createList(5);

	struct node* node2 = nn(15);
	node2->next = createList(5);

	struct node* node3 = nn(20);
	node3->next = createList(5);

	struct node* node4 = nn(25);
	node4->next = createList(5);

	start->next[0] = node1;
	start->next[1] = node2;
	start->next[2] = node3;
	start->next[3] = start;

	node1->next[0] = start;
	node1->next[1] = node2;

	node2->next[0] = node4;

//	printf("\n%s\n", DFSRecur(start, 2000) ? "Key Found" : "key not found");
	printf("\n%s\n", DFSIter(start, 200) ? "Key Found" : "key not found");
}


