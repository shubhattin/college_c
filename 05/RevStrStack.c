#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 30

typedef struct Stack
{
    int pos;
    char arr[S_SIZE];
} Stack;

void push(Stack *stk, char val)
{
    if (stk->pos + 1 >= S_SIZE)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stk->arr[++stk->pos] = val;
}

char pop(Stack *stk)
{
    if (stk->pos == -1)
    {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stk->arr[stk->pos--];
}

int main()
{
    char text[S_SIZE], rev[S_SIZE];
    int i = 0;
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->pos = -1;

    printf("Enter text: ");
    scanf("%[^\n]", text);
    for (i = 0; i < strlen(text); i++)
    {
        push(st, text[i]);
    }
    for (i = 0; i < strlen(text); i++)
    {
        rev[i] = pop(st);
    }
    rev[i]='\0';
    printf("Revered Text: %s\n", rev);
    return 0;
}