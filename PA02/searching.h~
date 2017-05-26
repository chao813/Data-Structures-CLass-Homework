#define MAX 10000000

typedef struct _node{
  long value;
  struct _node *next;
  long balance;
  struct _node *left;
  struct _node *right;
} Node; 

typedef struct _stack{
  long top;
  Node* elements[MAX];
} Stack;

typedef struct _queue{
  int size;
  //long capacity;
  int rear;
  int front;
  //Node **array; 
  Node * array[MAX];
} Queue;

Node *Load_File(char *Filename, int *Size);
Node *Construct_BST(Node *list);
long Print_BST_BF(char *Filename, Node *tree);
long Print_BST_Preorder(char *Filename, Node *tree);
long Print_BST_Inorder(char *Filename, Node *tree);
long Print_BST_Postorder(char *Filename, Node *tree);
Node *Balance_BST(Node *tree);
int Search_List(Node *list, long key, double *N_Comp);
int Search_Tree(Node *tree, long key, double *N_Comp);
int Search_Tree(Node *balanced_tree, long key, double *N_Comp);
void node_print(Node *list);
Node *insert(Node *root, Node *list);
int Is_Empty(Stack *stack);
int Push(Stack *stack, Node *node);
Node *Pop(Stack *stack);
Node *Stacktop(Stack *stack);
void Stackin(Stack *stack);
void Insertionsort(Node **list);
void sortedinsert(Node **list, Node *newnode);
//Node *sortedtobstrecur(Node **list, int n);
int countnodes(Node *head);
void enqueue(Queue *queue, Node *tree);
Node *dequeue(Queue *queue);
int Empty(Queue *queue);
void preorders(Node *tree);
void free_all(Node *tree);
Node *createNode(int value);
void free_list(Node *list);
Node *createNodes(long value);

Node *sortedtobstrecur(Node **list, int start, int end);
