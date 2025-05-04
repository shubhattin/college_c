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
  // as we are modiying the head itself, we also need to change the head
  // reference pointer
  Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

void insert_end(Node *head, int data) {
  Node *new_node = create_node(data);
  Node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = new_node;
}

void insert_middle(Node *head, int data, int index) {
  Node *new_node = create_node(data);
  int i = 0;
  Node *next = head;
  while (next != NULL) {
    if (i++ == index) {
      new_node->next = next->next;
      next->next = new_node;
      return;
      // ^ early return
    }
    next = next->next;
  }
  printf("\tIndex %d not found in Linked List\n", index);
}

void delete_head(Node **head) {
  Node *new_head = (*head)->next;
  free(*head);
  *head = new_head;
}

void delete_end(Node *head) {
  Node *next = head;
  Node *prev = NULL;
  while (next->next != NULL) {
    prev = next;
    next = next->next;
  }
  prev->next = NULL;
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
      free(tmp);
      return;
    }
    next = next->next;
  }
  printf("\tIndex %d not found in Linked List\n", index);
}

void print_lnk_list(Node *head) {
  Node *next = head;
  while (next != NULL) {
    printf("%d, ", next->data);
    next = next->next;
  }
}

int main() {
  Node *head = create_node(10);
  // inserting elements
  insert_head(&head, 21);
  insert_head(&head, 20);
  insert_end(head, 2);
  insert_end(head, 3);
  insert_end(head, 4);
  insert_end(head, 5);
  insert_end(head, 6);
  insert_head(&head, 1);
  insert_middle(head, 100, 3);
  printf("Linked List Elements After Insertion: \n");
  print_lnk_list(head);
  printf("\n");

  // This inserts the Node after Index 3 (after 4th element)

  // deleting nodes
  delete_head(&head);
  delete_end(head);
  delete_middle(head, 2);

  printf("Linked List Elements After Deletion: \n");
  print_lnk_list(head);
  printf("\n");
  return 0;
}
