#include<stdio.h>
#include<stdlib.h>
#include "util.h"

struct node* NN(int data)
{
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
}

//O(log n) -> to insert 1 node in BST
struct node* insert(struct node* root, int data)
{
	if(root == NULL)
	{
		return NN(data);
	}
	
	if(root->data >= data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;
}

void nl()
{
	printf("\n");
}

//O(h)
int minVal(struct node* node)
{
	if(node == NULL)
		return 0;

	while(node->left != NULL)
		node = node->left;

	return node->data;
}

//O(h)
int maxVal(struct node* node)
{
	if(node == NULL)
		return 0;
	while(node->right != NULL)
		node = node->right;
	return node->data;
}

int size(struct node* node)
{
	if(node == NULL)
		return 0;

	return (size(node->left) + 1 + size(node->right));
}

//O(n log n) -> to build a BST = n* insert each node in a tree (log n)
struct node* BuildRandomBSTHelper()
{
	int num = 0;
	int* arr = calloc(31, sizeof(int));

	struct node* root = NULL;
	printf("\nRandom values = ");
	while(num++ < 20)
	{
		int val = rand() % 30;
		if(!arr[val])
		{
			printf(" %d ", val);
			root = insert(root, val);
			arr[val] = 1;
		}		
	}	
	return root;
}
