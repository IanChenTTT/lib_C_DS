#ifndef MATRIX_H_
#define MATRIX_H_
/**
 * This is header file that include
 * matrix operation definition
 * matrix object definition
*/

/**
 * generate 2d integer array
 * @param int rows
 * @param int cols
 * @return int **
 */
int **make2dArray(int, int);
/**
 * random generate 2d array integer
 * @param int** arr
 * @param int rows
 * @param int cols
 * @return int **
 */
void rndArray(int** , int , int);
/**
 * free 2d integer array of memory
 * @param int ** arr
 * @param int rows
 * @param int cols
 * @return int **
 */
void free2dArray(int **, int, int);

/**
 * print 2d integer array
 * @param int** ptr
 * @param int rows
 * @param int cols
 */
void print2dArray(int** ptr, int rows, int cols);
/**
 * matrix addition
 * MAT1 + MAT2 = MAT3
 * @param int** MAT1
 * @param int** MAT2
 * @param int** Res
 * @param int rows;
 * @param int cols
*/
void add(int** , int** , int**, int , int);
/**
 * matrix mutiply
 * MAT1 * MAT2 = MAT3
 * @param int** MAT1
 * @param int** MAT2
 * @param int** Res
 * @param int rows;
 * @param int cols
*/
void mult(int**, int**, int**, int , int );
/**
 * matrix transpose
 * @param int** MAT1
 * @param int rows
 * @param int cols
 * @return int** Mat
*/
int **transpose(int** , int , int);
#endif