#include <stdio.h>

int main() {
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int i, j;
  int index[2] = {-1, -1};
  int num;
  printf("Enter a number = ");
  scanf("%d", &num);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (A[i][j] == num) {
        index[0] = i;
        index[1] = j;
      }
    }
  }
  if (index[0] == -1 || index[1] == -1) {
    puts("Number not found");
  } else {
    void *base = (void *)&A[0][0];
    void *address = base + (index[0] * 3 + index[1]) * sizeof(int);
    printf("Address in Row Major of %d is %p\n", num, address);
    // printf("\nAddress = %p\n", (void *)&A[index[0]][index[1]]);
  }
  return 0;
}
