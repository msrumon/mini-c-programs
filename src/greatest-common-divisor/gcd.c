#include <stdio.h>
#include "../../lib/number.h"

int findGCD(int number1, int number2)
{
  // Theory: https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclid's_algorithm
  if (number1 == 0)
    return number2;

  return findGCD(number2 % number1, number1);
}

void main()
{
  unsigned int length;

  printf("How many numbers?: ");
  scanf("%d", &length);

  int numbers[length];

  printf("Enter the numbers: \n");
  for (int i = 0; i < length; i++)
  {
    printf("(%d) ", i + 1);
    scanf("%d", &numbers[i]);
  }

  int gcd = numbers[0];

  for (int i = 1; i < length - 1; i++)
    gcd = findGCD(numbers[i], gcd);

  printf("GCD: %d", gcd);
}