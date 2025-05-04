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

void insert_middle(Node *head, int data, int index) {
  Node *new_node = create_node(data);
  int i = 0;
  Node *next = head;
  do {
    if (i++ == index) {
      new_node->next = next->next;
      next->next = new_node;
      return;
      // ^ early return
    }
    next = next->next;
  } while (next != head);
  printf("\tIndex %d not found in Linked List\n", index);
}

void delete_head(Node **head) {
  Node *last = (*head)->next;
  Node *new_head = (*head)->next;
  while (last->next != *head) {
    last = last->next;
  }
  last->next = new_head;
  free(*head);
  *head = new_head;
}

void delete_end(Node *head) {
  Node *last = head->next;
  Node *prev = NULL;
  while (last->next != head) {
    prev = last;
    last = last->next;
  };
  free(last);
  prev->next = head;
}

void delete_middle(Node *head, int index) {
  int i = 0;
  Node *node = head;
  Node *tmp = NULL;
  while (node->next != NULL) {
    if (++i == index && (node->next != NULL || node->next == head)) {
      tmp = node->next;
      node->next = tmp->next;
      free(tmp);
      return;
    }
    node = node->next;
  }
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
  insert_head(&head, 19);
  insert_end(head, 2);
  insert_end(head, 3);
  insert_middle(head, 5, 1);
  insert_middle(head, 90, 6);
  printf("Linked List Elements After Insertion: \n");
  print_lnk_list(head);
  printf("\n");

  // This inserts the Node after Index 3 (after 4th element)

  // deleting nodes
  delete_head(&head);
  delete_end(head);
  delete_middle(head, 3);

  printf("Linked List Elements After Deletion: \n");
  print_lnk_list(head);
  printf("\n");
  return 0;
}
