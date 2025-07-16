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

int paren_match(char text[]) {
  int i;
  Stack *st = init_stack();
  for (i = 0; i < strlen(text); i++) {
    char ch = text[i];
    if (ch == '(')
      push(st, '(');
    else if (ch == ')')
      pop(st);
  }
  return is_empty(st);
}

int main() {
  char text[] = "(a+v)((d))";
  printf("Parenthesis Mathched Status: %d\n", paren_match(text));
  return 0;
}
