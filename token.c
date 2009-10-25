#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token *token_create(TokenType type, char *value){
  Token *t = calloc(1,sizeof(Token));
  char *s = calloc(100, sizeof(char));
  strcpy(s,value);
  t->type = type;
  t->value = s;
  return t;
}
char *token_type_string(Token *token) {
  switch(token->type){
  case TOK_LPAREN:
    return "TOK_LPAREN";
  case TOK_RPAREN:
    return "TOK_RPAREN";
  case TOK_SYMBOL:
    return "TOK_SYMBOL";
  case TOK_NUMBER:
    return "TOK_NUMBER";
  default:
    fprintf(stderr, "token type not recognized!");
    exit(1);
  }
}
