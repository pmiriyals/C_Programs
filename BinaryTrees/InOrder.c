#include<stdio.h>
#include "util.h"
#include<stdlib.h>


void push(struct stack** stk, struct node* node)
{
	struct stack* res = malloc(sizeof(struct stack));
	if(res == NULL)
	{
		printf("\n Stack overflow");
		return;
	}
	res->t = node;
	res->next = (*stk);
	(*stk) = res;
}

struct node* pop(struct stack** stk)
{
	if(*stk == NULL)
	{
		printf("\n stack underflow");
		return NULL;
	}
	struct node* top = (*stk)->t;
	struct stack* temp = (*stk)->next;
	free(*stk);
	*stk = temp;
	return top;
}

//O(n) but uses extra space (stack)
void InOrderTraversalIterUsingStack(struct node* node)
{
	if(node == NULL)
		return;

	struct stack* stk = NULL;
	struct node* cur = node;
	int done = 0;

	while(!done)
	{
		if(cur != NULL)
		{
			push(&stk, cur);
			cur = cur->left;
		}
		else
		{
			cur = pop(&stk);
			if(cur != NULL)
			{
				printf(" %d ", cur->data);
				cur = cur->right;
			}
			else
				done = 1;
		}
	}
	
}

//O(n) efficient Iterative traversal based on Morris's threaded binary tree
void InOrderMorrisTraversalIterWithoutUsingStack(struct node* node)
{
	if(node == NULL)
		return;
	
	struct node* pre = NULL;
	struct node* cur = node;

	while(cur != NULL)
	{
		if(cur->left == NULL)
		{
			printf(" %d ", cur->data);
			cur = cur->right;
		}
		else
		{
			pre = cur->left;	//find the predecessor of current node (right most node in the left sub tree)

			while(pre->right != NULL && pre->right != cur)
			{
				pre = pre->right;
			}
	
			if(pre->right == NULL)
			{
				pre->right = cur;	//link predecessor's right to current
				cur = cur->left;
			}
			else if(pre->right == cur)	//revert back the link
			{
				pre->right = NULL;
				printf(" %d ", cur->data);
				cur = cur->right;
			}
		}
	}
}

//O(n) but creates stack frames
void InOrderTraversalUsingRecursion(struct node* node)
{
	if(node == NULL)
		return;

	InOrderTraversalUsingRecursion(node->left);
	printf(" %d ", node->data);
	InOrderTraversalUsingRecursion(node->right);
}

//O(h) where h is the height of the BST
int InOrderSuccessorOfBSTusingParentPtr(struct node* node)
{
	if(node == NULL)
		return;
	if(node->right)
		return minVal(node->right);
	else
	{
		struct node* p = node->parent;
		while(p!= NULL && node== p->right)
		{
			node = p;
			p = node->parent;
		}

		return p->data;
	}
	return -1;
}

//O(h)
//if a node has a right sub tree, inorder successor will be left most child of the right sub tree
//If not, then this has to be a left node, the successor is the closest ancestor v such that this node is a decendent of the left child of v
int InOrderSuccessorOfBST(struct node* root, struct node* node)
{
	if(root == NULL)
		return -1;
	
	struct node* cur = root;
	struct node* succ = NULL;

	while(cur != NULL)
	{
		if(node->right)
		{
			return minVal(node->right);	
		}
		else
		{
			if(cur->data > node->data)	
			{
				succ = cur;
				cur = cur->left;
			}
			else if(cur->data < node->data)
			{
				cur = cur->right;		
			}
			else
				break;
		}
	}
	if(succ)
		return succ->data;
	else
		return -1;
}

//O(h)
//if node (n) has left child, then predecessor of n is the right most child of the left sub tree
// Else, predecessor of n is the ancestor vertex v such that n is the decendent of right child of v
int InOrderPredecessorBSTIter(struct node* root, struct node* node)
{
	if(node == NULL || root == NULL)
		return -1;

	if(node->left != NULL)
	{
		return maxVal(node->left);
	}
	
	struct node* pre = NULL;
	while(root != NULL)
	{
		if(root->data < node->data)
		{
			pre = root;
			root = root->right;
		}
		else if(root->data > node->data)
		{
			root = root->left;
		}
		else
			break;
	}
	if(pre)
		return pre->data;
	else
		return -1;
}

int InOrderPredecessorParentPtr(struct node* node)
{
	if(node == NULL)
		return -1;
	if(node->left)
		return maxVal(node->left);

	struct node* p = node->parent;
	while(p!= NULL && node == p->left)
	{
		node = p;
		p = node->parent;
	}
	if(p)
		return p->data;
	else
		return -1;
}



