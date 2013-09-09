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

void insert(struct node** node, int data)
{
	struct node* temp = nn(data);
	if(*node == NULL)
	{
		*node = temp;
		return;
	}
	struct node* cur = *node;
	struct node* prev;
	while(cur != NULL)
	{
		prev = cur;
		if(cur->data >= data)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if(prev->data < data)
		prev->right = temp;
	else
		prev->left = temp;	
}

void nl()
{
	printf("\n");
}

struct node* buildtree(int n)
{
	int i = 0;
	int num;
	int* arr = calloc(20, sizeof(int));
	struct node* root = NULL;	
	printf("\n Building tree with node = ");
	while(i<n)
	{
		num = rand()%20;
		if(!arr[num])
		{
			arr[num] = 1;
			insert(&root, num);
			printf(" %d ", num);
			i++;	
		}
	}
	nl();
	return root;
}

//using a linked list for stack, where data is 
//a reference to node in the tree
struct stack{
	struct node* t;
	struct stack* next;
};

//push to stack using 3 step linkage
void push(struct stack** stk, struct node* node)
{
	struct stack* temp = malloc(sizeof(struct stack));
	if(temp == NULL)
	{
		printf("\n stack overflow");
		return;
	}
	temp->t = node;
	temp->next = *stk;
	*stk = temp;
}

struct node* pop(struct stack** stk)
{
	if(*stk == NULL)
	{
		printf("\n stack underflow\n");
		return NULL;	
	}
	struct stack* cur = *stk;
	struct node* res = cur->t;
	*stk = cur->next;
	free(cur);
	return res;
}

//O(n)
void preorderrecur(struct node* node)
{
	if(node == NULL)
		return;
	printf(" %d ", node->data);
	preorderrecur(node->left);
	preorderrecur(node->right);
}

//O(n)
void preorderiter(struct node* node)
{
	if(node == NULL) return;
	struct stack* stk = NULL;
	int done = 0;
	push(&stk, node);
	while(!done)
	{
		node = pop(&stk);
		if(node != NULL)
		{			
			printf(" %d ", node->data);
			if(node->right != NULL)
				push(&stk, node->right);
			if(node->left != NULL)
				push(&stk, node->left);		
		}
		else
			done = 1;
	}
}

void main()
{
	struct node* node = buildtree(12);
	printf("\n preorder recur = ");
	preorderrecur(node);
	printf("\n preorder iter = ");
	preorderiter(node);
	nl();
}
