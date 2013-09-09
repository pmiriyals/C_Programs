#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* nn(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(struct node** noderef, int data)
{
	struct node* temp = nn(data);
	temp->next = *noderef;
	*noderef = temp;
}

struct node* pushattailbyref(int num)
{
	struct node* head = NULL;
	struct node** localref = &head;
	int i;
	for(i=0;i<num;i++)
	{
		push(localref, i);
		localref = &((*localref)->next);
	}
	return head;
}

void deleteNodeN(struct node* node)
{
	struct node* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;
	free(temp);
}

void nl()
{
	printf("\n");
}

void printlist(struct node* node)
{
	while(node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;	
	}
}

void printMiddle(struct node* node)
{
	struct node* fast = node;
	struct node* slow = node;
	while(fast->next!= NULL)
	{
		fast = fast->next;
		if(fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	printf("\nCurrent middle element =  %d \n", slow->data);
}

void printNthNodeFromEnd(struct node* node, int n)
{
	struct node* fast = node;
	struct node* slow = NULL;
	int cnt = 0;
	while(fast != NULL)
	{
		fast = fast->next;

		if(cnt >= n)
		{
			if(slow == NULL)
				slow = node;
			else
				slow = slow->next;			
		}
		cnt++;
	}
	if(slow)
		printf("\n%dth node from end =  %d\n", n, slow->data);
	else
		printf("\n invalid num\n");
}


void delNodeNdriver(struct node* head)
{
	deleteNodeN(head->next);
	puts("\nafter deleting: ");
	printlist(head);	
	nl();
}

int cntGivenDatainList(struct node* node, int data)
{
	int cnt = 0;
	while(node != NULL)
	{
		if(node->data == data) cnt++;
		node = node->next;
	}
	return cnt;
}

void ReverseListRecur(struct node** headRef)
{
	if(*headRef == NULL)
		return;

	struct node* first = *headRef;
	struct node* rest = first->next;

	if(rest == NULL)
		return;

	ReverseListRecur(&rest);
	
	first->next->next = first;
	first->next = NULL;
	*headRef = rest;
}

//O(n)
struct node* ReverseListIter(struct node* node)
{
	struct node* prev = NULL;
	struct node* next;
	while(node != NULL)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	return prev;
}

void createloop(struct node* head)
{
	struct node* first = head;
	while(head->next != NULL)
		head = head->next;
	head->next = first;
}

void detectloop(struct node* head)
{
	struct node* slow = head;
	struct node* fast = head;
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		if(slow == fast)
		{
			printf("\n detected loop at %d in the list\n", fast->data);
			return;
		}
	}
	printf("\nNo loop detected\n");
}

int compare(struct node* a, struct node* b)
{
	if(a == NULL && b== NULL)
		return 1;	
	compare(a->next, b->next);
	if(a->data == b->data)
		return 1;
	else
		return 0;
}

int isPalinRecur(struct node** left, struct node* right)
{
	if(!right)
		return 1;


	return isPalinRecur(left, right->next);

	int ispalin = ((*left)->data == right->data);
	*left = (*left)->next;
	return ispalin;
}

//not working, idea is fine
// go to the middle of the list
//reverse the second half, compare both halves
//revert back the list
int isPalindromeIter(struct node* node)
{
	struct node* slow = NULL;
	struct node* fast = node;

	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			if(slow == NULL)
				slow = node->next;
			else			
				slow = slow->next;
			fast = fast->next;
		}		
	}
	printf("\n rest of the list starting from slow pointers is : ");
	printlist(slow);
	nl();
	struct node* rest = ReverseListIter(slow->next);
	printf("\n rest list (reverse) = ");
	printlist(rest);
	slow->next = NULL;
	int result = compare(node, slow);
	rest = ReverseListIter(rest);
	slow->next = rest;
	printf("\n after reseting the list; ");
	printlist(node);
	return result;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void pairwiseswap(struct node** href)
{
	struct node* temp = *href;
	while(temp!= NULL && temp->next != NULL)
	{
		swap(&temp->data, &temp->next->data);
		temp = temp->next->next;
	}
}

void delAltNodes(struct node* node)
{
	struct node* temp = NULL;
	while(node!= NULL && node->next != NULL)
	{
		temp = node->next->next;
		free(node->next);
		node->next = temp;
		node = temp;
	}
}

void sortedintersect(struct node* a, struct node* b)
{
	while(a != NULL && b!= NULL)
	{
		if(a->data == b->data)
		{
			printf(" %d ->", a->data);
			a = a->next;
			b = b->next;
		}
		else if(a->data > b->data)
		{
			b = b->next;
		}
		else
			a = a->next;	
	}
}

void copylistbyK(struct node* head, struct node** aref, int k)
{
	struct node dummy;
	dummy.next = NULL;
	struct node* cur = &dummy;	
	int i;	
	while(head != NULL)
	{
		push(&(cur->next), head->data);
		cur = cur->next;
		for(i = 0;i < k && head; i++)
			head = head->next;
	}	
	*aref = dummy.next;
}

void main()
{
	struct node* head = pushattailbyref(10);
	printf("\nlist built is: ");
	printlist(head);
	nl();
	struct node* si = NULL;
	copylistbyK(head, &si, 3);
	printf("\n list si = ");
	printlist(si);
	printf("\n sorted intersect = ");
	sortedintersect(head, si);
//	pairwiseswap(&head);
//	printlist(head);
	nl();
//	delAltNodes(head);
//	printlist(head);
//	printf("\n the list is %s palindrome\n", isPalinRecur(&head, head) ? "a" : "not a");
//	createloop(head);
//	detectloop(head);

//	head = ReverseListIter(head);
//	ReverseListRecur(&head);
//	printf("\n Reversed list = ");
//	printlist(head);
//	printf("\n %d occurs %d times in the given list\n", 10, cntGivenDatainList(head, 10));
//	printNthNodeFromEnd(head, 10);
//	printMiddle(head);
	
}
