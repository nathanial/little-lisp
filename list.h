#include "util.h"

typedef struct list_node {
  void *data;
  struct list_node *next;
} ListNode;

ListNode *list_prepend(ListNode *head, void *data);
void list_foreach(ListNode *head, void (*callback)(void*));
  
