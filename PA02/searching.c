#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "searching.h"

Node *Load_File(char *Filename, int *Size){
  FILE *inputfile = fopen(Filename, "r");
  fseek(inputfile, 0, SEEK_SET);
  long ch = 0;
  Node *list = 0;
  if(fscanf(inputfile, "%ld", &ch) == 1){
    list = createNodes(ch);
    (*Size)++;
  }
  while(fscanf(inputfile, "%ld", &ch) == 1){
    Node *newnode = createNodes(ch);
    newnode->next = list; 
    list = newnode;
    (*Size)++;
  }


  /*long a = 0;
  while(fscanf(inputfile, "%ld", &a) == 1){
    (*Size)++;
  }
  long elements[*Size];
  fseek(inputfile, 0, SEEK_SET);
  *Size = 0;

  while(fscanf(inputfile, "%ld", &(elements[*Size])) == 1){
    (*Size)++;
  }
  //printf("%d\n", *Size);
  Node *list = malloc(sizeof(Node));// * (*Size));
  list -> right = NULL;
  list -> left = NULL;
  list -> value = 0;
  Node* temper = list;
  
  int i = 0;
  for(i = *Size - 1; i >= 0; i--){
    list->value = elements[i];
    if(i != 0) {
      list -> next = NULL;
      list->next = malloc(sizeof(Node));
      list = list->next;
      list -> right = NULL;
      list -> left = NULL;
    }
    else {
     list -> next = malloc(sizeof(Node));
     list -> next = NULL; 
     list -> right = NULL;
     list -> left = NULL;
    }
  }
  list = temper;*/
  fclose(inputfile);
  return list;
}

void node_print(Node *list){
   while (list != NULL) {
     printf("%ld",list->value);
      fprintf(stdout, "->");
      list = list->next;
   }  
   fprintf(stdout, "NULL\n");
}

Node *insert(Node *root, Node *list){
  if(root == NULL){
    return list; 
  }
  
  if((list->value) < (root->value)){
    root->left = insert(root->left, list);
  } 
  else {
    root->right = insert(root->right, list);
  }
  return root;
}

Node *Construct_BST(Node *list){
  Node *temp = NULL;
  temp = list;
  list = list->next;
  while(list){
    insert(temp, list);
    list = list->next;
  }
  return temp;
}

long Print_BST_BF(char *Filename, Node *tree){
  FILE *breadthfirst = fopen(Filename, "w");
  fseek(breadthfirst, 0, SEEK_SET);
  int depth = 0;
  Node *newnode; 
  Queue *queue = malloc(sizeof(Queue));
  //queue = createqueue();
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;
  enqueue(queue, tree);
  while(!Empty(queue)){
    newnode = dequeue(queue);
    if(newnode != NULL){
      depth++;
      fprintf(breadthfirst, "%ld\n", newnode->value);
      enqueue(queue, newnode->left);
      enqueue(queue, newnode->right);
    }
  }
  fclose(breadthfirst);
  free(queue);
  return depth;
}

void preorders(Node *tree){
  if(tree != NULL){
    printf("%ld", tree->value);
    preorders(tree->left);
    preorders(tree->right);
  }
}

long Print_BST_Preorder(char *Filename, Node *tree){
  //printf("%ld", tree->value);
  FILE *preorder = fopen(Filename, "w");
  fseek(preorder, 0, SEEK_SET);
  int depth = 0;
  Node *newnode = NULL;
  Stack *stack = malloc(sizeof(Stack));
  Stackin(stack);
  Push(stack, tree);
  while(!Is_Empty(stack)){
    newnode = Pop(stack);
    if(newnode != NULL){
      fprintf(preorder, "%ld\n", newnode->value);
      depth++;
      Push(stack, newnode->right);
      Push(stack, newnode->left);
    }
  } 
  fclose(preorder);
  free(stack);
  return depth;
}

long Print_BST_Inorder(char *Filename, Node *tree){
  FILE *inorder = fopen(Filename, "w");
  fseek(inorder, 0, SEEK_SET);
  int depth = 0;
  Node *newnode = NULL;
  Stack *stack = malloc(sizeof(Stack));
  Stackin(stack);
  newnode = tree;
  do {
    while(newnode != NULL){
      Push(stack, newnode);
      newnode = newnode->left;
    }
    if(!Is_Empty(stack)){
      newnode = Pop(stack);
      depth++;
      fprintf(inorder, "%ld\n", newnode->value);
      newnode = newnode->right;
    }
  } while(!Is_Empty(stack) || newnode != NULL);
  fclose(inorder);
  free(stack);
  return depth;
}


long Print_BST_Postorder(char *Filename, Node *tree){
  FILE *postorder = fopen(Filename, "w");
  fseek(postorder, 0, SEEK_SET);
  int depth = 0;
  Stack *stack = malloc(sizeof(Stack));
  Stackin(stack);
  do {
    while(tree){
      if(tree->right){
	Push(stack, tree->right);
      }
      Push(stack, tree);
      tree = tree->left;
    }
    tree = Pop(stack);
    if(tree->right && stack->elements[stack->top] == tree->right){
      Pop(stack);
      Push(stack, tree);
      tree = tree->right;
    }
    else {
      depth++;
      fprintf(postorder, "%ld\n", tree->value);
      tree = NULL;
    }
  }while(!Is_Empty(stack));
  fclose(postorder);
  free(stack);
  return depth;
}

void Insertionsort(Node **list){
  Node *sorted = NULL;
  Node *current = *list;
  //printf("%ld", (*list)->value);
  //Node **head = NULL;
  //head = list;
  while(current != NULL){
    Node *next = current->next;
    sortedinsert(&sorted, current);
    current = next;
  }
  *list = sorted;
  //Print_BST_Preorder("a.txt", (*list));
  //printf("%ld", (*list)->value);
  //list = head;
  //node_print(*list);
}
void sortedinsert(Node **list, Node *newnode){
  Node *current;
  //Node **head = NULL;
  //head = list;
  if(*list == NULL || (*list)->value >= newnode->value){
    newnode->next = *list;
    *list = newnode;
  }
  else {
    current = *list;
    while(current->next != NULL && current->next->value < newnode->value){
      current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
  }
  //list = head;
}
/*Node *sortedtobstrecur(Node **list, int n){
  if(n <= 0){
    return NULL;
  }
  Node *left = sortedtobstrecur(list, n/2);
  Node *root = createNode((*list)->value);
  //malloc(sizeof(Node));
  //root->value = *list->value;
  //root->value = list->value;
  root->left = left;
  *list = (*list)->next;
  root->right = sortedtobstrecur(list, n-(n/2)-1);
  return root;
}*/

Node *createNode(int value){
  Node *node = malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int countnodes(Node *head){
  int count = 0;
  Node *temp = head;
  while(temp){
    temp = temp->next;
    count++;
  }
  return count;
}

/*Node *Balance_BST(Node *tree){
  int n = countnodes(tree);
  sortedtobstrecur(&tree, n);
  return tree;
  }*/

int Search_List(Node *list, long key, double *N_Comp){
  Node *current = list;
  while(current != NULL){
    if(current->value == key){
      (*N_Comp)++;
      return 1;
    }
    current = current->next;
    (*N_Comp)++;
  }
  return 0;
}

int Search_Tree(Node *tree, long key, double *N_Comp){
  if(tree == NULL){
    (*N_Comp)++;
    return 0;
  }
  (*N_Comp)++;
  if(key == tree->value){
    return 1;
  } else if(key < tree->value){
    Search_Tree(tree->left, key, N_Comp);
  } else if(key > tree->value){
    Search_Tree(tree->right, key, N_Comp); 
  }
  return 0;
}

int Is_Empty(Stack *stack){
  return(stack->top < 0);
}

int Push(Stack *stack, Node *node){
  if(stack->top >= MAX - 1){
    return 0; 
  }
  stack->elements[++(stack->top)] = node;
  return 1;
}

Node *Pop(Stack *stack){
  Node *node = NULL;
  node = stack->elements[stack->top];
  stack->top--;
  return node;
}

Node *Stacktop(Stack *stack){
  return(stack->elements[stack->top]);
}

void Stackin(Stack *stack){
  stack->top = -1;
}

void enqueue(Queue *queue, Node *tree){
  queue->size++;
  //if(queue->size == queue->capacity){
  //  return;
  //}
  //queue->rear = (queue->rear + 1) % queue->capacity;
  //queue->array[queue->rear] = tree;
  queue->rear = queue->rear + 1;
  if(queue->rear == MAX){
    queue->rear = 0;
  }
  queue->array[queue->rear] = tree;
}

Node *dequeue(Queue *queue){
  if(Empty(queue)){
    return NULL;
  }
  Node *node = NULL;
  queue->size--;
  node = queue->array[queue->front];
  //Node *node = queue->array[queue->front];
  //queue->front = (queue->front + 1) % queue->capacity;
  //queue->size = queue->size - 1;
  queue->front++;
  if(queue->front >= MAX){
    queue->front = 0;
  }
  return node;
}

int Empty(Queue *queue){
  return(queue->size == 0);
}

void free_all(Node *tree){
  if(tree == NULL){
    return;
  }
  free_all(tree->left);
  free_all(tree->right);
  free(tree);
}

void free_list(Node *list){
  while(list != NULL){
    Node *temp = list->next;
    //free(list->value);
    free(list);
    list = temp;
  }
}

Node *createNodes(long value){
  Node *nn = malloc(sizeof(Node));
  nn->value = value;
  nn->next = NULL;
  nn->left = NULL;
  nn->right = NULL;
  return nn;
}

Node *Balance_BST(Node *tree){
  int n = countnodes(tree);
  //printf("%d", n);
  return sortedtobstrecur(&tree, 0, n-1);
}

Node *sortedtobstrecur(Node **list, int start, int end){
  if(start > end){
    return NULL;
  }
  int mid = start + (end - start)/2;
  Node *leftchild = sortedtobstrecur(list, start, mid-1);
  Node *parent = createNodes((*list)->value);
  parent->left = leftchild;
  *list = (*list)->next;
  parent->right = sortedtobstrecur(list, mid+1, end);
  return parent;
}
