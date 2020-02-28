#include <stdio.h>
#include <stdlib.h>

void vanish(int **matrix, const unsigned row)
{
  for (int i = 0; i < row; i++)
    free(matrix + i);

  free(matrix);
}

int **take(const unsigned row, const unsigned column, const char *message)
{
  printf("\n%s \n", message);

  int **matrix = (int **)calloc(row, sizeof(int *));

  for (int a = 0; a < column; a++)
    *(matrix + a) = (int *)calloc(column, sizeof(int));

  /* scanf */
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < column; c++)
    {
      printf("a%d%d: ", r + 1, c + 1);
      scanf("%d", ((matrix + r) + c));
    }
  }
  /* endscanf */

  return matrix;
}

void spit(int **matrix, const unsigned row, const unsigned column, const char *message)
{
  printf("\n%s \n", message);

  for (int r = 0; r < row; r++)
  {
    printf("|");

    for (int c = 0; c < column; c++)
    {
      if (c == column - 1)
        printf("%d", *((matrix + r) + c));
      else
        printf("%d\t", *((matrix + r) + c));
    }

    printf("|\n");
  }
}

// int **multiply(int **matrix1, int **matrix2, const unsigned row1, const unsigned column2, const unsigned multiplier)
// {
//   int **multiplied = (int **)calloc(row1, sizeof(int *));

//   for (int a = 0; a < column2; a++)
//     *(multiplied + a) = (int *)calloc(column2, sizeof(int));

//   for (int r = 0; r < row1; r++)
//   {
//     for (int c = 0; c < column2; c++)
//     {
//       *((multiplied + r) + c) = 0;

//       for (int m = 0; m < multiplier; m++)
//         *((multiplied + r) + c) += *((matrix1 + r) + m) * *((matrix2 + m) + c);
//     }
//   }

//   return multiplied;
// }