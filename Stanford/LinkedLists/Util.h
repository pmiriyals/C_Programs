
struct node {
	int data;
	struct node* next;
};

struct node* newNode(int data);

void Push(struct node** head, int data);

struct node* BuildList();

int len(struct node* head);

void PrintList(struct node* head);

struct node* PushAtHead(int numNodes);

struct node* PushAtTailbyTail(int numNodes);

struct node* PushAtTailbyLocalRef(int numNodes);

struct node* PushAtTailbyDummy(int numNodes);

void MoveNode(struct node** a, struct node** b);

void Pop(struct node** head);

void DeleteList(struct node** head);

void FrontBackSplit(struct node** front, struct node** back, struct node* lst);

struct node* SortedMerge(struct node* a, struct node* b);

void Reverse(struct node** href);
