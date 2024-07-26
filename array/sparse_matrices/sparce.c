#include <stdio.h>
#include <stdlib.h>
#include "marco.h"
#include "sparce.h"
int main()
{
   printf("Hallow World \n");
   return 0;
}
void transpose(term a[], term b[])
{
   int n = 0;
   int y = 0;
   int x = 0;
   int current = 0;
   n = a[0].value;      /* total number of element */
   b[0].row = a[0].col; /* rows in b = columns in a */
   b[0].col = a[0].row; /* columns in b = rows in a */
   b[0].value = n;
   if (n > 0) /* non zero matrix */
   {
      current = 1;
      for (y = 0; y < a[0].col; y++) 
      {/* transpose by the columns in a*/
         for (x = 1; x < n ; x++)
         {/* find elements from the current column */
            if(a[x].col == y )
            {/* element is in current column, add it to b */
               b[current].row = a[x].col;
               b[current].col = a[x].row;
               b[current].value = a[x].value;
               current++;
            }
         }
      }
   }
}
int **make2dArray(int rows, int cols)
{
    // create a two dimensional rowx X cols array
    int **x = NULL;
    int i = 0;
    // get memory for row pointers
    CALLOC(x, rows, sizeof(*x));
    for (i = 0; i < rows; i++)
        CALLOC(x[i], cols, sizeof(**x));
    // get memory for each row
    return x;
}