#include "reader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int skip_spaces(char *text){
  int i = 0;
  while(text[i] != '\0'){
    if(text[i] == ' ' || text[i] == '\r' || 
       text[i] == '\n' || text[i] == '\t'){
      i++; 
    } else {
      return i;
    }
  }
  return i;
}

bool is_num(char *text){
  int tlen, i;
  tlen = strlen(text);
  for(i = 0; i < tlen; i++){
    if(text[i] > '9' || text[i] < '0'){
      return false;
    }
  }
  return true;
}

bool is_alpha(char c){
  return ((c > 'a' && c < 'z') ||
	  (c > 'A' && c < 'Z'));
}

bool is_operator(char c){
  return ((c == '+' || c == '-' || c == '/'));
}

bool is_symbol(char *text){
  int tlen, i;
  tlen = strlen(text);
  for(i = 0; i < tlen; i++){
    char c = text[i];
    if(!is_alpha(c) && !is_operator(c)){
      return false;
    }
  }
  return true;
}

char *lisp_typeof(LispObject *obj){
  switch(obj->type){
  case LIST:
    return "LIST";
  case STRING:
    return "STRING";
  case NUMBER:
    return "NUMBER";
  case SYMBOL:
    return "SYMBOL";
  }
  return NULL;
}
    
void lisp_read(char *text, LispObject *result) {
  int tlen, start;
  char *trimmed_text;

  tlen = strlen(text);
  start = skip_spaces(text);
  trimmed_text = text + start;

  if(is_num(trimmed_text)){
    result->type = NUMBER;
  } else if(is_symbol(trimmed_text)){
    result->type = SYMBOL;
  } else {
    fprintf(stderr, "lisp reader failed on: %s\n", text);
    exit(1);
  }
}
