#include <stdio.h>

int main() {
  char str[30];
  printf("Enter String: ");
  scanf("%[^\n]", str);
  // fgets(str, 30, stdin);
  // gets(str);
  printf("Entered String = %s", str);
  return 0;
}
