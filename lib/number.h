int findGCD(int number1, int number2)
{
  // Theory: https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclid's_algorithm
  if (number1 == 0)
    return number2;

  return findGCD(number2 % number1, number1);
}