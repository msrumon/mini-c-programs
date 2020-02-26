int isValidTriangle(int a, int b, int c)
{
  // Theory: https://en.wikipedia.org/wiki/Triangle_inequality
  if (a + b <= c || b + c <= a || c + a <= b)
    return 0;

  return 1;
}