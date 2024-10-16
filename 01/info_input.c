#include <stdio.h>

int main() {
  char name[50], email[50], adress[200], phone[13];
  int age;

  // Taking user input
  printf("Enter Name : ");
  fgets(name, sizeof(name), stdin);
  printf("Enter Age : ");
  scanf("%d", &age);
  getchar(); // reads the \n to allow email(string) input
  printf("Enter Email : ");
  fgets(email, sizeof(email), stdin);
  printf("Enter Address : ");
  fgets(adress, sizeof(adress), stdin);
  printf("Enter Phone : ");
  fgets(phone, sizeof(phone), stdin);

  // Displaying entered information
  printf("\n\nName : %s", name);
  printf("Age : %d\n", age);
  printf("Email : %s", email);
  printf("Address : %s", adress);
  printf("Phone : %s", phone);

  return 0;
}
