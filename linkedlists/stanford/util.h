
struct node{
	int data;
	struct node* next;
};

struct Tnode{
	int data;
	struct Tnode* left;
	struct Tnode* right;
};

struct node* nn(int data);

void push(struct node** node, int data);

void buildlistathead(struct node** head, int numEle);

void printlist(struct node* node, char* s);

struct node* buildlistattailbydummy(int numEle);

struct node* buildlistattailbyref(int numEle);

int listlen(struct node* node);

int pop(struct node** node);

void deletelist(struct node** node);

int getNth(struct node* node, int n);

void insertnth(struct node** node, int n, int data);

struct node* buildlistinsortedorder(int numEle);

void SortedInsertbydata(struct node** node, int data);

void sortedinsert(struct node** node, struct node* newNode);

void insertsort(struct node** href);

void append(struct node** aref, struct node** bref);

void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef);

void removeduplicates(struct node* node);

void movenode(struct node** src, struct node** dest);

void RightRotate(struct node** node, int k);

void alternatingsplit(struct node* node, struct node** aref, struct node** bref);

struct node* shufflemerge(struct node* a, struct node* b);

struct node* sortedmerge(struct node* a, struct node* b);

void mergesort(struct node** href);

struct node* sortedintersect(struct node* a, struct node* b);

void reverse(struct node** href);

void revrecur(struct node** href);

void delnodeGivenOnlyAPointerToTheNode(struct node* node);

int middlenode(struct node* head);

int NthNodeFromEnd(struct node* head, int n);

int detectloop(struct node* node);

int ispalindrome(struct node* node);

int ispalindromerecur(struct node** left, struct node* right);

int intersectionpoint(struct node* a, struct node* b);

void splitcircularlist(struct node* node);

void movelastnodetofirst(struct node** nref);

void pairwiseswap(struct node* node);

void pairwiseswaprecur(struct node* node);

void deletealternatenodes(struct node* node);

int isidentical(struct node* a, struct node* b);

int isidenticalrecur(struct node* a, struct node* b);

struct node* reversebyknodes(struct node* node, int k);

void insertinsortedcircularlist(struct node** href, int data);

void printcircularlist(struct node* head);

struct node* reversealternateknodes(struct node* head, int k);

void deletenodeifgreatervalueonright(struct node** href);

void deletenodeifgreateronrightwithoutrev(struct node** href);

void seggregateevenodd(struct node** href);

struct node* addListbydigits(struct node* a, struct node* b);

struct Tnode* sortedlinkedlistTobalancedbinarytree(struct node* node);

void inorderTnode(struct Tnode* root);

void nl();
