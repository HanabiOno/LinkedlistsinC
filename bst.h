#include "linkedlists/list.c"

typedef struct node {
  int item;
  struct node *left;
  struct node *right;
} BT;

BT* insert_bst(int i, BT *bst);
BT* bst_insert_randoms(int n, bool print);
BT* bst_insert_inorder(int n);
bool bst_contains(int i, BT *bst);
list* append(list *left, list *right);
list* bt_ints_depth_first(BT *bt);
list* bt_ints_breadth_first(BT *bt);
void print_bst(BT *bst);
int bt_depth(BT *bt);


