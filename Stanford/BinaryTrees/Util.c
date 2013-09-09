#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* neighbor;
};

struct node* newNode(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->neighbor = NULL;
	temp->data = data;
	return temp;
}

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return newNode(data);
	else
	{
		if(data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
		return node;
	}
}

struct node* BuildTree(int numNodes)
{
	struct node* root = NULL;
	int i = 0;
	while(i < numNodes)
	{
		int data = rand() % 100;	
		printf("\n rand() = %d", data);
		root = insert(root, data);
		i++;
	}
	return root;
}

int minVal(struct node* node)
{
	if(node == NULL)
		return -1;
	while(node->left != NULL)
		node = node->left;
	return node->data;
}

int maxDepth(struct node* node)
{
	if(node == NULL) 	
		return 0;
	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
	
		if(lDepth > rDepth) return lDepth+1;
		else return rDepth+1;
	}
}

int size(struct node* root)
{
	if(root == NULL) return 0;

	return (size(root->left) + 1 + size(root->right));
}

void printPostOrder(struct node* node)
{
	if(node == NULL) return;

	printPostOrder(node->left);
	printPostOrder(node->right);
	printf(" %d ", node->data);
}

void printInOrder(struct node* node)
{
	if(node == NULL)
		return;

	printInOrder(node->left);
	printf(" %d ", node->data);
	printInOrder(node->right);
}

void PrintTree(struct node* root)
{
	printf("\nroot = %d", root->data);
	if(root->left != NULL)
		printf("\nleft = %d", root->left->data);
	if(root->right != NULL)
		printf("\nright = %d", root->right->data);
}

int hasPathSum(struct node* node, int sum)
{
	if(node == NULL)
		return (sum == 0);
	else
	{
		int subSum = sum - node->data;
		return hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum);
	}
}

void printArray(int path[], int len)
{
	int i;
	for(i = 0; i < len; i++)
		printf(" %d ", path[i]);
	putchar('\n');
}

void printPaths(struct node* node, int path[], int pathLen)
{
	if(node == NULL)
		return;

	path[pathLen] = node->data;
	pathLen++;
	
	if(node->left == NULL && node->right == NULL)
		printArray(path, pathLen);
	else
	{
		printPaths(node->left, path, pathLen);
		printPaths(node->right, path, pathLen);
	}

}

void doubleTree(struct node* node)
{
	struct node* oldLeft;

	if(node == NULL)
		return;

	doubleTree(node->left);
	doubleTree(node->right);

	oldLeft = node->left;
	node->left = newNode(node->data);
	node->left->left = oldLeft;
}

void mirror(struct node* node)
{
	if(node == NULL)
		return;

	struct node* temp;
	mirror(node->left);
	mirror(node->right);

	temp = node->left;
	node->left = node->right;
	node->right = temp;
}

int sameTrees(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return 1;
	else if(a != NULL && b!= NULL)
	{
		return (a->data == b->data) && sameTrees(a->left, b->left) && sameTrees(a->right, b->right);
	}	
	else
		return 0;
}

void printPerimeter(struct node* node, int* l, int* cnt)
{
	if(node == NULL)
		return;
	if(*l && (node->left != NULL || node->right != NULL))
	{
		printf(" %d - ", node->data);
	}
	else
	{
		*l = 0;
	}
	printPerimeter(node->left, l, cnt);
	printPerimeter(node->right, l, cnt);

	
	if((*cnt) == 0)
		printf(" %d - ", node->data);

	if(node->left == NULL && node->right == NULL)
	{
		printf(" %d - ", node->data);
		(--(*cnt));
	}
}

int countLeafNodes(struct node* node)
{
	if(node == NULL)
		return 0;

	if(node->left == NULL && node->right == NULL)
		return 1;
	return countLeafNodes(node->left) + countLeafNodes(node->right);
}

void printRevPostOrder(struct node* node)
{
	if(node == NULL)
		return;
	printf(" %d ", node->data);
	printRevPostOrder(node->right);
	printRevPostOrder(node->left);
}

void PostOrderPredecessor(struct node* node, int data, int* setPre)
{
	if(node == NULL)
		return;
	
	if(*setPre)
	{
		printf("predecessor = %d\n", node->data);
		exit(0);
	}	
	if(node->data == data)
	{
		*setPre = 1;
	}
	PostOrderPredecessor(node->right, data, setPre);
	PostOrderPredecessor(node->left, data, setPre);
}

int CeilSearchBST(struct node* node, int key)
{
	if(node == NULL)
		return -1;

	if(node->data < key)
		return CeilSearchBST(node->right, key);

	int ceil = CeilSearchBST(node->left, key);
	return (ceil >= key) ? key : node->data;
}

int leastCommonAncestor(struct node* node, int n1, int n2)
{
	if(node == NULL || node->data == n1 || node->data== n2)
		return -1;

	if(node->right != NULL && (node->right->data == n1 || node->right->data == n2)) 
		return node->data;

	if(node->left != NULL && (node->left->data == n1 || node->left->data == n2))
		return node->data;

	if((node->data > n1 && node->data < n2) || (node->data < n1 && node->data > n2))
		return node->data;

	if(node->data > n1 && node->data > n2)
		return leastCommonAncestor(node->left, n1, n2);
	if(node->data < n1 && node->data < n2)
		return leastCommonAncestor(node->right, n1, n2);
}

void printGivenLevel(struct node* node, int level)
{
	if(node == NULL)
		return;
	if(level == 1)
		printf(" %d ", node->data);
	else {
		printGivenLevel(node->left, level-1);
		printGivenLevel(node->right, level-1);
	}
}
//O(n2)
void printLevelOrder(struct node* node)
{
	int height = maxDepth(node);
	int i;
	for(i = 1; i<= height; i++)
	{
		printGivenLevel(node, i);
		printf("\n");
	}
}

struct node** createQueue()
{
	struct node** queue = malloc(sizeof(struct node*) * 500);
	return queue;
}

void enQueue(struct node** queue, int* rear, struct node* temp)
{
	queue[(*rear)++] = temp;
}

struct node* deQueue(struct node** queue, int* front)
{
	return queue[(*front)++];
}

//O(n)
void printLevelOrderQueue(struct node* node)
{
	if(node == NULL)
		return;
	int front = 0, rear = 0;
	struct node* temp = node;
	struct node** queue = createQueue();

	while(temp)
	{
		printf(" %d ", temp->data);
		
		if(temp->left)
			enQueue(queue, &rear, temp->left);
		if(temp->right)
			enQueue(queue, &rear, temp->right);

		temp = deQueue(queue, &front);
	}
}

int adj[20][20];

void InitializeAdjMatrix(int row, int col)
{
	int i, j;

	for(i = 0; i < row; i++)
		for(j = 0; j< col; j++)
			adj[i][j] = 0;

}

void printAdjMatrix(int row, int col)
{
	puts("   ");
	int i, j;
	for(i = 0; i < col; i++)
		printf(" %d ", i);
	putchar('\n');
	for(i = 0; i < row; i++)
	{
		printf(" %d ", i);
		for(j = 0; j < col; j++)
			printf(" %d ", adj[i][j]);
		putchar('\n');
	}
}

void BuildAdjacencyMatrix(struct node* node)
{
	if(node == NULL)
		return;

	if(node->left)
		adj[node->data][node->left->data] = 1;
	if(node->right)
		adj[node->data][node->right->data] = 1;
	BuildAdjacencyMatrix(node->left);
	BuildAdjacencyMatrix(node->right);	
}

//O(n)
void SetNeighbor(struct node* node)
{
	if(node == NULL)
		return;

	if(node->left && node->right)
		node->left->neighbor = node->right;

	if(node->neighbor && node->right && node->neighbor->left)
		node->right->neighbor = node->neighbor->left;

	SetNeighbor(node->left);
	SetNeighbor(node->right);
}

void initSetNeighbor(struct node* root)
{
	SetNeighbor(root);
	printf("\n 1 - %d", root->left->neighbor->data);
	printf("\n 6 - %d", root->right->left->neighbor->data);
	printf("\n 12 - %d", root->right->right->left->left->left->neighbor->data);
	printf("\n 6 - %s", root->right->neighbor==NULL ? "No neighbor" : "Neighbor exists");
}

//O(n)
void inorderRecur(struct node* node)
{
	if(node == NULL)
		return;

	inorderRecur(node->left);
	printf(" %d ", node->data);
	inorderRecur(node->right);
}

void nl(){printf("\n");}

struct stack{
	struct node* t;
	struct stack* next;
};

struct node* pop(struct stack** stk)
{
	if(*stk == NULL)
	{
		printf("\nStack underflow");
		return NULL;
	}
	struct node* temp = (*stk)->t;
	struct stack* topRef = *stk;
	*stk = (*stk)->next;
	free(topRef);
	return temp;
}

void push(struct stack** stk, struct node* node)
{
	struct stack* temp = malloc(sizeof(struct stack));

	if(temp == NULL)
	{
		printf("\nStack overflow");
		return;
	}

	temp->t = node;
	temp->next = *stk;
	*stk = temp;
}
//O(n)
void InOrderIterStack(struct node* node)
{
	if(node == NULL)
		return;

	int done = 0;
	struct stack* stk = NULL;
	struct node* cur = node;
	
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
			{
				done = 1;
			}
		}
	}
}

void main()
{
	int i;
	struct node* root = NULL;
	
	for(i=0; i < 10; i++)
	{
		int val = rand() % 20;
		printf(" %d ", val);
		root = insert(root, val);
	}
	nl();
	inorderRecur(root);
	nl();
	InOrderIterStack(root);
	nl();
}
