int CeilSearchBST(struct node* node, int key)
{
	if(node == NULL)
		return -1;

	if(node->data < key)
		return CeilSearchBST(node->right, key);

	int ceil = CeilSearchBST(node->left, key);
	return (ceil >= key) ? key : node->data;
}
