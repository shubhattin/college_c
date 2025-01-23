#include <stdio.h>

int main() {
  int n, rev, rem;

  printf("Enter a number: ");
  scanf("%d", &n);

  rev = 0;
  int n1 = n;

  while (n != 0) {
    rem = n % 10;
    rev = rev * 10 + rem;
    n /= 10;
  }
  printf("Reverse: %d\n", rev);
  if (n1 == rev)
    printf("A Palindrome Number");
  else
    printf("Not a palindrome number");
  printf("\n");
  return 0;
}
