#include <stdio.h>
#include <math.h>
#include "../../lib/triangle.h"

void main()
{
  int edge1, edge2, edge3;

  printf("Enter edge-1: ");
  scanf("%d", &edge1);

  printf("Enter edge-2: ");
  scanf("%d", &edge2);

  printf("Enter edge-3: ");
  scanf("%d", &edge3);

  if (isValidTriangle(edge1, edge2, edge3) == 1)
  {
    int perimeter = edge1 + edge2 + edge3;
    float s = (float)perimeter / 2; // casting 'perimeter' into float to prevent the calculation from returning integer
    printf("Area: %0.2f sq. unit", sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)));
  }
  else
    printf("The edges will not form any valid triangle!");
}
