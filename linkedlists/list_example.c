#include <stdio.h>
#include <stdlib.h>
#include "list.c"

void main (int argc, char** argv) {
  list *list;
  int length;

  length = atoi(argv[1]);
  list = make_random_list(length);
  print_list(list);
  printf("Length: %d\n", list_length(list));
  printf("%s", ascending(list) ? "true" : "false");
  free_list(list);
}
