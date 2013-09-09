#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* nn(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node** rref, int data)
{
	if(*rref == NULL)
	{
		*rref = nn(data);
		return;
	}

	struct node* cur = *rref;
	struct node* prev = NULL;
	while(cur != NULL)
	{
		prev = cur;
		if(cur->data < data)
			cur = cur->right;
		else
			cur = cur->left;
	}

	if(prev->data < data)
		prev->right = nn(data);
	else
		prev->left = nn(data);
}

struct node* buildTree(int n)
{
	int num, i= 0;
	int* a = calloc(20, sizeof(int));
	struct node* root = NULL;
	printf("\n values being inserted = ");
	while(i < n)
	{
		num = rand()%20;
		if(!a[num])
		{
			insert(&root, num);
			a[num] = 1;
			printf(" %d ", num);
			i++;
		}
	}
	printf("\n");
	return root;
}

void distance(struct node* node, int data, int dist)
{
	if(node == NULL)
		return ;

	if(node->data == data)
	{
		printf("\n distance = %d\n", dist);
		return;
	}

	distance(node->left, data, dist+1);
        distance(node->right, data, dist+1);
}

int maxDepth(struct node* node)
{
	if(node == NULL)
		return 0;

	int lDepth = maxDepth(node->left);
	int rDepth = maxDepth(node->right);

	if(lDepth > rDepth)
		return lDepth+1;
	else
		return rDepth+1;
}

void printlevel(struct node* node, int n)
{
	if(node == NULL)
		return;
	if(n == 0)
	{
		printf(" %d ", node->data);
		return;
	}

	printlevel(node->left, n-1);
	printlevel(node->right, n-1);
}

void printlevelorder(struct node* node)
{
	int h = maxDepth(node);
	printf("\n height of tree = %d\n", h);
	int i;
	for(i = 0; i< h; i++)
	{
		printlevel(node, i);
		printf("\n");
	}
}


void main()
{
	struct node* node = buildTree(10);
	printf("\n level order of tree = ");
	printlevelorder(node);

	distance(node, 15, 0);
}


