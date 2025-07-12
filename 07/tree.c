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

void preorder(Tree *node) {
  if (node != NULL) {
    printf("%d, ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(Tree *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d, ", node->data);
  }
}

void inorder(Tree *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d, ", node->data);
    inorder(node->right);
  }
}

int isBst(Tree *node, Tree **prev) {
  if (node != NULL) {
    if (!isBst(node->left, prev))
      return 0;
    if (*prev != NULL && node->data <= (*prev)->data)
      return 0;
    *prev = node;
    return isBst(node->right, prev);
  } else
    return 1;
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
  Tree *prev = NULL;
  printf("isBST: %d\n", isBst(root, &prev));

  return 0;
}
