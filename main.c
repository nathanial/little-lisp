#include <stdio.h>
#include <string.h>
#include "reader.h"
#include "list.h"
#include "util.h"

void test_reader_symbols();
void test_reader();
void test_list();

int main(int argc, char *args[]){
  test_list();
  test_reader();
  return 0;
}

void test_reader(){
  LispObject number, list;
  test_reader_symbols();

  lisp_read("1234", &number);
  ASSERT(strcmp(lisp_typeof(&number),"NUMBER") == 0, "'1234' is a number");

  lisp_read("(+ 1 2)", &list);
  ASSERT(strcmp(lisp_typeof(&list), "LIST") == 0, "'(+ 1 2)' is a list");
}

void test_reader_symbols(){
  LispObject symbol;
  lisp_read("foo", &symbol);
  ASSERT(symbol.type == SYMBOL, "foo is a symbol");

  lisp_read("FOO", &symbol);
  ASSERT(symbol.type == SYMBOL, "FOO is a symbol");
  
  lisp_read("+-/", &symbol);
  ASSERT(symbol.type == SYMBOL, "+-/ is a symbol");
}

void test_list(){
  int count = 0;
  void list_counter(void *data){
    count += 1;
  }
  ListNode *node = list_prepend(NULL, "1");
  node = list_prepend(node, "2");
  node = list_prepend(node, "3");
  node = list_prepend(node, "4");
  list_foreach(node, list_counter);
  ASSERT(count == 4, "list length = 4");
}
  
