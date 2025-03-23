#include <stdio.h>

int main() {
  int A[3][3], B[3][3], C[3][3];
  int i, j;

  printf("Enter Matrix 1:\n");
  for (i = 0; i < 3; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < 3; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter Matrix 2:\n");
  for (i = 0; i < 3; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < 3; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  /* Print the result */
  printf("\nSum of Matrices :\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d\t", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
