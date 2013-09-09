
struct node{
	int data;
	struct node* next;
};

void push(struct node** head, int data);

int pop(struct node** head);

void nl();

int size(struct node* head);

void randomVal(int len, int* arr);

struct node* buildlistathead(int len);

struct node* buildlistattailbylocalref(int len);

void appendnode(struct node** head, int num);

struct node* buildlistattailbydummy(int len);

void printList(struct node* head);

void DeleteList(struct node** head);

//PROBLEMS

int getnth(struct node* head, int n);

void insertnth(struct node** headRef, int data, int ndx);

void sortedinsert(struct node** head, struct node* node);

void frontbacksplit(struct node* src, struct node** f, struct node** b);

void alternatingsplit(struct node* src, struct node** aref, struct node** bref);

void asplit(struct node* src, struct node** aref, struct node** bref);

struct node* shufflemerge(struct node** aref, struct node** bref);

struct node* sortedmerge(struct node* a, struct node* b);

void mergesort(struct node** aref);

void fbsplit(struct node* src, struct node** aref, struct node** bref);

struct node* sortedmerge(struct node* a, struct node* b);

struct node* sortnmerge(struct node* a, struct node* b);

void MergeSort(struct node** aref);

void reverse(struct node** aref);

void revrecur(struct node** aref);
