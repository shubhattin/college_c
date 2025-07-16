
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

int height(Tree *root) {
  if (root == NULL)
    return -1;
  else {
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
  }
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
  n4->left = create_node(4);

  // n2
  Tree *n5 = create_node(20);
  n2->right = n5;

  printf("Inorder Traversal: \n");
  inorder(root);
  printf("\n");
  printf("Tree Height: %d\n", height(root));

  return 0;
}
