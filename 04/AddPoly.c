#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coeff;
  int power;
  struct Node *next;
} Node;

Node *create_node(int coeff, int power) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->coeff = coeff;
  node->power = power;
  node->next = NULL;
  return node;
}
void insert_head(Node **head, int coeff, int power) {
  Node *new_head = create_node(coeff, power);
  new_head->next = *head;
  *head = new_head;
}
void insert_end(Node **head, int coeff, int power) {
  if (*head == NULL)
    return insert_head(head, coeff, power);
  Node *next = *head;
  while (next->next != NULL) {
    next = next->next;
  }
  next->next = create_node(coeff, power);
}

void print_list(Node *head) {
  Node *next = head;
  if (head != NULL)
    while (next != NULL) {
      printf("%d,%d", next->coeff, next->power);
      next = next->next;
      if (next != NULL)
        printf("  ");
    }
  else
    printf("Empty List!");
}

Node *add_polynomials(Node **poly1, Node **poly2) {
  Node *p1 = *poly1;
  Node *p2 = *poly2;
  Node *add_list = NULL;

  while (p1 != NULL && p2 != NULL) {
    if (p1->power == p2->power) {
      int sum_coeff = p1->coeff + p2->coeff;
      if (sum_coeff != 0) // skip zero coefficient terms
        insert_end(&add_list, sum_coeff, p1->power);
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->power > p2->power) {
      insert_end(&add_list, p1->coeff, p1->power);
      p1 = p1->next;
    } else {
      insert_end(&add_list, p2->coeff, p2->power);
      p2 = p2->next;
    }
  }
  // Add remaining terms
  while (p1 != NULL) {
    insert_end(&add_list, p1->coeff, p1->power);
    p1 = p1->next;
  }
  while (p2 != NULL) {
    insert_end(&add_list, p2->coeff, p2->power);
    p2 = p2->next;
  }
  return add_list;
}

int main() {
  Node *ploy1 = NULL;
  Node *ploy2 = NULL;

  // Ploynomial 1: 23x^3 + 7x^2 + 1
  insert_end(&ploy1, 23, 3);
  insert_end(&ploy1, 7, 2);
  insert_end(&ploy1, 1, 0);

  // Polynomial 2: 77x^5 + 2x^3
  insert_end(&ploy2, 77, 4);
  insert_end(&ploy2, 2, 0);

  Node *added_list = add_polynomials(&ploy1, &ploy2);
  printf("Sum List:\n");
  print_list(added_list);
  printf("\n");
}
