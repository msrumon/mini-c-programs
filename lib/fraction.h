#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "number.h"

typedef struct rational
{
  int numerator;
  int denominator;
} frac;

char *convertFracToString(frac fraction)
{
  const size_t length = sizeof(fraction.numerator) + sizeof(fraction.denominator) + 1;
  char *string = calloc(length, sizeof(char));

  if (fraction.denominator == 1 || fraction.denominator == fraction.numerator)
    sprintf(string, "%d", fraction.numerator);

  else
  {
    char *numerator = malloc(sizeof(int)), *denominator = malloc(sizeof(int));

    sprintf(numerator, "%d", fraction.numerator);
    sprintf(denominator, "%d", fraction.denominator);

    strcat(string, numerator);
    strcat(string, "/");
    strcat(string, denominator);
  }

  return string;
}

frac convertStringToFrac(char *string)
{
  char *copied = string, *delimiter = "/";
  char *token = strtok(copied, delimiter);
  int numbers[2];
  frac fraction;

  for (int i = 0; i < 2 || token != NULL; i++)
  {
    numbers[i] = atoi(token);
    token = strtok(NULL, delimiter);
  }

  fraction.numerator = numbers[0];
  fraction.denominator = numbers[1];
  return fraction;
}

char *takeFracFromUser(char *message)
{
  char *input = malloc(sizeof(char));
  printf("%s ", message);
  scanf("%s", input);
  return input;
}

frac sum(frac fraction1, frac fraction2)
{
  frac result;

  int lcm = findLCM(fraction1.denominator, fraction2.denominator);
  result.denominator = lcm;
  result.numerator = (lcm / fraction1.denominator * fraction1.numerator) + (lcm / fraction2.denominator * fraction2.numerator);

  int gcd = findGCD(result.denominator, result.numerator);
  result.denominator /= gcd;
  result.numerator /= gcd;

  return result;
}

frac product(frac fraction1, frac fraction2)
{
  frac result;
  result.denominator = fraction1.denominator * fraction2.denominator;
  result.numerator = fraction1.numerator * fraction2.numerator;

  int gcd = findGCD(result.denominator, result.numerator);
  result.denominator /= gcd;
  result.numerator /= gcd;

  return result;
}

frac inverse(frac fraction)
{
  frac result;
  result.denominator = fraction.numerator;
  result.numerator = fraction.denominator;

  int gcd = findGCD(result.denominator, result.numerator);
  result.denominator /= gcd;
  result.numerator /= gcd;

  return result;
}

frac divide(frac fraction1, frac fraction2)
{
  return product(fraction1, inverse(fraction2));
}