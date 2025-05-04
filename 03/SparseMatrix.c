#include <stdio.h>

int main() {
  int A[3][3];
  int i, j;
  int zero, non_zero = 0;

  printf("Enter Matrix 1:\n");
  for (i = 0; i < 3; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < 3; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // checking if sparse matric and then storing and displaying
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (A[i][j] == 0) {
        zero++;
      } else {
        non_zero++;
      }
    }
  }

  if (zero > non_zero) {
    printf("Matrix is sparse: \n");
    int B[3][non_zero];
    // row, column, value

    int x = 0;
    // storing the sparse matrix
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (A[i][j] != 0) {
          B[0][x] = i;
          B[1][x] = j;
          B[2][x++] = A[i][j];
        }
      }
    }

    // displaying the sparse matrix
    printf("Compact Sparse Matrix Representation:\n");
    for (i = 0; i < 3; i++) {
      for (j = 0; j < non_zero; j++) {
        printf("%d\t", B[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
