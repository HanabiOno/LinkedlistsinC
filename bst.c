#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "bst.h"


//Step 3: returns a Boolean which is true if the elements of the list are (strictly) in ascending order and false otherwise
BT* insert_bst(int i, BT *bst){
  struct node *n;
  if (bst==NULL){
    n = (struct node *) malloc(sizeof(struct node));
    n->item = i;
    n->left = NULL;
    n->right = NULL;
    bst = n;}
  else if (i<bst->item){
    bst->left = insert_bst(i, bst->left);}
  else {bst->right = insert_bst(i, bst->right);}
  return bst;
}

//Step 4: returns a pointer to a BST which contains n random integers in the range [0,100).
//Use srand instead of rand to produce different numbers everything you run it.
BT* bst_insert_randoms(int n, bool print){
  BT *bst;
  int i;
  
  bst = NULL;
  srand(time(0));
  while(n--){
    i = rand() % 100;
    if (print){ printf("%d ", i);}
    bst = insert_bst(i, bst);
  }
  return bst;
}

//Helper function for step 5
list* append(list *left, list *right){
  if (!left){
    return right;
  }
  if (!right){
    return left;
  }
  list* pleft = left;
  while(pleft->rest){
    pleft = pleft->rest;
  }
  pleft->rest = right;
  return left;
}

//Step 5: returns a pointer to a linked list of the integers contained in the BT in depth first order as described on [wikipedia] (https://nl.wikipedia.org/wiki/Depth-first_search)
list* bt_ints_depth_first(BT *bt){
  if (bt == NULL){
    return NULL;
  }

  struct cell *c;
  c = (struct cell *) malloc(sizeof(struct cell));
  c->first = bt->item;
  c->rest = append(bt_ints_depth_first(bt->left),
                   bt_ints_depth_first(bt->right));
  return c;
}
    
//Step 7: returns a Boolean which is true iff the BST contains the integer.
bool bst_contains(int i, BT *bst){
  if (bst == NULL){
    return false;
  }
  if (bst->item == i){
    BT* bst_i = bst;
    return true;
  }
  if (bst->item>i){
    return bst_contains(i, bst->left);
  }
  if (bst->item<i){
    return bst_contains(i, bst->right);
  }
}

//Step 8: returns the maximum of the depths of its two children or 1 in the case that the BT has no children.
int bt_depth(BT *bt){
  if (bt == NULL){
    return 0;
  }
  else {
    int ldepth = bt_depth(bt->left);
    int rdepth = bt_depth(bt->right);
    if (ldepth > rdepth) {
      return(ldepth+1);
    }
    else {
      return(rdepth+1);
    }
  }
}

//Step 9: Show that inserting the integers 0...99 in that order into an empty BST results in a tree which is much deeper than inserting 100 random values from the range 0...99 into an empty BST.
BT* bst_insert_inorder(int n){
  BT *bst;
  int i;

  bst=NULL;
  for(i = 0; i < n; i++){
    bst = insert_bst(i,bst);
  }
  return bst;
}

//Function to print out the bst in order.
void print_bst(BT *bst){
  if (bst != NULL){
    print_bst(bst->left);
    printf("%d ", bst->item);
    print_bst(bst->right);
  }
}

