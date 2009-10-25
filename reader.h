typedef enum {
  LISP_SEXP,
  LISP_STRING,
  LISP_NUMBER,
  LISP_SYMBOL
} LispType;  

typedef struct lisp_obj {
  LispType type;
  struct lisp_obj *members;
  char *string_value;
  char *symbol_value;
  int int_value;
} LispObject;

void lisp_read(char *text, LispObject *result);
