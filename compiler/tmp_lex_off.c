#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum token_TokenKind { TOK_EOF };
typedef enum token_TokenKind token_TokenKind_t;

struct token_Token {
  token_TokenKind_t kind;
  int32_t line;
  int32_t col;
  int32_t int_val;
  double float_val;
  uint8_t *ident;
  int32_t ident_len;
};
struct lexer_Lexer {
  size_t pos;
  int32_t line;
  int32_t col;
};
struct lexer_LexerResult {
  struct lexer_Lexer next_lex;
  struct token_Token tok;
  size_t token_start;
};

int main(void) {
  printf("sizeof(lexer_Lexer)=%zu offsetof(pos)=%zu\n",
         sizeof(struct lexer_Lexer), offsetof(struct lexer_Lexer, pos));
  printf("sizeof(Token)=%zu\n", sizeof(struct token_Token));
  printf("offsetof(LexerResult,next_lex)=%zu offsetof(tok)=%zu offsetof(token_start)=%zu next_lex.pos=%zu\n",
         offsetof(struct lexer_LexerResult, next_lex),
         offsetof(struct lexer_LexerResult, tok),
         offsetof(struct lexer_LexerResult, token_start),
         offsetof(struct lexer_LexerResult, next_lex.pos));
  printf("offsetof(LexerResult,tok.ident_len)=%zu\n",
         offsetof(struct lexer_LexerResult, tok.ident_len));
  return 0;
}
