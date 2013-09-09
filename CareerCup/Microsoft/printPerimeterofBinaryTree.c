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
