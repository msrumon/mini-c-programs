#include <stdio.h>
#include "../../lib/number.h"

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

  long lcm = numbers[0];

  for (int i = 1; i < length; i++)
    lcm = findLCM(numbers[i], lcm);

  printf("LCM: %d", lcm);
}