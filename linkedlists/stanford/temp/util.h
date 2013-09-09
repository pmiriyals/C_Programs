
struct node{
	int data;
	struct node* next;
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

void frontbacksplit(struct node* node, struct node** front, struct node** back);

void removeduplicates(struct node* node);

void movenode(struct node** src, struct node** dest);

void alternatingsplitinrev(struct node* src, struct node** aref, struct node** bref);

void alternatingsplit(struct node* src, struct node** aref, struct node** bref);

void nl();
