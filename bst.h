typedef struct node {
  int item;
  struct node *left;
  struct node *right;
} BT;

BT* insert_bst(int i, BT *bst);

