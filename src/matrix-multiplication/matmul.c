#include <stdlib.h>
#include "../../lib/matrix.h"

void main()
{
  unsigned r1, c1, r2, c2;

  printf("Row of 1st matrix: ");
  scanf("%d", &r1);
  printf("Column of 1st matrix: ");
  scanf("%d", &c1);

  if (r1 < 1 || c1 < 1)
  {
    printf("Values of row and/or column must be greater than zero.");
    exit(1);
  }

  printf("Row of 2nd matrix: ");
  scanf("%d", &r2);
  printf("Column of 2nd matrix: ");
  scanf("%d", &c2);

  if (r2 < 1 || c2 < 1)
  {
    printf("Values of row and/or column must be greater than zero.");
    exit(1);
  }

  if (c1 != r2)
  {
    printf("Cannot be multiplied because of dimension constraint.");
    exit(1);
  }

  /* allocating matrices */
  int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

  /* scanning 1st matrix */
  manipulate("Enter 1st matrix:", r1, c1, mat1);

  /* scanning 2nd matrix */
  manipulate("Enter 2nd matrix:", r2, c2, mat2);

  /* calculating */
  multiply(r1, c1, r2, c2, mat1, mat2, result);

  /* printing result */
  display("Result:", r1, c2, result);
}