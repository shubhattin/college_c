#include <stdio.h>

// int fib(int n) {
//   int a = 1, b = 1, c;
//   int i;
//   if (n == 1)
//     return a;
//   for (i = 0; i < n - 2; i++) {
//     c = a + b;
//     a = b;
//     b = c;
//   }
//   return b;
// }

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  printf("Enter fibonacci number index: ");
  scanf("%d", &n);
  printf("nth Fibonacci number: %d\n", fib(n));
  return 0;
}
