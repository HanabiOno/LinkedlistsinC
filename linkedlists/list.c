#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>


list* make_random_list(int length) {
  list *list;
  struct cell *c;

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
  int curitem;
  int nextitem;

  next = l->rest;
  while(next){
    printf("%d", l->first);
    curitem = l->first;
    nextitem = next->first;
    if (nextitem <= curitem){
      return false;
    next = next->rest;
    }
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


