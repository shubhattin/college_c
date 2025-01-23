#include <stdio.h>

int main() {
  int A[3][3], B[3][3];
  printf("Enter Matrix 1 (2x3):\n");
  for (int i = 0; i < 3; i++) {
    printf("Row %d: ", i + 1);
    for (int j = 0; j < 3; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      B[i][j] = A[j][i];
  }

  printf("Added Matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d\t", A[i][j]);
    printf("\n");
  }
  printf("Added Matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d\t", B[i][j]);
    printf("\n");
  }

  return 0;
}
