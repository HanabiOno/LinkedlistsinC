#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void main (int argc, char** argv) {
  list *list;
  int length;

  length = atoi(argv[1]);
  list = make_random_list(length);
  print_list(list);
  if (ascending(list)){
    printf("The list is ascending\n");
  }
  printf("Length: %d\n", list_length(list));
  free_list(list);
}
