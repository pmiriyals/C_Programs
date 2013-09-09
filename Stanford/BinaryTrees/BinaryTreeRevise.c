#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* nn = malloc(sizeof(struct node));
	nn->left = NULL;
	nn->right = NULL;
	nn->data = data;
}

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return newNode(data);
	else
	{
		if(node->data >= data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
	return node;
}

int size(struct node* node)
{
	if(node == NULL)
		return 0;
	else
	{
		return sizeof(node->left) + 1 + sizeof(node->right);
	}
}

int minVal(struct node* node)
{
	if(node == NULL)
		return -1;

	while(node->left != NULL)
		node = node->left;
	return node->data;
}

int hasPathSum(struct node* node, int sum)
{
	if(node == NULL)
		return sum == 0;
	else
	{
		int subSum = sum - node->data;
	
		return hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum);
	}
}

void printArray(int path[], pathLen)
{
	while(pathLen-- > 0)
	{
		printf(" %d ", path[pathLen]);
	}
	print("\n");
}

void printPaths(struct node* node, int path[], int pathLen)
{
	if(node == NULL)
		return;

	path[pathLen] = node->data;
	pathLen++;
	if(node->left == NULL && node->right == NULL)
		printArray(path, pathLen);
	else {
		printPaths(node->left, path, pathLen);
		printPaths(node->right, path, pathLen);
	}
}

void printPreOrder(struct node* node)
{
	if(node == NULL)
		return;
	printf(" %d ", node->data);
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void printInOrder(struct node* node)
{
	if(node == NULL)
		return;
	printInOrder(node->left);
	printf(" %d ", node->data);
	printInOrder(node->right);
}

void printPostOrder(struct node* node)
{
	if(node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	printf(" %d ", node->data);


}

int maxDepth(struct node* node)
{
	if(node == NULL)
		return 0;

	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if(lDepth > rDepth)
			return (lDepth+1);
		else
			return rDepth;
	}
}

void doubleTree(struct node* node)
{
	if(node == NULL)
		return;
	else
	{
		doubleTree(node->right);
		doubleTree(node->left);
		struct node* oldLeft = node->left;
		node->left = newNode(node->data);
		node->left->left = oldLeft;
	}
}

int sameTree(struct node* a, struct node* b)
{
	if(a== NULL && b==NULL)
		return 1;
	else if(a != NULL && b!= NULL)
	{
		return (a->data == b->data) && sameTree(a-left, b->left) && sameTree(a->rigth, b->right);
	}
	return 0;
}

struct node* mirror(struct node* node)
{
	if(node == NULL)
		return NULL;
	mirror(node->left);
	mirror(node->right);

	struct node* temp = node->left;
	node->left = node->right;
	node->right = temp;
}

int countTrees(int numKeys)
{
	if(numKyes <= 1)
		return 1;
	else {
		int left, right, root;
		int sum = 0;
		left = countTrees(root-1);
		right = countTrees(numKeys - root);
		sum += left*right;
	}
	return sum;
}

int isBST1(struct node* node)
{
	if(node == NULL)
		return 1;

	if(node->left != NULL && node->data < maxValue(node->left))
		return 0;

	if(node->right != NULL && node->data >= maxValue(node->righ))
		return 0;

	if(!isBST1(node->left) || !isBST1(node->right))
		return 0;

	return 1;	
}

int isBST(struct node* node, int min, int max)
{
	if(node == NULL)
		return 1;

	if(node->data < min || node->data >= max)
		return 0;

	return isBST(node->left, min, node->data) && isBST(node->right, node->data, max);
}

