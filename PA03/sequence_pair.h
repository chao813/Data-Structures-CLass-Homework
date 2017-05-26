typedef struct _nrect{
  int numval; 
  double width;
  double height; 
  struct _node *next;
  double Xcord;
  double Ycord;
} Nrect; 

typedef struct _node{
  Nrect *rect;
  int numval;
} Node;

typedef struct _index{
  int numval;
  Nrect *rect;
  double Xcord;
  double Ycord;
} Index;


Node *createGraph(Node *node, int *seq1, int *seq2, int nblocks);
