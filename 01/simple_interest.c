#include <stdio.h>

int main() {
  float principal = 0, time = 0, rate = 0;
  float SI = 0, amount = 0;

  // Variable Input
  printf("Enter Principal Amount : Rs. ");
  scanf("%f", &principal);
  printf("Enter Time : ");
  scanf("%f", &time);
  printf("Enter Rate : ");
  scanf("%f", &rate);

  // Interest Calculation
  SI = (principal * time * rate) / 100;
  amount = principal + SI;

  // Displaying Results
  printf("\nSimple Interest: Rs. %f\n", SI);
  printf("Amount: Rs. %f\n", amount);

  return 0;
}
