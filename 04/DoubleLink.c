#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *create_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void insert_head(Node **head, int data) {
  Node *new_head = create_node(data);
  new_head->next = *head;
  if (*head != NULL)
    (*head)->prev = new_head;
  *head = new_head;
}

void insert_end(Node *head, int data) {
  Node *new_node = create_node(data);
  Node *next = head;
  while (next->next != NULL) {
    next = next->next;
  }
  next->next = new_node;
  new_node->prev = next;
}

void insert_middle(Node *head, int data, int index) {
  Node *new_node = create_node(data);
  int i = 0;
  Node *next = head;
  while (next != NULL) {
    if (i++ == index) {
      new_node->next = next->next;
      next->next = new_node;
      new_node->prev = next;
      return;
      // ^ early return
    }
    next = next->next;
  }
  printf("\tIndex %d not found in Linked List\n", index);
}

void delete_head(Node **head) {
  Node *new_head = (*head)->next;
  new_head->prev = NULL;
  free(*head);
  *head = new_head;
}

void delete_end(Node *head) {
  Node *next = head;
  while (next->next != NULL) {
    next = next->next;
  }
  (next->prev)->next = NULL;
  free(next);
}

void delete_middle(Node *head, int index) {
  int i = 0;
  Node *next = head;
  Node *tmp = NULL;
  while (next != NULL) {
    if (++i == index && next->next != NULL) {
      tmp = next->next;
      next->next = tmp->next;
      tmp->prev = next;
      free(tmp);
      return;
    }
    next = next->next;
  }
  printf("\tIndex %d not found in Linked List\n", index);
}

void print_link_list(Node *head) {
  Node *next = head;
  while (next != NULL) {
    printf("%d, ", next->data);
    next = next->next;
  }
}

int main() {
  Node *head = NULL;

  // Insertion
  insert_head(&head, 2);
  insert_head(&head, 1);
  insert_end(head, 3);
  insert_end(head, 5);
  insert_end(head, 6);
  insert_middle(head, 4, 2);
  // after index 2 (after 3rd element)

  printf("Linked List after Insertion: \n");
  print_link_list(head);
  printf("\n");

  // Deletion
  delete_head(&head);
  delete_end(head);
  delete_middle(head, 2);

  printf("Linked List after Deletion: \n");
  print_link_list(head);
  printf("\n");

  return 0;
}
