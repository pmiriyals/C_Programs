void PostOrderPredecessor(struct node* node, int data, int* setPre)
{
	if(node == NULL)
		return;
	
	if(*setPre)
	{
		printf("predecessor = %d", node->data);
		exit(0);
//		*setPre = 0;
	}	
	if(node->data == data)
	{
		*setPre = 1;
	}
	PostOrderPredecessor(node->right, data, setPre);
	PostOrderPredecessor(node->left, data, setPre);
}
