typedef struct node {
  int item;
  struct node *left;
  struct node *right;
} BT;

BT* insert_bst(int i, BT *bst);
BT* bst_insert_randoms(int n);
bool bst_contains(int i, BT *bst);

