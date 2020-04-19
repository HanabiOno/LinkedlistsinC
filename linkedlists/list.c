#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
