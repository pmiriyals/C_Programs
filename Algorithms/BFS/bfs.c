#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	int visited;
	struct node** next;
};

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

struct node** createQueue()
{
	return (struct node**) malloc(sizeof(struct node*) * 500);
}

void enQueue(struct node** queue, int* rear, struct node* node)
{
	queue[(*rear)++] = node;
}

struct node* deQueue(struct node** queue, int* front)
{
	return queue[(*front)++];
}

int BFS(struct node* start, int v)
{
	int rear = 0, front = 0;
	struct node** queue = createQueue();

	start->visited = 1;	//mark the root (start) node as visited before adding it to the queue
//	enQueue(queue, &rear, start);	//enQueue the root node (start) of the graph

	struct node* cur = start;
	int i = 0;

	while(cur != NULL)
	{

		if(cur->vertex == v) //check if this is the index we are searching for
		{
			return 1;
		}

		while(cur->next != NULL && cur->next[i] != NULL)
		{					
			if(!cur->next[i]->visited)
			{
				cur->next[i]->visited = 1; //mark the node before enQueueing
				enQueue(queue, &rear, cur->next[i]);								
			}
			i++;
		}

		cur = deQueue(queue, &front);	//Remove the next vertex in the Queue
		i = 0;	//reset index
	}
	return 0;	//if reached here, vertex not found
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

//	printf("\n BFS(30) = %s\n", BFS(node, 30) ? "Vertex found" : "Vertex not found");
	printf("\n DFSRecur(40) = %s\n", DFSRecur(node, 40) ? "Vertex found" : "Vertex not found");
	return 0;
}
