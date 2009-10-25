#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
  TOK_LPAREN,
  TOK_RPAREN,
  TOK_SYMBOL,
  TOK_NUMBER
} TokenType;

typedef struct {
  TokenType type;
  char *value;
} Token;

Token *token_create(TokenType type, char *value);
char *token_type_string(Token *token);

#endif
