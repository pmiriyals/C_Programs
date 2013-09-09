#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "util.h"

struct node* nn(int data)
{
	struct node* newn = malloc(sizeof(struct node));
	newn->left = NULL;
	newn->right = NULL;
	newn->data = data;
	return newn;
}

void insertIter(struct node** nref, int data)
{
	struct node* temp = nn(data);

	if(*nref == NULL)
	{
		*nref = temp;
		return;
	}
	struct node* node = *nref;
	struct node* prev;
	while(node != NULL)
	{
		prev = node;
		if(node->data < data)
			node = node->right;
		else
			node = node->left;
	}
	if(prev->data >= data)
		prev->left = temp;
	else
		prev->right = temp;
}

struct node* insert(struct node* node, int data)
{
	if(node == NULL)
		return nn(data);
	else
	{
		if(node->data < data)
			node->right = insert(node->right, data);
		else
			node->left = insert(node->left, data);
		return node;
	}
}

struct node* buildTree(int size)
{
	int* cnt = calloc(size+21, sizeof(int));
	int num;
	int i = 0;
	struct node* root = NULL;
	printf("\n inserting following elements into tree = ");
	while(i < size)
	{
		num = rand() % (size+20);		
		if(!cnt[num])
		{
			cnt[num] = 1;
			i++;
			root = insert(root, num);
			printf(" %d ", num);
		}		
	}
	return root;
}

int size(struct node* node)
{
	if(node == NULL)
		return 0;

	return size(node->left) + 1 + size(node->right);
}

int maxDepth(struct node* node)
{
	if(node == NULL)
		return 0;

	int lDepth = maxDepth(node->left);
	int rDepth = maxDepth(node->right);

	if(lDepth > rDepth)
		return (lDepth+1);
	else
		return (rDepth+1);
}

int minValue(struct node* node)
{
	if(node == NULL) return -1;
	while(node->left != NULL)
		node = node->left;
	return node->data;
}

void printinorder(struct node* node)
{
	if(node == NULL) return;

	printinorder(node->left);
	printf(" %d ", node->data);
	printinorder(node->right);
}

void printpostorder(struct node* node)
{
	if(node == NULL)
		return;

	printpostorder(node->left);
	printpostorder(node->right);
	printf(" %d ", node->data);
}

void printpreorder(struct node* node)
{
	if(node == NULL)
		return;
	printf(" %d ", node->data);
	printpreorder(node->left);
	printpreorder(node->right);
}

int hasPathSum(struct node* node, int sum)
{
	if(node == NULL)
		return (sum == 0);
	else
	{
		int subsum = sum - node->data;
		return hasPathSum(node->left, subsum) || hasPathSum(node->right, subsum);
	}
}

void printpatharr(int* path, int len)
{
	int i;
	printf("\n path = ");
	for(i = 0; i< len; i++)
		printf(" %d ", path[i]);
}

void printPathsRecur(struct node* node, int* path, int pathLen)
{
	if(node == NULL)
		return;

	path[pathLen++] = node->data;
	if(node->left == NULL && node->right == NULL)
		printpatharr(path, pathLen);
	else
	{
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

void printPaths(struct node* node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

//O(n)
void mirror(struct node* node)
{
	if(node == NULL)
		return;
	
	mirror(node->left);
	mirror(node->right);
	struct node* temp = node->left;
	node->left = node->right;
	node->right = temp;
}
//O(n)
void doubleTree(struct node* node)
{
	if(node == NULL)
		return;

	doubleTree(node->left);
	doubleTree(node->right);

	struct node* oldLeft = node->left;	
	node->left = nn(node->data);
	node->left->left = oldLeft;
}

//O(n)
int sameTree(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return 1;
	else if(a != NULL && b != NULL)
		return (a->data == b->data) && sameTree(a->left, b->left) && sameTree(a->right, b->right);
	else
		return 0;
}

int countTrees(int numKeys)
{
	if(numKeys <= 1)
		return 1;
	else
	{
		int root, left, right, sum = 0;
		for(root = 1; root <= numKeys; root++)
		{
			left = countTrees(root-1);
			right = countTrees(numKeys-root);
			sum += left*root;
		}
		return sum;
	}
}

//O(n)
int isBST(struct node* node, int min, int max)
{
	if(node == NULL)
		return 1;

	if(node->data > max || node->data < min)
		return 0;

	return (isBST(node->left, min, node->data) && isBST(node->right, node->data+1, max));
}

//O(n)
//In-order traversal using a stack (iterative)
struct stack{
	struct node* t;
	struct stack* next;
};

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
		printf("\nstack underflow");
		return NULL;
	}
	struct node* node = (*stk)->t;
	*stk = (*stk)->next;
	return node;
}

void printinorderiterusingstack(struct node* node)
{
	if(node == NULL)
		return;

	struct node* cur = node;
	struct stack* stk = NULL;
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

//O(n)
void InorderTraversalWithoutStackIter(struct node* node)
{
	if(node == NULL)
		return;

	struct node* cur = node;
	struct node* pre = NULL;

	while(cur != NULL)
	{
		if(cur->left == NULL)
		{
			printf(" %d ", cur->data);
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur)
				pre = pre->right;
			if(pre->right == NULL)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				printf(" %d ", cur->data);
				cur = cur->right;
			}
		}
	}
}

//O(h)
int inordersuccofBST(struct node* root, struct node* node)
{
	if(node == NULL)
		return;
	if(node->right)
		return minValue(node->right);
	else
	{
		struct node* succ = NULL;
		while(root != NULL)
		{
			if(root->data > node->data)
			{
				succ = root;
				root = root->left;
			}
			else if(root->data < node->data)
				root = root->right;
			else
				break;
		}
		if(succ)
			return succ->data;
		else
			return -1;
	}
}

int maxVal(struct node* node)
{
	if(node == NULL)
		return -1;
	while( node->right)
		node = node->right;
	return node->data;
}
//O(n)
int inorderpred(struct node* root, struct node* node)
{
	if(node == NULL)
		return;
	if(node->left)
		return maxVal(node->left);
	else
	{
		struct node* pred = NULL;
		while(root != NULL)
		{
			if(root->data < node->data)
			{
				pred = root;
				root = root->right;
			}
			else if(root->data > node->data)
				root = root->left;
			else
				break;
		}
		if(pred)
			return pred->data;
		else
			return -1;
	}
}

//O(log n)
int lowestCommonAncestor(struct node* root, int v1, int v2)
{
	if(root == NULL || root->data == v1 || root->data ==v2)
		return -1;

	if(root->right != NULL && (root->right->data == v1 || root->right->data == v2))
		return root->data;
	
	if(root->left != NULL && (root->left->data == v1 || root->left->data == v2))
		return root->data;	

	if((root->data > v1 && root->data < v2) || (root->data < v1 && root->data > v2))
		return root->data;

	if(root->data < v1 && root->data < v2)
		return lowestCommonAncestor(root->right, v1, v2);
	else
		return lowestCommonAncestor(root->left, v1, v2);
}

//O(h)
void preorderIterUsingStack(struct node* node)
{
	if(node == NULL)
		return;
	struct node* cur = node;
	struct stack* stk = NULL;
	push(&stk, cur);
	int done = 0;
	while(!done)
	{
		cur = pop(&stk);
		if(cur != NULL)
		{
			printf(" %d ", cur->data);
			if(cur->right != NULL)
				push(&stk, cur->right);
			if(cur->left != NULL)
				push(&stk, cur->left);
		}
		else
			done = 1;
	}
}

//O(h)
void postorderIter(struct node* node)
{
	if(node == NULL)
		return;

	struct node* cur = node;
	struct stack* stk = NULL;
	struct stack* res = NULL;
	push(&stk, cur);
	int done = 0;
	while(!done)
	{
		cur = pop(&stk);
		if(cur != NULL)
		{
			push(&res, cur);
			if(cur->left != NULL)
				push(&stk, cur->left);
			if(cur->right != NULL)
				push(&stk, cur->right);
		}
		else
			done = 1;
	}
	cur = pop(&res);
	while(cur != NULL)
	{
		printf(" %d ", cur->data);
		cur = pop(&res);
	}
}

//Level Order Traversal using Queues

struct node** createQueue()
{
	return malloc(sizeof(struct node*) * 500);
}

void enQueue(struct node** queue, int* rear, struct node* node)
{
	queue[(*rear)++] = node;
}

struct node* deQueue(struct node** queue, int* front)
{
	return queue[(*front)++];
}
//O(n) (Bread First Search approach)
void levelOrderTraversal(struct node* node)
{
	if(node == NULL)
		return;
	struct node* cur = node;
	struct node** queue = createQueue();
	int front = 0, rear = 0;
	while(cur)
	{
		printf(" %d ", cur->data);
		if(cur->left)
			enQueue(queue, &rear, cur->left);
		if(cur->right)
			enQueue(queue, &rear, cur->right);
		cur = deQueue(queue, &front);
	}
}

void printgivenlevel(struct node* node, int level)
{
	if(node == NULL)
		return;
	if(level == 1)
		printf(" %d ", node->data);
	if(level > 1)
	{
		printgivenlevel(node->left, level-1);
		printgivenlevel(node->right, level-1);
	}
}

//O(n2)
void levelorderrecur(struct node* node)
{
	int h = maxDepth(node);
	int i;
	for(i = 1; i<= h; i++)
	{
		printgivenlevel(node, i);
		printf("\n");
	}
}

//O(n) (similar to tree traversal)
int countLeafNode(struct node* node)
{
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;

	return (countLeafNode(node->left)+countLeafNode(node->right));
}

int checkchildsumproperty(struct node* node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return 1;

	int left = 0, right = 0;

	if(node->left != NULL)
		left = node->left->data;
	if(node->right != NULL)
		right = node->right->data;

	if((node->data == (left+right))	&& checkchildsumproperty(node->left) && checkchildsumproperty(node->right))
		return 1;
	else
		return 0;
}

void increment(struct node* node, int diff)
{
	if(node->left)
	{
		node->left->data += diff;
		increment(node->left, diff);
	}
	else if(node->right)
	{
		node->right->data += diff;
		increment(node->right, diff);
	}
}

//Convert Tree to satisfy child sum property
void convertTree(struct node* node)
{
	int left = 0, right = 0, diff;
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return;

	convertTree(node->left);
	convertTree(node->right);
	if(node->left != NULL)
		left = node->left->data;
	if(node->right != NULL)
		right = node->right->data;

	diff = left + right - node->data;
	if(diff > 0)
		node->data += diff;
	else if(diff < 0)
	{
		increment(node, -diff);
	}
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

//O(n2)
int diameter(struct node* node)
{
	if(node == NULL)
		return 0;

	int lheight = maxDepth(node->left);
	int rheight = maxDepth(node->right);

	int ldiameter = diameter(node->left);
	int rdiameter = diameter(node->right);

	return max(lheight+rheight+1, max(ldiameter, rdiameter));
}

//O(n) //optimized version of diameter. Instead of calculating height separately
//calculate it inside recursion itself
int diameterOpt(struct node* node, int* height)
{
	int lh = 0, rh = 0, ldiameter = 0, rdiameter = 0;
	if(node == NULL)
	{
		*height = 0;
		return 0;
	}

	ldiameter = diameterOpt(node->left, &lh);
	rdiameter = diameterOpt(node->right, &rh);

	*height = max(lh, rh) + 1;

	return max(lh+rh+1, max(ldiameter, rdiameter));
}
//Check if tree is height balanced
//worst case time for skewed = O(n2)
int isBalanced(struct node* node)
{
	if(node == NULL)
		return 1;

	int lDepth = maxDepth(node->left);
	int rDepth = maxDepth(node->right);

	if(abs(lDepth-rDepth) <= 1 && isBalanced(node->left) && isBalanced(node->right))
		return 1;
	return 0;
}

//O(n)
int isBalancedOpt(struct node* node, int* height)
{
	if(node == NULL)
		return 1;

	int lh  = 0, rh = 0, l, r;

	l = isBalancedOpt(node->left, &lh);
	r = isBalancedOpt(node->right, &rh);

	*height = (lh > rh ? lh : rh) + 1;
	if((lh-rh) || (rh-lh))
		return 0;
	else return lh&&rh;
}

//Level order traversal in SPIRAL
//worst case time = O(n2)
//best case (balanced) = O(n)
void printlevel(struct node* root, int level, int ltr)
{
	if(level <= 1)
	{
		printf(" %d ", root->data);		
	}
	else
	{
		if(ltr)
		{
			if(root->left != NULL)
				printlevel(root->left, level-1, ltr);
			if(root->right != NULL)
				printlevel(root->right, level-1, ltr);
		}
		else
		{
			if(root->right != NULL)
				printlevel(root->right, level-1, ltr);
			if(root->left != NULL)
				printlevel(root->left, level-1, ltr);
		}
	}
}

void levelorderSpiral(struct node* node)
{
	int height = maxDepth(node);
	int i, ltr = 0;
	for(i = 1; i<=height;i++)
	{
		printlevel(node, i, ltr);
		ltr = (ltr == 0) ? 1 : 0;
		nl();
	}
}

//BuildTree from preorder and inorder traversals

int searchInNode(int* in, int strt, int end, int data)
{
	while(strt <= end)
	{
		if(in[strt] == data)
			return strt;
		strt++;
	}
}

//Worst case if tree is skewed O(n2)
struct node* BuildTreeFromPreAndIn(int* pre, int* in, int instrt, int inEnd)
{
	static int preIndex = 0;
	if(instrt > inEnd)
		return NULL;		

	struct node* node = nn(pre[preIndex++]);

	if(instrt == inEnd)
		return node;
	
	int InIndex = searchInNode(in, instrt, inEnd, node->data);

	node->left = BuildTreeFromPreAndIn(pre, in, instrt, InIndex-1);
	node->right = BuildTreeFromPreAndIn(pre, in, InIndex+1, inEnd);
	return node;
}

//Get max width in a binary tree
//that is maximum number of node at a given level
//O(n) using preorder as shown below (we can use level order, but it will be O(n2) for skewed tree)

void maxWidthRecur(struct node* node, int* count, int level)
{
	if(node)
	{
		count[level]++;
		maxWidthRecur(node->left, count, level+1);
		maxWidthRecur(node->right, count, level+1);
	}
}

int maxWidth(struct node* node)
{
	if(node == NULL)
		return 0;

	int h = maxDepth(node);
	int* count = calloc(h, sizeof(int));
	maxWidthRecur(node, count, 0);
	int max = count[0];
	int i;
	for(i = 1; i < h; i++)
	{
		if(count[i] > max)
			max = count[i];
	}
	return max;
}

//IsFoldable
//A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other
//O(n)

int IsFoldableUtil(struct node* n1, struct node* n2)
{
	if(n1 == NULL && n2 == NULL)
		return 1;
	if(n1 == NULL || n2 == NULL)
		return 0;

	return IsFoldableUtil(n1->left, n2->right) && IsFoldableUtil(n1->right, n2->left);
}

int IsFoldable(struct node* node)
{
	if(node == NULL)
		return 1;
	return IsFoldableUtil(node->left, node->right);
}

//Print nodes at K distance from root
//O(n)

void printNodesatKDistance(struct node* node, int k)
{
	if(node == NULL)
		return;

	if(k == 0)
	{
		printf(" %d ", node->data);
		return;
	}

	printNodesatKDistance(node->left, k-1);
	printNodesatKDistance(node->right, k-1);
}

//O(n)
//Sorted order printing of an array containing a BST
void printSorted(int arr[], int start, int end)
{     
  if(start > end)
    return; 

  printSorted(arr, start*2 + 1, end);
  printf("%d  ", arr[start]);
  printSorted(arr, start*2 + 2, end);  
}

//O(n)
int kthsmallestnode(struct node* node, int k)
{
	struct node* cur = node;
	int cnt = 0;
	while(cur != NULL)
	{
		if(cur->left == NULL)
		{
			cnt++;
			if(cnt == k)
				return cur->data;
			cur = cur->right;
		}
		else
		{
			struct node* pred = cur->left;
			while(pred->right != NULL && pred->right != cur)
				pred = pred->right;
			if(pred->right == NULL)
			{
				pred->right = cur;
				cur = cur->left;
			}
			else
			{
				pred->right = NULL;
				cnt++;				
				if(cnt == k)
					return cur->data;
				cur = cur->right;
			}
		}
	}
	return -1;
}

//Level of a node
//O(n), level order traversal
int NodeFound(struct node* node, int level, int data)
{
	if(node == NULL)
		return 0;
	
	if(level == 1)
	{
		return node->data == data;
	}
	else
	{
		return NodeFound(node->left, level-1, data) || NodeFound(node->right, level-1, data);
	}
}

int NodeLevel(struct node* node, int data)
{
	int h = maxDepth(node);
	int i;
	for(i = 1; i<= h; i++)
	{
		if(NodeFound(node, i, data))
			return i;
	}
	return -1;
}
//Level of a node (simplified implementation), O(n)
//Catch: use bitwise OR
int getLevelUtil(struct node *node, int data, int level)
{
  if ( node == NULL )
    return 0;
 
  if ( node->data == data )
    return level;
 
  return getLevelUtil ( node->left, data, level+1) |
         getLevelUtil ( node->right, data, level+1);
}

//O(n)
int printAncestors(struct node* node, int key)
{
	if(node == NULL)
		return 0;

	if(node->data == key)
		return 1;

	if(printAncestors(node->left, key) || printAncestors(node->right, key))
	{
		printf(" %d ", node->data);
	}
}

//O(n)
void printRangeinBST(struct node* node, int k1, int k2)
{
	if(node == NULL)
		return;

	if(node->data > k1)
		printRangeinBST(node->left, k1, k2);

	if(node->data >= k1 && node->data <= k2)
		printf(" %d ", node->data);

	if(node->data < k2)
		printRangeinBST(node->right, k1, k2);
}

//Great Tree List Recursion problem

static void join(struct node* a, struct node* b)
{
	a->right = b;
	b->left = a;
}

static struct node* append(struct node* a, struct node* b)
{
	if(a == NULL)	return b;
	if(b == NULL) return a;

	struct node* aLast = a->left;
	struct node* bLast = b->left;

	join(aLast, b);
	join(bLast, a);

	return a;
}

struct node* TreeToList(struct node* node)
{
	if(node == NULL)
		return NULL;

	struct node* aList;
	struct node* bList;
	aList = TreeToList(node->left);
	bList = TreeToList(node->right);
	
	node->left = node;
	node->right = node;

	aList = append(aList, node);
	aList = append(aList, bList);

	return aList;
}

void printCircularList(struct node* node)
{
	if(node == NULL)
		return;

	struct node* start = node;
	while(node->right != start)
	{
		printf(" %d ", node->data);
		node = node->right;
	}
	printf(" %d ", node->data);
}

//Sum Tree node->data == Sum(node->left) + Sum(node->right)

int isLeaf(struct node* node)
{
	if(node != NULL && (node->left == NULL && node->right == NULL))
		return 1;
	return 0;
}

int isSumTree(struct node* node)
{
	if(node == NULL || isLeaf(node))
		return 1;

	if(isSumTree(node->left) && isSumTree(node->right))
	{
		int ls, rs;
		if(node->left == NULL)
			ls = 0;
		else if(isLeaf(node->left))
			ls = node->left->data;
		else
			ls = 2* node->left->data;

		if(node->right == NULL)
			rs = 0;
		else if(isLeaf(node->right))
			rs = node->right->data;
		else
			rs = node->right->data * 2;

		return(node->data == (ls+rs));
	}
	return 0;
}

void maxSumRootToLeaf(struct node* node, int sum, int* max)
{
	if(node == NULL)
	{
		printf("\nsum of path = %d", sum);
		if(sum > *max)
			*max = sum;
		return;
	}
	else
	{
		sum += node->data;
		printf("\n node->data = %d", node->data);
		maxSumRootToLeaf(node->left, sum, max);
		maxSumRootToLeaf(node->right, sum, max);
	}
}

void nl()
{
	printf("\n");
}

