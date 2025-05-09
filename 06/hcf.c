#include <stdio.h>

// int hcf(int a, int b) {
//   int rem;
//   do {
//     rem = b % a;
//     b = a;
//     a = rem;
//   } while (rem != 0);
//   return b;
// }

int hcf(int a, int b) {
  if (a == 0)
    return b;
  return hcf(b % a, a);
}

// int hcf(int a, int b) {
//   if (b == 0)
//     return a;
//   return hcf(b, a % b);
// }

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  printf("HCF: %d\n", hcf(a, b));
  return 0;
}
