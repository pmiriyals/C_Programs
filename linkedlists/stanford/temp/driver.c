#include<stdio.h>
#include<stdlib.h>
#include "util.h"

void testpush()
{
	struct node* node = NULL;
	push(&node, 10);
	push(&node, 20);
	push(&node, 30);
	nl();
	while(node!=NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
	nl();
}

void testbuildlistathead()
{
	struct node* node = NULL;	
	buildlistathead(&node, 10);
	printlist(node, "at head");

}

void testattailbydummy()
{
	struct node* node = NULL;
	node = buildlistattailbydummy(10);
	printlist(node, "at tail by dummy ");
}

void testattailbyref()
{
	struct node* node = NULL;
	node = buildlistattailbyref(10);
	printlist(node, "at tail by local ref ");
	listlen(node);
}

void testpop()
{
	struct node* node = NULL;
	node = buildlistattailbyref(10);
	printlist(node, "at tail by local ref ");
	listlen(node);
	pop(&node);
	printlist(node, "after popping a node");
	listlen(node);
}

void testinsertnth()
{
	struct node* node = NULL;
	node = buildlistattailbyref(10);
	printlist(node, "at tail by local ref ");
	insertnth(&node, 10, 100);
	printlist(node, " after inserting at node 10");
}

void testSortedInsertbydata()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(10);
	printlist(node, "in sorted order ");
	SortedInsertbydata(&node, 20);
	printlist(node, " after sorted insert");
}

void testbuildlistinsortedorder()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(10);
	printlist(node, "in sorted order ");
	sortedinsert(&node, nn(18));
	printlist(node, " after sorted insert");
}

void testinsertsort()
{
	struct node* node = NULL;
	node = buildlistattailbyref(10);
	printlist(node, "before sorting the list");
	insertsort(&node);
	printlist(node, "after sorting the list ");
}


void testremoveduplicates()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(5);
	printlist(node, "node");
	struct node* temp = buildlistinsortedorder(5);
	printlist(temp, "temp");
	append(&node, &temp);
	printlist(node, "after appending");
	insertsort(&node);
	printlist(node, "after sorting");
	removeduplicates(node);
}

void testmovenode()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(5);
	printlist(node, "node");
	struct node* temp = buildlistinsortedorder(5);
	printlist(temp, "temp");
	movenode(&node, &temp);
	printlist(node, "node");
	printlist(temp, "temp");
}

void main()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(10);
	printlist(node, "node");
	struct node* a = NULL;
	struct node* b = NULL;
		
	alternatingsplit(node, &a, &b);
	printlist(a, "a");
	printlist(b, "b");
}
