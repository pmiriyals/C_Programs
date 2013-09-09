#include<stdio.h>
#include<stdlib.h>
#include "util.h"

struct node* nn(int data)
{
	struct node*  newNode = malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

void nl()
{
	printf("\n");
}

//O(1)
void push(struct node** node, int data)
{
	struct node* temp = nn(data);
	temp->next = *node;
	*node = temp;
}

int* builduniqueEle(int numEle)
{
	int* cnt = calloc(numEle+21, sizeof(int));
	int* arr = malloc(sizeof(int) * numEle);
	int num = 0;
	int i = 0;
	printf("\n Generating unique elements = ");
	while(i < numEle)
	{
		num = rand() % (numEle + 20);		
		if(!cnt[num])
		{
			cnt[num] = 1;
			arr[i] = num;
			i++;		
			printf(" %d ", num);	
		}
	}
	nl();
	return arr;
}

//O(n)
void buildlistathead(struct node** head, int numEle)
{
	int* arr = builduniqueEle(numEle);
	struct node* node = NULL;
	int ndx = 0;
	while(ndx < numEle)
	{
		push(&node, arr[ndx]);
		ndx++;
	}
	*head = node;
}

//O(n)
struct node* buildlistattailbydummy(int numEle)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* local = &dummy;
	int* arr = builduniqueEle(numEle);
	int ndx = 0;
	while(ndx < numEle)
	{
		push(&(local->next), arr[ndx]);
		ndx++;
		local = local->next;
	}
	return dummy.next;
}

//O(n)
struct node* buildlistattailbyref(int numEle)
{
	struct node* head = NULL;
	struct node** localRef = &head;
	int ndx = 0;
	int* arr = builduniqueEle(numEle);

	while(ndx < numEle)
	{
		push(localRef, arr[ndx++]);
		localRef = &((*localRef)->next);
	}
	return head;
}

//O(n)
int listlen(struct node* node)
{
	int cnt = 0;
	while(node != NULL)
	{
		node = node->next;
		cnt++;
	}
	printf("\nList length = %d\n", cnt);
	return cnt;
}

//O(n)
void printlist(struct node* node, char* s)
{
	printf("\nList %s = ", s);
	while(node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
	nl();
}

//O(n) interate till nth position
void insertnth(struct node** node, int n, int data)
{
	if(n == 0)
	{
		push(node, data);
	}
	else
	{
		struct node* temp = *node;
		int ndx = 0;
		while(ndx < (n-1) && temp != NULL)
		{
			temp = temp->next;
			if(temp == NULL)
			{
				printf("\n index out of bounds\n");
				return;
			}
			ndx++;
		}
		push(&(temp->next), data);
	}
}

int pop(struct node** node)
{
	int num = (*node)->data;
	struct node* temp = *node;
	*node = temp->next;
	free(temp);
	printf("\n popped node = %d\n", num);
	return num;
}

//O(n)
void sortedinsert(struct node** node, struct node* newNode)
{
	struct node dummy;
	dummy.next = *node;
	struct node* cur = &dummy;
	while(cur->next != NULL && cur->next->data < newNode->data)
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;
	*node = dummy.next;
}

//O(n)
void insertsort(struct node** href)
{
	struct node* cur = *href;
	struct node* result = NULL;
	struct node* next;

	while(cur != NULL)
	{
		next = cur->next;
		sortedinsert(&result, cur);
		cur = next;
	}
	*href = result;
}

//O(n)
void SortedInsertbydata(struct node** node, int data)
{
	struct node* temp = NULL;
	if(*node == NULL || (*node)->data > data)
	{
		temp = nn(data);
		temp->next = *node;
		*node = temp;
	}
	else
	{
		struct node* temp = *node;
		while(temp->next != NULL && temp->next->data < data)
		{
			temp = temp->next;
		}
		push(&(temp->next), data);
	}
}

//O(n)
void append(struct node** aref, struct node** bref)
{
	if(*aref == NULL)
	{
		*aref = *bref;
	}
	else
	{
		struct node* cur = *aref;
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = *bref;
	}
	*bref = NULL;
}

//O(n)
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef)
{
	struct node* fast;
	struct node* slow;
	if (source==NULL || source->next==NULL) 
	{ 
		*frontRef = source;
		*backRef = NULL;
	}
	else 
	{
		slow = source;
		fast = source->next;
		while (fast != NULL) 
		{
			fast = fast->next;
			if (fast != NULL) 
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

//O(n)
void removeduplicates(struct node* node)
{
	if(node == NULL)
		return;
	struct node* next;
	while(node->next != NULL)
	{
		if(node->data == node->next->data)
		{
			next = node->next->next;
			free(node->next);
			node->next = next;
		}
		else
			node = node->next;
	}
}

//O(1)
void movenode(struct node** src, struct node** dest)
{
	struct node* node = *src;
	*src = (*src)->next;
	node->next = *dest;
	*dest = node;
}

void alternatingsplit(struct node* node, struct node** aref, struct node** bref)
{
	struct node adummy;
	adummy.next = NULL;
	struct node bdummy;
	bdummy.next = NULL;
	struct node* a = &adummy;
	struct node* b = &bdummy;

	while(node != NULL)
	{
		movenode(&node, &(a->next));
		a = a->next;
		if(node != NULL)
		{
			movenode(&node, &(b->next));
			b = b->next;
		}
	}
	*aref = adummy.next;
	*bref = bdummy.next;
}

struct node* shufflemerge(struct node* a, struct node* b)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* cur = &dummy;

	while(a != NULL && b!= NULL)
	{
		movenode(&a, &(cur->next));
		cur = cur->next;
		movenode(&b, &(cur->next));
		cur = cur->next;
	}
	if(a)
		cur->next = a;
	else if(b)
		cur->next = b;

	return dummy.next;
}

struct node* sortedmerge(struct node* a, struct node* b)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* result = &dummy;
	while(1)
	{
		if(a == NULL)
		{
			result->next = b;
			break;
		}
		else if(b == NULL)
		{
			result->next = a;
			break;
		}
		else
		{
			if(a->data < b->data)
			{
				movenode(&a, &(result->next));
				result = result->next;
			}
			else
			{
				movenode(&b, &(result)->next);
				result = result->next;
			}
		}
	}
	return dummy.next;
}

void mergesort(struct node** href)
{
	struct node* head = *href;
	struct node* a = NULL;
	struct node* b = NULL;
	if(head == NULL || head->next == NULL)
		return;

	frontbacksplit(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*href = sortedmerge(a, b);
}

struct node* sortedintersect(struct node* a, struct node* b)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* tail = &dummy;
	while(a != NULL && b!= NULL)
	{
		if(a->data == b->data)
		{
			push(&(tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if(a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return dummy.next;
}

//O(n)
void reverse(struct node** href)
{
	struct node* head = *href;
	struct node* prev = NULL;
	struct node* next;
	while(head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	*href = prev;
}

//O(n)
void revrecur(struct node** href)
{
	if(*href == NULL)
		return;

	struct node* front = *href;
	struct node* rest = front->next;

	if(rest == NULL)
		return;

	revrecur(&rest);
	front->next->next = front;
	front->next = NULL;
	*href = rest;
}

struct node* buildlistinsortedorder(int numEle)
{
	int i = 0;
	struct node* head = NULL;
	struct node** localRef = &head;

	for(i = 0; i< numEle; i++)
	{
		push(localRef, i * 2);
		localRef = &((*localRef)->next);
	}
	return head;
}

//O(n) (linked list does not provide direct access of elements)
int getNth(struct node* node, int n)
{
	int cnt = 1;
	while(node != NULL)
	{
		if(cnt == n)
			return node->data;		
		node = node->next;
		cnt++;
	}
	return -1;
}

void deletelist(struct node** node)
{
	struct node* temp = *node;
	printf("\n Deleting list = ");
	struct node* next;
	while(temp != NULL)
	{
		printf(" %d ", temp->data);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*node = temp;
}

//delete a node, given only a pointer to the node
//O(1)
void delnodeGivenOnlyAPointerToTheNode(struct node* node)
{
	if(node == NULL) return;	
	if(node->next)
	{
		node->data = node->next->data;
		struct node* next = node->next;
		node->next = node->next->next;
		free(next);
	}
	else
	{		
		//will not work. Leaves garbage value.
		free(node);
	}
}

//O(n)
int middlenode(struct node* head)
{
	if(head == NULL) return;
	struct node* slow = head;
	struct node* fast = head;
	while(fast->next != NULL)
	{
		fast = fast->next;
		if(fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow->data;
}

//O(n)
int NthNodeFromEnd(struct node* head, int n)
{
	if(head == NULL)
		return;
	struct node* fast = head;
	struct node* slow = head;
	int cnt = 1;
	while(fast && cnt < n)
	{
		fast = fast->next;
		cnt++;
	}
	if(cnt == n)
	{
		while(fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow->data;
	}
	return -1;
	
}

//O(n)
int detectloop(struct node* node)
{
	struct node* fast = node;
	struct node* slow = node;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		if(fast == slow)
			return 1;
	}
	return 0;
}

//O(n)
int ispalindrome(struct node* node)
{
	if(node == NULL) return 1;	
	struct node* slow = node;
	struct node* fast = node;
	struct node* left = node;

	while(fast->next)
	{
		fast = fast->next;
		if(fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}

	reverse(&slow);
	while(slow && left)
	{
		if(slow->data == left->data)
		{
			slow = slow->next;
			left = left->next;
		}
		else
			return 0;
	}
	reverse(&slow);
	return 1;
}

//O(n)
int ispalindromerecur(struct node** left, struct node* right)
{
	if(right == NULL)
		return 1;
	
	int ispalin = ispalindromerecur(left, right->next);
	if(ispalin < 1)
		return 0;
	ispalin = ((*left)->data == right->data);
	*left = (*left)->next;
	return ispalin;
}

int findintersection(struct node* biggerlist, struct node* smallerlist, int diff)
{
	int cnt = 0;
	while(cnt < diff)
	{
		biggerlist = biggerlist->next;
		cnt++;
	}

	while(biggerlist && smallerlist)
	{
		if(biggerlist == smallerlist)
			return biggerlist->data;
		biggerlist = biggerlist->next;
		smallerlist = smallerlist->next;
	}
	return -1;
}
//O(m+n) worst case (no intersection)
//O(1) best case, found at first node
int intersectionpoint(struct node* a, struct node* b)
{
	int alen = listlen(a);
	int blen = listlen(b);

	if(alen < blen)
		return findintersection(b, a, blen-alen);
	else
		return findintersection(a, b, alen-blen);
}

//O(n)
void splitcircularlist(struct node* node)
{
	struct node* first = node;
	struct node* second = node;
	struct node* fast = node;
	struct node* slow = node;
	
	while(fast->next != first)
	{
		fast = fast->next;
		if(fast->next != first)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	second = slow->next;
	slow->next = first;
	fast->next = second;
	printf("\n printing first list = ");
	slow = first;
	while(slow->next != first)
	{
		printf(" %d ", slow->data);
		slow = slow->next;
	}
	printf(" %d ", slow->data);
	fast = second;
	printf("\n printing second list = ");
	while(fast->next != second)
	{
		printf(" %d ", fast->data);
		fast = fast->next;
	}
	printf(" %d ", fast->data);
}

//O(n)
void movelastnodetofirst(struct node** nref)
{
	if(*nref == NULL || (*nref)->next == NULL) return;

	struct node* node = *nref;
	struct node* prev = node;
	struct node* next = node->next;

	while(next->next != NULL)
	{
		next = next->next;
		prev = prev->next;
	}
	prev->next = NULL;
	next->next = node;
	*nref = next;
}

void swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

void pairwiseswap(struct node* node)
{
	if(node == NULL || node->next == NULL)
		return;
	while(node != NULL && node->next != NULL)
	{
		swap(&(node->data), &(node->next->data));
		node = node->next->next;
	}	
}

void pairwiseswaprecur(struct node* node)
{
	if(node == NULL || node->next == NULL)
		return;

	swap(&(node->data), &(node->next->data));
	pairwiseswaprecur(node->next->next);
}

//O(n)
//tricky:check for both node != NULL && node->next != NULL
void deletealternatenodes(struct node* node)
{
	if(node == NULL)
		return;
	struct node* next;
	while(node && node->next)
	{
		next = node->next;
		node->next = node->next->next;
		node = node->next;
		free(next);
	}
}

//O(n)
int isidentical(struct node* a, struct node* b)
{
	while(a && b)
	{
		if(a->data != b->data)
			return 0;
		a = a->next;
		b = b->next;
	}
	if(a == NULL && b == NULL)
		return 1;
	return 0;
}


int isidenticalrecur(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return 1;
	if(a == NULL && b!= NULL)
		return 0;
	if(a != NULL && b == NULL)
		return 0;

	if(a->data != b->data)
		return 0;
	return isidenticalrecur(a->next, b->next);
}

struct node* reversebyknodes(struct node* node, int k)
{
	int cnt = 0;
	struct node* cur = node;
	struct node* next;
	struct node* prev = NULL;

	while(cur != NULL && cnt < k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		cnt++;
	}
	if(next != NULL)
		node->next = reversebyknodes(next, k);
	return prev;
}

void printcircularlist(struct node* head)
{
	if(head == NULL) return;
	struct node* next = head->next;
	printf("\n circular list = ");
	struct node* start = head;
	while(head != NULL && next != start)
	{
		printf(" %d ", head->data);
		head = head->next;
		next = next->next;
	}
	printf(" %d ", head->data);
}

//O(n)
void insertinsortedcircularlist(struct node** href, int data)
{
	struct node* start = *href;
	struct node* newN = nn(data);
	//base case. If given list is NULL, set a circular ref on new node.
	if(start == NULL)
	{
		newN->next = newN;
		*href = newN;
		return;
	}
	struct node* node = start->next;
	//special case for first node. Need to change the head pointer.
	if(start->data >= newN->data)
	{
		while(node->next != start)
			node = node->next;
		node->next = newN;
		newN->next = start;
		*href = newN;
	}
	else
	{
		struct node* cur = start;
		//for the rest of the list
		while(cur->next != start && cur->next->data <= newN->data)
			cur = cur->next;
		newN->next = cur->next;
		cur->next = newN;
	}
}
//O(n)
struct node* reversealternateknodes(struct node* head, int k)
{
	if(head == NULL)
		return;
	int cnt = 0;
	struct node* cur = head;
	struct node* next;
	struct node* prev = NULL;

	while(cur != NULL && cnt < k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		cnt++;
	}
	if(head != NULL)
		head->next = cur;
	cnt = 0;
	while(cnt < k-1 && cur != NULL)
	{
		cur = cur->next;
		cnt++;
	}
	if(cur != NULL)
		cur->next = reversealternateknodes(cur->next, k);
	return prev;
}

//O(n)
void deletenodeifgreateronrightwithoutrev(struct node** href)
{
	if(*href == NULL)
		return;

	struct node* node = *href;
	int set = 1;
	struct node* start = node;
	struct node* next;
	struct node* prev = NULL;
	while(node != NULL && node->next != NULL)
	{
		if(node->data < node->next->data)
		{
			next = node->next;
			free(node);
			node = next;
			if(prev)
				prev->next = node;
			if(set)
				start = next;
		}
		else
		{
			set = 0;
			prev = node;
			node = node->next;	
		}
	}
	*href = start;
}

void deletenodeifgreatervalueonright(struct node** href)
{
	struct node* node = *href;

	if(node == NULL)
		return;

	reverse(&node);
	struct node* start = node;
	struct node* next;
	int maxtillhere = node->data;
	while(node != NULL && node->next != NULL)
	{
		if(node->next->data < maxtillhere)
		{
			next = node->next->next;
			maxtillhere = node->next->data;
			free(node->next);
			node->next = next;
		}
		else
			node = node->next;
	}
	reverse(&start);
	*href = start;
}

//O(n)
void seggregateevenodd(struct node** href)
{
	struct node* head = *href;
	struct node dummy;
	dummy.next = NULL;
	struct node* odd = &dummy;
	struct node* next;
	int set = 1;
	struct node* even = head;
	struct node* prev = NULL;
	while(head != NULL)
	{
		if(head->data % 2)
		{
			odd->next = head;
			next = head->next;
			odd = odd->next;
			odd->next = NULL;
			head = next;
			if(prev)
				prev->next = next;
		}
		else
		{
			if(set)
			{
				set = 0;
				even = head;
			}
			prev =	head;
			head = head->next;
		}
	}
	printlist(dummy.next, "odd list");
	printlist(even, "even list");
	prev->next = dummy.next;
	*href = even;
}

struct node* addsamesizelist(struct node* a, struct node* b, int* carry)
{
	if(!a && !b)
		return NULL;

	struct node* result = malloc(sizeof(struct node));
	if(a && b)
	{
		result->next = addsamesizelist(a->next, b->next, carry);
		int sum = a->data + b->data + *carry;
		result->data = sum % 10;
		*carry = sum/10;
	}
	return result;

	
}

void swapptr(struct node** a, struct node** b)
{
	struct node* temp = *a;
	*a = *b;
	*b = temp;
}

void addremaininglist(struct node* rem, struct node* cur, struct node** result, int* carry)
{
	if(rem != cur)
	{
		addremaininglist(rem->next, cur, result, carry);
		int sum = rem->data + *carry;
		push(result, sum%10);
		*carry = sum/10;
	}
}

struct node* addListbydigits(struct node* a, struct node* b)
{
	int la = listlen(a);
	int lb = listlen(b);
	struct node* result = NULL;
	int carry = 0;
	if(la == lb)
	{
		result = addsamesizelist(a, b, &carry);		
	}
	else
	{
		int diff;
		if(lb > la)
		{
			diff = lb - la;
			swapptr(&a, &b); //set a as larger 
		}
		else
			diff = la-lb;
		struct node* cur = a;
		int i;
		for(i = 0; i< diff; i++)
			cur = cur->next;
		result = addsamesizelist(cur, b, &carry);
		addremaininglist(a, cur, &result, &carry);
	}
	if(carry > 0)
		push(&result, carry);
	return result;
}

//Sorted Linked List to Balanced BST O(n)
struct Tnode* newTnode(int data)
{
	struct Tnode* temp = malloc(sizeof(struct Tnode));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}

void inorderTnode(struct Tnode* root)
{
	if(root == NULL)
		return;
	inorderTnode(root->left);
	printf(" %d ", root->data);
	inorderTnode(root->right);
}

struct Tnode* listToTree(struct node** nref, int n)
{
	if(n <= 0)
		return NULL;

	struct Tnode* left = listToTree(nref, n/2);
	
	struct Tnode* root = newTnode((*nref)->data);
	root->left = left;
	*nref = (*nref)->next;
	root->right = listToTree(nref, n-(n/2)-1);
	return root;
}

//O(n)
struct Tnode* sortedlinkedlistTobalancedbinarytree(struct node* node)
{
	int n = listlen(node);
	return listToTree(&node, n);
}

//O(n)
void RightRotate(struct node** node, int k)
{
	if(*node == NULL)
		return;
	int l = listlen(*node);
	if(l < k)
		return;
	int cnt = 0;
	struct node* cur = *node;
	while(cur != NULL && cnt < (l-k-1))
	{
		cnt++;
		cur = cur->next;
	}
	if(cr == NULL)
		return;
	struct node* temp = cur->next;
	struct node* save = cur->next;
	cur->next = NULL;
	while(temp->next != NULL)
		temp = temp->next;

	temp->next = *node;
	*node = save;
}
