#include <stdio.h>

int main() {
  long a = 1, b = 1, c;
  int n = 80, i;
  printf("Fibonacci Series: %ld, %ld, ", a, b);

  for (i = 3; i <= n; i++) {
    c = a + b;
    printf("%ld, ", c);
    a = b;
    b = c;
  }
  printf("\n");
  return 0;
}
