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
  Node *node = *head;
  new_node->next = *head;
  while (node->next != *head) {
    node = node->next;
  }
  node->next = new_node;
  *head = new_node;
}

void insert_end(Node *head, int data) {
  Node *new_node = create_node(data);
  Node *node = head;
  new_node->next = head;
  while (node->next != head) {
    node = node->next;
  }
  node->next = new_node;
  new_node->next = head;
}

void print_lnk_list(Node *head) {
  Node *next = head;
  do {
    printf("%d, ", next->data);
    next = next->next;
  } while (next != head);
}

int main() {
  Node *head = create_node(10);
  head->next = head;
  // inserting elements
  insert_head(&head, 21);
  insert_head(&head, 20);
  insert_head(&head, 1);
  insert_end(head, 2);
  insert_end(head, 3);
  printf("Linked List Elements After Insertion: \n");
  print_lnk_list(head);
  printf("\n");

  // This inserts the Node after Index 3 (after 4th element)

  // deleting nodes

  printf("Linked List Elements After Deletion: \n");
  print_lnk_list(head);
  printf("\n");
  return 0;
}
