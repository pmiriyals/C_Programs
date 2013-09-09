#include<stdio.h>
#include<stdlib.h>
#include "util.h"

void test()
{
	struct node* node = buildTree(10);
	nl();
	printf("\ninorder tree = ");
	printinorder(node);
	printf("\npost order tree = ");
	printpostorder(node);
	printf("\npre order tree = ");
	printpreorder(node);
	printf("\n\nsize = %d", size(node));
	printf("\nmaxDepth = %d", maxDepth(node));
	printf("\nminVal = %d", minValue(node));
	printf("\n hasPathSum = %s", hasPathSum(node,104) ? "true" : "false");
	nl();
	printPaths(node);
	printf("\nis same tree = %s", sameTree(node, node) ? "true": "false");
	nl();
	printf("\n number of trees possible with numkyes = 10 is %d\n", countTrees(10));
	printf("\nisBST = %s", isBST(node, -100, 100) ? "true" : "false");
	printf("\nin-order traversal using stack (iterative) = ");
	printinorderiterusingstack(node);
	nl();
	printf("In-order traversal without stakc (iterative) = ");
	InorderTraversalWithoutStackIter(node);
	printf("\nInOrder successor = %d\n", inordersuccofBST(node, node->left));
	printf("\n In-order pred = %d\n", inorderpred(node, node->left));

	printf("\n LCA = %d\n", lowestCommonAncestor(node, 25, 27));
	printf("pre-order traversal (iterative) = ");
	preorderIterUsingStack(node);
	nl();
	printf("post-order (iterative) = ");
	postorderIter(node);
	printf("\n level order traversal = ");
	levelOrderTraversal(node);
	nl();
	printf("level order traversal (recur) = ");
	levelorderrecur(node);
	printf("\nNum leaf node = %d", countLeafNode(node));
	printf("\ndiameter = %d\n", diameter(node));
	int height;
	printf("\ndiameterOpt = %d\n", diameterOpt(node, &height));
	printf("\nisbalanced = %s", isBalanced(node) ? "true" : "false");
	printf("\nlevel order spiral = \n");
	levelorderSpiral(node);
	nl();
	int h = 0;
	printf("\n isBalancedOpt = %d", isBalancedOpt(node, &h));
//	convertTree(node);
//	printf("\nin order after converting = ");
//	printinorder(node);
//	printf("\n ischildsum = %s\n", checkchildsumproperty(node) ? "true" : "false");

	
//	mirror(node);
//	printf("\nin order tree after mirror= ");
//	printinorder(node);
//	printf("\npre order tree after mirror = ");
//	printpreorder(node);
//	doubleTree(node);
//	printf("\nprint in order of double tree = ");
//	printinorder(node);
//	printf("\nprint pre order of double tree = ");
//	printpreorder(node);
//	nl();
}

void testBuildTreeFromGivenPreandInOrderTraversals()
{
	int pre[] = {10, 8, 6, 9, 15, 12};
	int in[] = {6, 8, 9, 10, 12, 15};

	struct node* node = BuildTreeFromPreAndIn(pre, in, 0, (sizeof(in)/sizeof(int))-1);
	printf("\ninorder = ");
	printinorder(node);
	printf("\npreorder = ");
	printpreorder(node);
	printf("\npost order = ");
	printpostorder(node);
	printf("\nlevel order = \n");
	levelorderrecur(node);
}

void testfunctions()
{
	struct node* node = buildTree(10);	
	printf("\npost order tree = ");
	printpostorder(node);
	printf("\npre order tree = ");
	printpreorder(node);
	printf("\nMax width of the tree = %d\n", maxWidth(node));
	printf("\nIsFoldable = %s\n", IsFoldable(node) ? "true" : "false");
	printf("\n print nodes at k distance from root = ");
	printNodesatKDistance(node, 3);

	printf("\n kth smallest element = %d\n", kthsmallestnode(node, 6));
	printf("\n level of node = %d\n", getLevelUtil(node, 7, 1));
	printf("Ancestors = ");
	printAncestors(node, 25);
	printf("\nPrint range between k1 and k2 = ");
	printRangeinBST(node, 9, 24);
	nl();
//	printf("\n Cicular list = ");
//	printCircularList(TreeToList(node));
	node->left->data = 10;
	node->left->left = NULL;
	node->left->right = NULL;
	node->right->data = 20;
	node->right->left = NULL;
	node->right->right = NULL;
	node->data = 30;
	printf("\nIsSumTree = %d\n", isSumTree(node));
}

void main()
{
	struct node* node = buildTree(10);
	printf("\ninorder tree = ");
	printinorder(node);
	
	int max = 0;
	maxSumRootToLeaf(node, 0, &max);
	printf("\n max = %d\n", max);
	nl();
}
