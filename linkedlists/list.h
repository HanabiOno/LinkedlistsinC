#include <stdbool.h> 


typedef struct cell {
  int first;
  struct cell *rest;
} list;

list * make_random_list(int length);
int list_length(list *list);
bool ascending(list *l);  
void print_list(list *list);
void free_list(list *list);  
