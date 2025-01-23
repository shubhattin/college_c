#include <stdio.h>

int main() {
  char names[3][50];

  for (int i = 0; i < 3; i++) {
    printf("Enter name %d: ", i + 1);
    fgets(names[i], sizeof(names[0]), stdin);
  }

  for (int i = 0; i < 3; i++) {
    printf("Name %d = %s", i + 1, names[i]);
  }
  return 0;
}
