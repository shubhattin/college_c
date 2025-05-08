#include <stdio.h>
#include <stdlib.h>

#define S_SIZE 30

typedef struct Stack {
  int pos;
  char arr[S_SIZE];
} Stack;

void push(Stack *stk, char val) {
  if (stk->pos + 1 >= S_SIZE) {
    printf("Stack Overflow!\n");
    return;
  }
  stk->arr[++stk->pos] = val;
}

char pop(Stack *stk) {
  if (stk->pos == -1) {
    printf("Stack Underflow!\n");
    return '\0';
  }
  return stk->arr[stk->pos--];
}

void display_binary(int);

int main() {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);
  display_binary(num);

  return 0;
}

void display_binary(int num) {
  Stack *st = (Stack *)malloc(sizeof(Stack));
  st->pos = -1;
  int rem;

  while (num != 0) {
    rem = num % 2;
    num /= 2;
    push(st, rem);
  }

  printf("Binary Representation: ");
  while (st->pos != -1) {
    printf("%d", pop(st));
  }
  printf("\n");
}
