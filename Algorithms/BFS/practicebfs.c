#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	int visited;
	struct node** next;
};

struct node** createList(int size)
{
	return (struct node**) malloc(sizeof(struct node*) * size);
}

struct node* newNode(int v)
{
	struct node* nn = (struct node*) malloc(sizeof(struct node));
	nn->vertex = v;
	nn->visited = 0;
	nn->next = NULL;
}

void enQueue(struct node** queue, int* rear, struct node* node)
{
	queue[(*rear)++] = node;
}

struct node* deQueue(struct node** queue, int* front)
{
	return queue[(*front)++];
}

void BFS(struct node* node, int x)
{
	struct node** queue = createList(100);
	int front = 0, rear = 0;
	struct node* cur = node;
	cur->visited = 1;
	int ndx = 0;

	while(cur != NULL)
	{
		if(cur->vertex == x)
		{
			printf("\nKey found\n");
			return;
		}

		while(cur->next != NULL && cur->next[ndx] != NULL)
		{
			if(!cur->next[ndx]->visited)
			{
				enQueue(queue, &rear, cur->next[ndx]);
				cur->next[ndx]->visited = 1;
			}
			ndx++;
		}
		ndx = 0;
		cur = deQueue(queue, &front);
	}
	printf("\n key not found\n");
}

void main()
{
	struct node* start = newNode(5);
	start->next = createList(5);
	
	struct node* node1 = newNode(10);
	node1->next = createList(5);

	struct node* node2 = newNode(20);
	node2->next = createList(5);

	struct node* node3 = newNode(25);
	node3->next = createList(5);

	struct node* node4 = newNode(30);
	node4->next = createList(5);

	start->next[0] = node1;
	start->next[1] = node2;
	start->next[2] = node3;
	start->next[3] = start;

	node1->next[0] = start;
	node1->next[1] = node2;
	node1->next[2] = node3;

	node2->next[0] = node4;

	BFS(start, 300);
}
