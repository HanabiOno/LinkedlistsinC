#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>
#include <time.h>

list* make_random_list(int length) {
  list *list;
  struct cell *c;

  srand(time(0));
  list = NULL;
  while (length--) {
    c = (struct cell *) malloc(sizeof(struct cell));
    c->first = rand() % 100;
    c->rest = list;
    list = c;
  }
  return list;
}

int list_length(list *list) {
  int length = 0;

  while (list) {
    length++;
    list = list->rest;
  }

  return length;
}

bool ascending(list *l){
  list *next;
  int curitem = l->first;
  int nextitem;
  bool out;
  list *listcheck = l;

  if (list_length(l)<=1){
    return false;
  }
  next = listcheck->rest; 
  while(next){
    nextitem = next->first;
    if (nextitem <= curitem){
      return false;
    }
    listcheck = next;
    curitem = listcheck->first;
    next = next->rest;
  }
  return true;
}

void print_list(list *list) {
  while (list) {
    printf("%d ", list->first);
    list = list->rest;
  }
  printf("\n");
}

// Free the memory of all of the cells in list
void free_list(list *list) {
  struct cell *next;

  while (list) {
    next = list->rest;
    free(list);
    list = next;
  }
}


