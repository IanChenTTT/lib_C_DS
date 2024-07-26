#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "matrix.h"
/**
 * This run all function test case
 * @param int rows
 * @param int cols
 */
void run(int, int);
int main()
{
    int rows = 1;
    int cols = 1;
    printf("rows\n");
    scanf("%d", &rows);
    printf("cols\n");
    scanf("%d", &cols);
    run(rows, cols);
    return 0;
}
void run(int rows, int cols)
{
    // add
    int **Mat1 = make2dArray(rows, cols);
    int **Mat2 = make2dArray(rows, cols);
    int **Mat3 = make2dArray(rows, cols);
    //multiplication
    int **Mat4 = make2dArray(cols, rows);
    int **Mat5 = make2dArray(rows, rows);
    rndArray(Mat1, rows, cols);
    rndArray(Mat4, cols, rows);
    // Function test case
    // printf("-------------TEST1-------------\n");
    // add(Mat1, Mat2, Mat3, rows, cols);
    // print2dArray(Mat3, rows, cols);
    // printf("\n");
    // print2dArray(Mat4, cols, rows);
    // printf("-------------TEST2-------------\n");
    // mult(Mat3, Mat4, Mat5, rows, cols);
    // print2dArray(Mat5, rows, rows);
    printf("-------------TEST3-------------\n");
    int** Mat6 = transpose(Mat1,rows, cols);
    print2dArray(Mat6, cols , rows);
    printf("\n");
    print2dArray(Mat1, rows, cols);
    // Free MEM
    free2dArray(Mat1, rows, cols);
    free2dArray(Mat2, rows, cols);
    free2dArray(Mat3, rows, cols);
    free2dArray(Mat4, cols, rows);
    free2dArray(Mat5, rows, rows);
}
void print2dArray(int **ptr, int rows, int cols)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
            printf("%d \t \t", ptr[y][x]);
        printf("\n");
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
void rndArray(int **arr, int rows, int cols)
{
    srand(time(NULL)); // Initialization, should only be called once.
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
            arr[y][x] = rand() % 10 +1; // Returns a pseudo-random integer between 0 and RAND_MAX.
    }
}
void free2dArray(int **arr, int rows, int cols)
{
    while (rows)
        free(arr[--rows]);
    free(arr);
}
void add(int **mat1, int **mat2, int **res, int rows, int cols)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
            res[y][x] = mat1[y][x] + mat2[y][x];
    }
}
void mult(int** mat1, int** mat2, int** res, int rows, int cols)
{
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            for(int x1 = 0 ; x1 < cols ; x1 ++)
            {
                printf("%d : ",mat1[y][x1]);
                printf("%d \t",mat2[x1][x]);
                res[y][x] += mat1[y][x1] * mat2[x1][x];
            }
            printf("\n");
        }
        printf("\n");
    }
}
int **transpose(int** mat , int rows , int cols){
    int **res = make2dArray(cols,rows);
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            int temp = 0;
            SWAP(mat[y][x],res[x][y],temp);
        }
    }
    return res;
}
