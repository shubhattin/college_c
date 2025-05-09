#include <stdio.h>

// void fib(int n) {
//   int a = 1, b = 1, c;
//   int i = 0;
//   printf("Series:\n%d, %d, ", a, b);
//   for (i = 0; i < n - 2; i++) {
//     c = a + b;
//     a = b;
//     b = c;
//     printf("%d, ", b);
//   }
//   printf("\n");
// }

void fib(int a, int b, int n) {
  if (n == 2) {
    printf("\n");
    return;
  }
  if (a == 1 && b == 1)
    printf("Series:\n%d, ", a);
  printf("%d, ", b);
  return fib(b, a + b, n - 1);
}

int main() {
  int n;
  printf("Number of terms to print for fibonacci series: ");
  scanf("%d", &n);
  fib(1, 1, n);
  return 0;
}
