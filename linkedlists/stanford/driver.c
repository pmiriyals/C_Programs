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

void testalternatingsplit()
{
	struct node* node = NULL;
	node = buildlistinsortedorder(5);
	printlist(node, "node");
	struct node* a = NULL;
	struct node* b = NULL;
	alternatingsplit(node, &a, &b);
	printlist(a, "a");
	printlist(b, "b");
}

void testshufflemerge()
{
	struct node* a = buildlistinsortedorder(10);
	struct node* b = buildlistattailbyref(2);
	printlist(a, "a");
	printlist(b, "b");

	struct node* node = shufflemerge(a, b);
	printlist(node, "node");
}

void testsortedmerge()
{
	struct node* a = buildlistinsortedorder(5);
	struct node* b = buildlistinsortedorder(5);
	printlist(a, "a");
	printlist(b, "b");

	struct node* node = sortedmerge(a, b);
	printlist(node, "node");
}

void testmergesort()
{
	struct node* node = buildlistattailbyref(20);
	printlist(node, "node before sorting");
	mergesort(&node);
	printlist(node, "node after sorting");
}

void testsortedintersect()
{
	struct node* a = buildlistinsortedorder(10);
	printlist(a, "a");
	struct node* b = buildlistinsortedorder(10);
	printlist(b, "b");
	struct node* result = sortedintersect(a, b);
	printlist(result, "result");
}

void testreverse()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	reverse(&node);
	printlist(node, "after reversing");
}

void testrevrecur()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	revrecur(&node);
	printlist(node, "after reversing");
}

void testdeletenode()
{
	struct node* node = buildlistattailbyref(4);
	printlist(node, "node before deleting");
	printf("\ndelete node = %d\n", node->next->next->next->data);
	delnodeGivenOnlyAPointerToTheNode(node->next->next->next);
	printlist(node, "node after deleting");
}

void testnthnode()
{
	struct node* node = buildlistattailbyref(3);
	printlist(node, "node");
	printf("\nmiddle node = %d\n", middlenode(node));
	printf("\nnth node from end = %d\n", NthNodeFromEnd(node,1));
}

void testdetectloop()
{
	struct node* node = buildlistattailbyref(3);
	printlist(node, "node");
	node->next->next = node;
	printf("\nloop exists = %s\n", detectloop(node) ? "true" : "false");
}

void testpalindrome()
{
	struct node* node = buildlistattailbyref(3);
	printlist(node, "node");
	node->data = node->next->next->data;
	printlist(node, "palindrome");

	printf("\nispalindrome recur = %s\n", ispalindromerecur(&node, node) ? "true" : "false");
	printf("\nispalindrome = %s\n", ispalindrome(node) ? "true" : "false");

}

void testintersectionpoint()
{
	struct node* node = buildlistattailbyref(6);
	printlist(node, "node");
	struct node* temp = node->next->next->next->next;
	printf("\nintersection point = %d\n", intersectionpoint(node, temp));

}

void testsplitcircularlist()
{
	struct node* node = buildlistattailbyref(4);
	printlist(node, "node");
	node->next->next->next->next = node;;
	splitcircularlist(node);	

}

void testmovelastnode()
{
	struct node* node = buildlistattailbyref(10);
	printlist(node, "node");
	movelastnodetofirst(&node);
	printlist(node, "after moving last node to first");

}

void testpairwiseswap()
{
	struct node* node = buildlistattailbyref(10);
	printlist(node, "node");
	pairwiseswap(node);
	pairwiseswaprecur(node);
	printlist(node, "after pairwise swap");

}

void testdeletealternatenodes()
{
	struct node* node = buildlistattailbyref(10);
	printlist(node, "node");
	deletealternatenodes(node);
	printlist(node, "node after deleting alternate nodes");
}

void testisidentical()
{
	struct node* a = buildlistinsortedorder(10);
	printlist(a, "a");
	struct node* b = buildlistinsortedorder(10);
	printlist(b, "b");
	printf("\nisidentical = %s\n", isidentical(a, b) ? "true" : "false");
	printf("\nisidentical = %s\n", isidenticalrecur(a, b) ? "true" : "false");

}

void testrevbygivensize()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	node = reversebyknodes(node, 1);
	printlist(node, "after reversing by given size");
}

void testsortedinsertincircularlist()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	struct node* cur = node;
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	printf("\ncircular list before insertion:");
	printcircularlist(node);
	insertinsortedcircularlist(&node, -2);
	printf("\ncircular list after insertion");
	printcircularlist(node);
}

void testreversealternatenodes()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	node = reversealternateknodes(node, 3);
	printlist(node, "node after alternate reverse by k");
}

void testdeletenodeifrightgreater()
{
	struct node* node = buildlistattailbyref(10);
	printlist(node, "node");
	//deletenodeifgreatervalueonright(&node);
	deletenodeifgreateronrightwithoutrev(&node);
	printlist(node, "node after deleting");

}

void testseggregatingevenodd()
{
	struct node* node = buildlistattailbyref(10);
	printlist(node, "node");
	seggregateevenodd(&node);
	printlist(node, "node after seggregating");

}

void testaddlists()
{
	struct node* a = buildlistattailbyref(10);
	printlist(a, "a");
	struct node* b = buildlistattailbyref(0);
	printlist(b, "b");
	struct node* result = addListbydigits(a, b);
	printlist(result, "result");
}

void testlisttotree()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	struct Tnode* root = sortedlinkedlistTobalancedbinarytree(node);
	printf("\n inorder traversal = ");
	inorderTnode(root);

}

void testrotate()
{
	struct node* node = buildlistinsortedorder(10);
	printlist(node, "node");
	RightRotate(&node, 2);
	printlist(node, "node after rotating");

}

void main()
{
}
