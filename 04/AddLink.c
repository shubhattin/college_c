#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}
void insert_head(Node **head, int data) {
  Node *new_head = create_node(data);
  new_head->next = *head;
  *head = new_head;
}
void insert_end(Node **head, int data) {
  if (*head == NULL)
    return insert_head(head, data);
  Node *next = *head;
  while (next->next != NULL) {
    next = next->next;
  }
  next->next = create_node(data);
}

void print_list(Node *head) {
  Node *next = head;
  if (head != NULL)
    while (next != NULL) {
      printf("%d", next->data);
      next = next->next;
      if (next != NULL)
        printf(" -> ");
    }
  else
    printf("Empty List!");
}

Node *add_lists(Node **list1, Node **list2) {
  Node *add_list = NULL;
  int val;
  Node *l1 = *list1, *l2 = *list2;
  while (l1 != NULL || l2 != NULL) {
    val = 0;
    if (l1 != NULL) {
      val += l1->data;
      l1 = l1->next;
    }
    if (l2 != NULL) {
      val += l2->data;
      l2 = l2->next;
    }
    insert_end(&add_list, val);
  }
  return add_list;
}

int main() {
  Node *list1 = NULL;
  Node *list2 = NULL;

  // list1
  insert_end(&list1, 23);
  insert_end(&list1, 7);
  insert_end(&list1, 1);

  // list2
  insert_end(&list2, 77);
  insert_end(&list2, 2);

  Node *added_list = add_lists(&list1, &list2);
  printf("Sum List:\n");
  print_list(added_list);
  printf("\n");
}
