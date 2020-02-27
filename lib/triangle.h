#include <stdbool.h>

bool isValidTriangle(unsigned edge1, unsigned edge2, unsigned edge3)
{
  // Theory: https://en.wikipedia.org/wiki/Triangle_inequality
  if (edge1 + edge2 <= edge3 || edge2 + edge3 <= edge1 || edge3 + edge1 <= edge2)
    return false;

  return true;
}