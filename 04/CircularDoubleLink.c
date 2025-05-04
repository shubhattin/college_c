#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void insert_head(Node **head, int data) {
  Node *new_node = create_node(data);
  new_node->next = *head;
  if (*head != NULL) {
    new_node->prev = (*head)->prev;
    (*head)->prev = new_node;
    (new_node->prev)->next = new_node;
  }
  *head = new_node;
}

void insert_end(Node *head, int data) {
  Node *new_node = create_node(data);
  new_node->prev = head->prev;
  (head->prev)->next = new_node;
  head->prev = new_node;
  new_node->next = head;
}

void insert_middle(Node *head, int data, int index) {
  Node *new_node = create_node(data);
  int i = 0;
  Node *next = head;
  do {
    if (i++ == index) {
      new_node->next = next->next;
      new_node->prev = next;
      (next->next)->prev = new_node;
      next->next = new_node;
      return;
      // ^ early return
    }
    next = next->next;
  } while (next != head);
  printf("\tIndex %d not found in Linked List\n", index);
}

void delete_head(Node **head) {
  Node *new_head = (*head)->next;
  Node *last = (*head)->prev;
  last->next = new_head;
  new_head->prev = last;
  free(*head);
  *head = new_head;
}

void delete_end(Node *head) {
  Node *last = head->prev;
  Node *last_prev = last->prev;
  head->prev = last_prev;
  last_prev->next = head;
  free(last);
}

void delete_middle(Node *head, int index) {
  int i = 0;
  Node *node = head;
  Node *tmp = NULL;
  while (node->next != NULL) {
    if (++i == index && (node->next != NULL || node->next == head)) {
      tmp = node->next;
      node->next = tmp->next;
      (tmp->next)->prev = node;
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
  head->prev = head;
  // inserting elements
  insert_head(&head, 2);
  insert_head(&head, 1);
  insert_head(&head, 9);
  insert_end(head, 18);
  insert_end(head, 17);
  insert_middle(head, 23, 2);
  insert_middle(head, 19, 5);

  printf("Linked List Elements After Insertion: \n");
  print_lnk_list(head);
  printf("\n");

  // This inserts the Node after Index 3 (after 4th element)

  // deleting nodes
  delete_head(&head);
  delete_head(&head);
  delete_end(head);
  delete_middle(head, 2);

  printf("Linked List Elements After Deletion: \n");
  print_lnk_list(head);
  printf("\n");
  return 0;
}
