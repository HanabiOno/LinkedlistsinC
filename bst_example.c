#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "bst.c"

void main(){
  int n;
  printf("What size do you want the test BST to be?\n");
  scanf("%d", &n);
  printf("This is the order in which random nodes are put in the BST:\n");
  BT* bst = bst_insert_randoms(n, true);
  printf("\nThis is the depth of the tree: %d",bt_depth(bst));
  printf("\nThis is the bst in order:\n");
  print_bst(bst);
  printf("\nThis BST contains the following digits in the range [0,50):\n");
  int i;
  for (i = 0; i < 50; i++){
    if (bst_contains(i, bst)){
      printf("%d ", i);
    }
  }
  list* list = make_random_list(20);
  printf("\nThis is the bst depth first order (according to wikipedia):\n");
  print_list(bt_ints_depth_first(bst));
  printf("This is the depth when inserting 100 nodes inorder: %d\n", bt_depth(bst_insert_inorder(100)));
  printf("This is the depth when inserting 100 nodes randomly: %d\n", bt_depth(bst_insert_randoms(100, false))); 
}
