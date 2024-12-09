#include <stdio.h>

int main() {
  int i, j, n = 9;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= ((i >= n / 2 + 1) ? n - i + 1 : i); j++)
      printf("* ");
    printf("\n");
  }
  return 0;
}
