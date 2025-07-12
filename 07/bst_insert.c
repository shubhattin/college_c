
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *create_node(int data) {
  Node *tr = (Node *)malloc(sizeof(Node));
  tr->data = data;
  tr->right = NULL;
  tr->left = NULL;
  return tr;
}

void inorder(Node *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d, ", node->data);
    inorder(node->right);
  }
}

void insert(Node *root, int num) {
  Node *prev = NULL;
  while (root != NULL) {
    prev = root;
    if (root->data == num) {
      printf("Number already exists, insert failed!\n");
      return;
    } else if (root->data > num)
      root = root->left;
    else
      root = root->right;
  }
  Node *new = create_node(num);
  printf("prev: %d\n", prev->data);
  if (prev->data < num)
    prev->right = new;
  else
    prev->left = new;
}

int main() {
  Node *root = create_node(9);
  Node *n1 = create_node(3);
  Node *n2 = create_node(20);
  root->left = n1;
  root->right = n2;

  // n1
  Node *n3 = create_node(1);
  Node *n4 = create_node(6);
  n1->left = n3;
  n1->right = n4;

  // n2
  Node *n5 = create_node(22);
  n2->left = create_node(19);
  n2->right = n5;

  printf("Inorder Traversal: \n");
  inorder(root);
  printf("\n");
  int num;
  printf("Enter number: ");
  scanf("%d", &num);
  insert(root, num);

  printf("After Inorder Traversal: \n");
  inorder(root);
  printf("\n");

  return 0;
}
