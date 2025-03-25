#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_head(Node **head, int data) {
  Node *new_node = create_node(data);

  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void print_lnk_list(Node **head) {
  Node *next = *head;
  while (next != NULL) {
    printf("%d, ", next->data);
    next = next->next;
  }
}

int main() {
  Node *head = create_node(1);
  insert_head(&head, 2);
  insert_head(&head, 3);
  insert_head(&head, 4);
  insert_head(&head, 5);
  insert_head(&head, 6);

  printf("Linked List Elements: \n");
  print_lnk_list(&head);
  printf("\n");
  return 0;
}
