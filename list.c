#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode *list_prepend(ListNode *head, void *data){
  ListNode *old_head = head;
  if(head == NULL){
    head = calloc(1,sizeof(*head));
    CHECK_MALLOC(head);
  } else {
    head = calloc(1,sizeof(*head));
    CHECK_MALLOC(head);
  }
  head->data = data;
  head->next = old_head;
  return head;
}

void list_foreach(ListNode *head, void (*callback)(void*)){
  if(head == NULL) return;
  callback(head->data);
  list_foreach(head->next,callback);
}

