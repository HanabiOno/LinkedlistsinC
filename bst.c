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

bool bst_contains(int i, BT *bst){
  if (bst == NULL){
    return false;
  }
  if (bst->item == i){
    return true;
  }
  if (bst->item>i){
    return bst_contains(i, bst->left);
  }
  if (bst->item<i){
    return bst_contains(i, bst->right);
  }
}

void print_bst(BT *bst){
  if (bst != NULL){
    print_bst(bst->left);
    printf("%d ", bst->item);
    print_bst(bst->right);
  }
}

void main(){
  BT* bst = bst_insert_randoms(20);
  print_bst(bst);
  printf("\n");
  int i;
  for (i = 0; i < 50; i++){
    if (bst_contains(i, bst)){
      printf("This bst contains: %d\n", i);
    }
  }
}
    
  
