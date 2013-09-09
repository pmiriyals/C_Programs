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

struct node* top(struct stack* stk)
{
	if(stk == NULL)
	{
		printf("\n stack underflow");
		return NULL;
	}
	return stk->t;
}

struct node* nn(int v)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->vertex = v;
	temp->visited = 0;
	temp->next = NULL;
}

struct node** createList(int size)
{
	return (struct node**) malloc(sizeof(struct node*) * size);
}

int DFSIter(struct node* node, int x)
{
	struct stack* stk = NULL;
	struct node* cur = node;

	cur->visited = 1;

	while(cur != NULL)
	{
//		printf("\ncur->vertex = %d\n", cur->vertex);
		if(cur->vertex == x)
			return 1;

		int ndx = 0;
		while(cur->next != NULL && cur->next[ndx] != NULL)
		{
//			printf("\ncur->next[ndx] = %d\tcur->next[ndx]->visited = %d\n", cur->next[ndx]->vertex, cur->next[ndx]->visited);
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

int DFSRecur(struct node* node, int v)
{
	if(node == NULL)
		return 0;

	printf(" %d ", node->vertex);
	node->visited = 1;

	if(node->vertex == v)
		return 1;
	int i = 0, res = 0;
	while(node->next != NULL && node->next[i] != NULL)
	{
		if(!node->next[i]->visited)
		{
			node->next[i]->visited = 1;
			res = DFSRecur(node->next[i], v);	
		}
		i++;
	}
	return res;
}

int main()
{
	struct node* node = nn(10);
	node->next = createList(5);
	
	struct node* node1 = nn(20);
	node1->next = createList(5);

	struct node* node2 = nn(30);
	node2->next = createList(5);

	struct node* node3 = nn(40);

	node->next[0] = node1;
	node->next[1] = node2;
//	node->next[2] = node3;

	node1->next[0] = node2;
	node1->next[1] = node3;

	node2->next[0] = node;

	printf("\n DFSIter(40) = %s\n", DFSIter(node, 40) ? "Vertex found" : "Vertex not found");
	//printf("\n DFSRecur(40) = %s\n", DFSRecur(node, 40) ? "Vertex found" : "Vertex not found");
	return 0;
}
