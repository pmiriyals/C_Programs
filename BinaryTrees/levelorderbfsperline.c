#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* nn(int data)
{
	struct node* cur = malloc(sizeof(struct node));
	cur->data = data;
	cur->left = NULL;
	cur->right = NULL;
}

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return nn(data);
	else
	{
		if(node->data >= data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		return node;
	}
}

struct node* buildtree(int num)
{
	int i;
	struct node* root = NULL;

	for(i = 1; i<= num; i++)
	{
		root = insert(root, rand()%(num+10));
	}
	return root;
}

struct node** createQueue(int size)
{
	return malloc(sizeof(struct node*) * size);
}

void enQueue(struct node** queue, int* rear, struct node* node)
{
	queue[(*rear)++] = node;	
}

struct node* deQueue(struct node** queue, int* front)
{
	return queue[(*front)++];
}

void inorder(struct node* node)
{
	if(node== NULL)
		return;

	inorder(node->left);
	printf(" %d ", node->data);
	inorder(node->right);
}

void levelorder(struct node* node)
{
	struct node** queue = createQueue(10);

	int front = 0, rear = 0;
	int levelnodes = 1;
	int numnodes, i;

	struct node* cur = node;

	printf(" %d ", cur->data);
	struct node* dummy;
	while(cur != NULL)
	{
		printf("\n");
		dummy = cur;
		numnodes = levelnodes;
		levelnodes = 0;

		for(i = 0; i<numnodes && cur != NULL; i++)
		{
			if(cur->left)
			{
				enQueue(queue, &rear, cur->left);
				levelnodes++;
				printf(" %d ", cur->left->data);
			}
			if(cur->right)
			{
				enQueue(queue, &rear, cur->right);
				levelnodes++;
				printf(" %d ", cur->right->data);
			}
			cur = deQueue(queue, &front);
		}
		if(dummy == cur)
			cur = deQueue(queue, &front);

	}	
}

void main()
{
	struct node* node = buildtree(10);
//	inorder(node);
	levelorder(node);
}
