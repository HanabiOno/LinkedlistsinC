#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

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

BT* bst_insert_randoms(int n){
  BT *bst;
  int i;
  
  bst = NULL;
  while(n--){
    i = rand() % 100;
    bst = insert_bst(i, bst);
  }
  return bst;
}
