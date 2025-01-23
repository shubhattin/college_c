#include <stdio.h>

int main() {
  int n = 3;
  printf("Enter Dimension of Matrix: ");
  scanf("%d", &n);
  int A[n][n], B[n][n], C[n][n];

  printf("Enter Matrix 1 (3x3):\n");
  for (int i = 0; i < n; i++) {
    printf("Row %d: ", i + 1);
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter Matrix 2 (3x3):\n");
  for (int i = 0; i < n; i++) {
    printf("Row %d: ", i + 1);
    for (int j = 0; j < n; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  printf("Matrix 1:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d\t", A[i][j]);
    printf("\n");
  }

  printf("Matrix 2:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d\t", B[i][j]);
    printf("\n");
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];

  printf("Added Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d\t", C[i][j]);
    printf("\n");
  }

  return 0;
}
