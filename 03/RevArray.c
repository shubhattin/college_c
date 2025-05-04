#include <stdio.h>

#define N 6

void print_array(int A[]) {
  for (int i = 0; i < N; i++)
    printf("%d, ", A[i]);
}
int main() {
  int arr[N] = {1, 2, 9, 4, 5, 10};
  int i = 0, tmp;

  for (i = 0; i < N / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[N - i - 1];
    arr[N - i - 1] = tmp;
  }
  // works for both even and odd number of terms

  printf("Reversed Array:\n");
  print_array(arr);
  printf("\n");

  return 0;
}
