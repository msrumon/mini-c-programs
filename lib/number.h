#include <stdlib.h>

int greaterBetween(const int number1, const int number2)
{
  if (number1 > number2)
    return number1;

  return number2;
}

int greatestAmong(int *numbers, const int size)
{
  int greatest = *(numbers + 0);

  for (int i = 1; i < size; i++)
    greatest = greaterBetween(greatest, *(numbers + i));

  return greatest;
}

int smallerBetween(const int number1, const int number2)
{
  if (number1 > number2)
    return number2;

  return number1;
}

int smallestAmong(int *numbers, const int size)
{
  int smallest = *(numbers + 0);

  for (int i = 1; i < size; i++)
    smallest = smallerBetween(smallest, *(numbers + i));

  return smallest;
}

int findGCD(const int number1, const int number2)
{
  // Theory: https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclid's_algorithm
  if (number1 == 0)
    return number2;

  return findGCD(number2 % number1, number1);
}

long findLCM(const int number1, const int number2)
{
  // Theory: https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor
  return abs(number1 * number2) / findGCD(number1, number2);
}