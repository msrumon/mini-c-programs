#include <stdio.h>

void display(const char *message, const size_t row, const size_t column, int matrix[row][column])
{
  printf("\n%s\n", message);

  for (int r = 0; r < row; r++)
  {
    printf("|");

    for (int c = 0; c < column; c++)
    {
      if (c == column - 1)
        printf("%d", matrix[r][c]);
      else
        printf("%d\t", matrix[r][c]);
    }

    printf("|\n");
  }
}

void manipulate(const char *message, const size_t row, const size_t column, int matrix[row][column])
{
  printf("\n%s\n", message);

  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < column; c++)
    {
      printf("a%d%d: ", r + 1, c + 1);
      scanf("%d", &matrix[r][c]);
    }
  }
}

void multiply(const size_t row1, const size_t column1, const size_t row2, const size_t column2, const int matrix1[row1][column1], const int matrix2[row2][column2], int result[row1][column2])
{
  for (int r = 0; r < row1; r++)
  {
    for (int c = 0; c < column2; c++)
    {
      result[r][c] = 0;

      for (int m = 0; m < row2 || m < column1; m++)
        result[r][c] += matrix1[r][m] * matrix2[m][c];
    }
  }
}