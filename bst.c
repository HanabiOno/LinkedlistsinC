#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include "linkedlists/list.c"
#include "time.h"

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

//Use srand instead of rand to produce different numbers everything you run it.
BT* bst_insert_randoms(int n){
  BT *bst;
  int i;
  
  bst = NULL;
  srand(time(0));
  while(n--){
    i = rand() % 100;
    printf("%d ",i);
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



void print_bst(BT *bst){
  if (bst != NULL){
    print_bst(bst->left);
    printf("%d ", bst->item);
    print_bst(bst->right);
  }
}

void main(){
  int n;
  printf("How long do you want the test BST to be?\n");
  scanf("%d", &n);
  printf("This is the order in which random nodes are put in the BST:\n");
  BT* bst = bst_insert_randoms(n);
  printf("\nThis is the bst in order:");
  print_bst(bst);
  printf("\nThis BST contains the following digits in the range [0,50):\n");
  int i;
  for (i = 0; i < 50; i++){
    if (bst_contains(i, bst)){
      printf("%d ", i);
    }
  }
  list* list = make_random_list(20);
  printf("\nThis is the bst depth first order (according to wikipedia):/n");
  print_list(bt_ints_depth_first(bst));
}
    
  
