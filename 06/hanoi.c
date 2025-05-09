#include <stdio.h>

void hanoi(int n, char from, char aux, char to) {
  if (n != 0) {
    // move n - 1 disks from from to aux
    hanoi(n - 1, from, to, aux);
    // move the last disk from from to to
    printf("=> %d :- from %c to %c\n", n, from, to);
    // move n - 1 disks from aux to to
    hanoi(n - 1, aux, from, to);
  }
}

int main() {
  int n;
  printf("Enter number of plates: ");
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  return 0;
}
