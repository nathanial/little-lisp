#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "util.h"
#include "token.h"
#include <gdsl.h>

void test_scanner();
void test_scan_symbols();

int main(int argc, char *args[]){
  test_scanner();
  return 0;
}

void test_scanner(){
  test_scan_symbols();
}

void test_scan_symbols() {
  char *text = "123 foo (+ 1 2)";
  gdsl_list_t tokens = lisp_scan(text);
  gdsl_list_cursor_t cursor = gdsl_list_cursor_alloc(tokens);
  gdsl_list_cursor_move_to_head(cursor);
  while(1){
    Token *token = (Token*)gdsl_list_cursor_get_content(cursor);
    printf("token %s = %s\n", token_type_string(token), token->value);
    if(!gdsl_list_cursor_has_succ(cursor)){
	break;
    }
    gdsl_list_cursor_step_forward(cursor);
  }
  gdsl_list_cursor_free(cursor);
  gdsl_list_free(tokens);
}
  
  
