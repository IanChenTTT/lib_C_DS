# ADT structure sparce matrix

## ADT
---
* Object: A set of triples <rows , columns, value>,where row and column are integer and form unique combination, and value comes from the set item
* Functions:
``For all a,b ``
   *  

---
  a[0].row = how many rows it have <br>
  a[0].col = how many cols it have <br>
  a[0].val = how many nonzero value it have
## Transpose

``` C++
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
```

<table>
  <tr>
    <th>Matrix 1</th>
    <th>Matrix 2</th>
  </tr>
<tr>
<td>
A

| Row  |  Col  | Value |
| :--- | :---: | ----: |
| 6    |   6   |     8 |
| 0    |   0   |    15 |
| 0    |   3   |    22 |
| 0    |   5   |   -15 |
| 1    |   1   |    11 |
| 1    |   2   |     3 |
| 2    |   3   |    -6 |
| 4    |   0   |    91 |
| 5    |   2   |    28 |

</td>


<td>
AT

| Row  |  Col  | Value |
| :--- | :---: | ----: |
| 6    |   6   |     8 |
| 0    |   0   |    15 |
| 0    |   3   |    22 |
| 0    |   5   |   -15 |
| 1    |   1   |    11 |
| 1    |   2   |     3 |
| 2    |   3   |    -6 |
| 4    |   0   |    91 |
| 5    |   2   |    28 |

</td> 
</tr>
<tr>

<td> <strong> x = 1 </strong>

| Row  |  Col  | Value | y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | Y    |



</td>

<td> <strong> x = 2 </strong>

| Row  |  Col  | Value | y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | Y    |
| 0    |   3   |    22 | N    |

</td>

<td>

| Row  |  Col  | Value | y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | Y    |
| 0    |   3   |    22 | N    |

...To

</td>


</tr>
<tr>
<td> <strong> x = 7 </strong>

| Row  |  Col  | Value | Y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | Y    |
| 0    |   3   |    22 | N    |
| 0    |   5   |    22 | N    |
| 1    |   1   |    22 | N    |
| 1    |   2   |    22 | N    |
| 2    |   3   |    22 | N    |
| 4    |   0   |    22 | Y    |
| 5    |   2   |    22 | N    |
</td>
</tr>
<tr>

<td> <strong> x = 1 </strong>

| Row  |  Col  | Value | Y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | N    |
| 0    |   3   |    22 |      |
| 0    |   5   |    22 |      |
| 1    |   1   |    22 |      |
| 1    |   2   |    22 |      |
| 2    |   3   |    22 |      |
| 4    |   0   |    22 |      |
| 5    |   2   |    22 |      |

</td>
<td> <strong> x = 2 </strong>

| Row  |  Col  | Value | Y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | N    |
| 0    |   3   |    22 | N    |
| 0    |   5   |    22 |      |
| 1    |   1   |    22 |      |
| 1    |   2   |    22 |      |
| 2    |   3   |    22 |      |
| 4    |   0   |    22 |      |
| 5    |   2   |    22 |      |

</td>
<td> <strong> x = 7 </strong>

| Row  |  Col  | Value | Y==0 |
| :--- | :---: | ----: | :--- |
| 6    |   6   |     8 | SKIP |
| 0    |   0   |    15 | N    |
| 0    |   3   |    22 | N    |
| 0    |   5   |    22 | N    |
| 1    |   1   |    22 | Y    |
| 1    |   2   |    22 | N    |
| 2    |   3   |    22 | N    |
| 4    |   0   |    22 | N    |
| 5    |   2   |    22 | N    |

</td>



</tr>
</table>

## Fast Transpose

``` C++
void fastTranspose(term a[], term b[]) {
    int nonZeroRow[MAX_COL] = {0}, startingPos[MAX_COL] = {0};
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].val = a[0].val;
    for (int i = 1; i <= a[0].val; i++) {
        nonZeroRow[a[i].col]++;
    }
    startingPos[0] = 1;
    for (int i = 1; i <= a[0].col; i++) {
        startingPos[i] = startingPos[i-1] + nonZeroRow[i-1];
    }
    for (int i = 1; i <= a[0].val; i++) {
        int j = startingPos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].val = a[i].val;
    }
}
```

<table>
<tr>
<td>

``A``

| Row  |  Col  | Value |
| :--- | :---: | ----: |
| 6    |   6   |     8 |
| 0    |   0   |    15 |
| 0    |   3   |    22 |
| 0    |   5   |   -15 |
| 1    |   1   |    11 |
| 1    |   2   |     3 |
| 2    |   3   |    -6 |
| 4    |   0   |    91 |
| 5    |   2   |    28 |

</td>
<td>

1. first loop iniatialize NonZeroRow N
* N[0] = 2
* N[1] = 1
* N[2] = 2
* N[3] = 2
* N[4] = 0
* N[5] = 1
1. second loop Initialize startingPos S
* S[0] = 1
* S[1] = S[0] + N[0] = 3
* S[2] = s[1] + N[1] = 3 + 1
* S[3] = s[2] + N[2] = 4 + 2
* S[4] = s[3] + N[3] = 6 + 2
* S[4] = s[4] + N[4] = 8 + 0
</td>
</tr>
</table>



