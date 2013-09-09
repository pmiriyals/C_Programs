struct node{
	struct node* left;
	struct node* right;
	int data;
};

struct node* nn(int data);

void insertIter(struct node** node, int data);

struct node* buildTree(int size);

int size(struct node* node);

int maxDepth(struct node* node);

int minValue(struct node* node);

void printinorder(struct node* node);

void printpostorder(struct node* node);

struct node* insert(struct node* node, int data);

void printpreorder(struct node* node);

int hasPathSum(struct node* node, int sum);

void printPaths(struct node* node);

void mirror(struct node* node);

void doubleTree(struct node* node);

int sameTree(struct node* a, struct node* b);

int countTrees(int numKeys);

int isBST(struct node* node, int min, int max);

void printinorderiterusingstack(struct node* node);

void InorderTraversalWithoutStackIter(struct node* node);

int inordersuccofBST(struct node* root, struct node* node);

int inorderpred(struct node* root, struct node* node);

int lowestCommonAncestor(struct node* root, int v1, int v2);

void preorderIterUsingStack(struct node* node);

void postorderIter(struct node* node);

void levelOrderTraversal(struct node* node);

void levelorderrecur(struct node* node);

int countLeafNode(struct node* node);

int checkchildsumproperty(struct node* node);

void convertTree(struct node* node);

int diameter(struct node* node);

int diameterOpt(struct node* node, int* height);

int isBalanced(struct node* node);

void levelorderSpiral(struct node* node);

int isBalancedOpt(struct node* node, int* height);

struct node* BuildTreeFromPreAndIn(int* pre, int* in, int instrt, int inEnd);

int maxWidth(struct node* node);

int IsFoldable(struct node* node);

void printNodesatKDistance(struct node* node, int k);

void printSorted(int arr[], int start, int end);

int kthsmallestnode(struct node* node, int k);

int NodeLevel(struct node* node, int data);

int getLevelUtil(struct node *node, int data, int level);

int printAncestors(struct node* node, int key);

void printRangeinBST(struct node* node, int k1, int k2);

struct node* TreeToList(struct node* node);

void printCircularList(struct node* node);

int isSumTree(struct node* node);

void maxSumRootToLeaf(struct node* node, int sum, int* max);

void nl();


