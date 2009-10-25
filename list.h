#include "util.h"
#ifndef LIST_H
#define LIST_H

typedef struct list_node {
  void *data;
  struct list_node *next;
} ListNode;

ListNode *list_prepend(ListNode *head, void *data);
void list_foreach(ListNode *head, void (*callback)(void*));
  
#endif LIST_H
