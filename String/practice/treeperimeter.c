#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* neighbor;
};

struct node* nn(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->neighbor = NULL;
}

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return nn(data);
	else{
		if(node->data < data)
			node->right = insert(node->right, data);
		else
			node->left = insert(node->left, data);
	}
	return node;
}

void printinorder(struct node* node)
{
	if(node == NULL)	return;

	printinorder(node->left);
	printf(" %d ", node->data);
	printinorder(node->right);
}

void printLeft(struct node* node)
{
	if(node == NULL && (node->left == NULL && node->right == NULL))
		return;

	if(node->left)
	{
		printf(" %d ", node->data);
		printLeft(node->left);
	}
	else if(node->right)
	{
		printf(" %d ", node->data);
		printLeft(node->right);
	}
}

void printLeaf(struct node* node)
{
	if(node == NULL)
		return;

	printLeaf(node->left);
	printLeaf(node->right);
	if(node->left == NULL && node->right == NULL)
		printf(" %d ", node->data);
}

void printRight(struct node* node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return;

	if(node->right)
	{
		printRight(node->right);
		printf(" %d ", node->data);
	}
	else if(node->left)
	{
		printRight(node->left);
		printf(" %d ", node->data);
	}
}

void printPerimeter(struct node* node)
{
	printf("\n Perimeter = %d", node->data);
	printLeft(node->left);
	printLeaf(node->left);
	printLeaf(node->right);
	printRight(node->right);
	printf("\n");
}

void main()
{
	struct node* node = NULL;
	int i;
	printf("\n generating nodes = ");
	for(i = 1; i < 20; i+=2)
	{
		int num = rand()%20;	
		printf(" %d ", num);
		node = insert(node, num);
	}

	printf("\n inorder = ");
	printinorder(node);
	printPerimeter(node);
}
