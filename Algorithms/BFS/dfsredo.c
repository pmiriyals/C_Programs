#include<stdio.h>
#include<stdlib.h>

struct node
{
	int vertex;
	int visited;
	struct node** next;	
};

struct node** createList(int size)
{
	return malloc(sizeof(struct node*) * size);
}

struct node* nn(int vertex)
{
	struct node* node = malloc(sizeof(struct node));
	node->vertex = vertex;
	node->visited = 0;
	node->next = NULL;
	return node;
}

struct stack
{
	struct node* t;
	struct stack* next;
};

void push(struct stack** stk, struct node* node)
{
	struct stack* cur = malloc(sizeof(struct stack));
	if(cur == NULL)
	{
		printf("\nstack overflow");
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
	struct node* node = cur->t;
	free(cur);
	return node;
}

int dfs(struct node* start, int key)
{
	struct node* node = start;
	struct stack* stk = NULL;
	node->visited = 1;

	while(node != NULL)
	{
		printf("\n\nnode being processed = %d", node->vertex);
	
		if(node->vertex == key)
			return 1;

		printf("\npush to stack = ");
		int i = 0;
		while(node->next != NULL && node->next[i] != NULL)
		{
			if(!node->next[i]->visited)
			{
				push(&stk, node->next[i]);
				node->next[i]->visited = 1;
				printf(" %d ", node->next[i]->vertex);
			}
			i++;
		}
		node = pop(&stk);
	}
	return 0;
}

void main()
{
	struct node* start = nn(0);
	start->next = createList(5);

	struct node* n1 = nn(1);
	n1->next = createList(5);
	
	start->next[0] = n1;	//0-1

	struct node* n2 = nn(7);
	n2->next = createList(5);

	start->next[1] = n2;	//0-7
	n1->next[0] = n2;	//1-7
	

	struct node* n3 = nn(2);
	n3->next = createList(5);
	
	n1->next[1] = n3;	//1-2
	n1->next[2] = start;	//1-0
	n2->next[0] = start;	//7-0
	n2->next[1] = n1;	//7-1

	struct node* n4 = nn(8);
	n4->next = createList(5);

	n2->next[2] = n4;	//7-8
	n3->next[0] = n1;	//2-1
	n3->next[1] = n4;	//2-8
	n4->next[0] = n3;

	struct node* n5 = nn(6);
	n5->next = createList(5);

	n4->next[1] = n5;	//8-6
	n5->next[0] = n4;	//6-8
	n5->next[1] = n2;	//6-7
	n2->next[3] = n5;	//7-6

	struct node* n6 = nn(5);
	n6->next = createList(5);

	n6->next[0] = n3;
	n3->next[2] = n6;
	n6->next[1] = n5;
	n5->next[2] = n6;

	struct node* n7 = nn(3);
	n7->next = createList(5);
	n7->next[0] = n3;
	n3->next[3] = n7;
	n7->next[1] = n6;
	n6->next[2] = n7;
	
	struct node* n8 = nn(4);
	n8->next = createList(5);
	n8->next[0] = n7;
	n7->next[2] = n8;
	n8->next[1] = n6;
	n6->next[3] = n8;

	printf("\nDFS(start, key) = %s\n", dfs(start, 20) ? "Key Found" : "Key not found");
}
