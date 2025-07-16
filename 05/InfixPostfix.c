#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
  int top;
  char arr[MAX_SIZE];
} Stack;

Stack *init_stack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = -1;
  return s;
}
int is_empty(Stack *s) { return s->top == -1; }
int is_full(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *stk, char val) {
  if (stk->top + 1 >= MAX_SIZE) {
    printf("Stack Overflow!\n");
    return;
  }
  stk->arr[++stk->top] = val;
}

char pop(Stack *stk) {
  if (stk->top == -1) {
    printf("Stack Underflow!\n");
    return '\0';
  }
  return stk->arr[stk->top--];
}

char peek(Stack *s) {
  if (is_empty(s)) {
    printf("Empty Stack!\n");
    return '\0';
  }
  return s->arr[s->top];
}

int prece(char ch) {
  char OP[] = {'+', '-', '*', '/', '^'};
  int PR[] = {1, 1, 2, 2, 3};
  for (int i = 0; i < 5; i++)
    if (ch == OP[i])
      return PR[i];
  return 0;
}

char *infix_to_postfix(char text[]) {
  int len = strlen(text);
  char *post = (char *)malloc(sizeof(char) * (len + 1));
  int x = 0;
  Stack *st = init_stack();
  for (int i = 0; i < len; i++) {
    char ch = text[i];
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
      post[x++] = ch;
    else if (ch == '(')
      push(st, '(');
    else if (ch == ')') {
      while (peek(st) != '(') {
        post[x++] = pop(st);
      }
      pop(st);
    } else {
      int curr_prec = prece(ch);
      while (!is_empty(st) && curr_prec <= prece(peek(st))) {
        post[x++] = pop(st);
      }
      push(st, ch);
    }
  }
  while (!is_empty(st))
    post[x++] = pop(st);

  post[x + 1] = '\0';
  return post;
}

int main() {
  char text[100];
  printf("Infix Expression: ");
  fgets(text, sizeof(text), stdin);
  printf("Postfix Expression: %s\n", infix_to_postfix(text));
  return 0;
}
