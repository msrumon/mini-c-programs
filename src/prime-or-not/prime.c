#include <stdio.h>
#include <stdbool.h>

void main()
{
  int input;
  bool flag = true;

  printf("Enter number: ");
  scanf("%d", &input);

  for (int i = 2; i < input; i++)
  {
    if (input % i == 0)
    {
      printf("%d is not prime number, it is divisible by %d.", input, i);
      flag = false;
      break;
    }
  }

  if (flag == true)
    printf("%d is a prime number!", input);
}