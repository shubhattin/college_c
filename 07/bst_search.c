#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
  int data;
  struct Tree *left;
  struct Tree *right;
} Tree;

Tree *create_node(int data) {
  Tree *tr = (Tree *)malloc(sizeof(Tree));
  tr->data = data;
  tr->right = NULL;
  tr->left = NULL;
  return tr;
}

void inorder(Tree *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d, ", node->data);
    inorder(node->right);
  }
}

int search(Tree *node, int num) {
  if (node != NULL) {
    if (node->data == num)
      return 1;
    else if (node->data > num)
      return search(node->left, num);
    else if (node->data < num)
      return search(node->right, num);
  }
  return 0;
}

int main() {
  Tree *root = create_node(9);
  Tree *n1 = create_node(3);
  Tree *n2 = create_node(19);
  root->left = n1;
  root->right = n2;

  // n1
  Tree *n3 = create_node(1);
  Tree *n4 = create_node(6);
  n1->left = n3;
  n1->right = n4;

  // n2
  Tree *n5 = create_node(20);
  n2->right = n5;

  printf("Inorder Traversal: \n");
  inorder(root);
  printf("\n");
  int num;
  printf("Enter number: ");
  scanf("%d", &num);
  printf("Search Result: %d\n", search(root, num));

  return 0;
}
