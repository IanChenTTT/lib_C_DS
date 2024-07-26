#ifndef SPARCE_H_
#define SPRARCE_H_
/**
 * a[0].row = how many rows it have 
 * a[0].col = how many cols it have 
 * a[0].val = how many nonzero value it have
 * 
 * @param int col
 * @param int row
 * @param int value
 */
typedef struct
{

   int col;
   int row;
   int value;
} term;

/**
 * b is set to the transpose of a
 * @param term[] a
 * @param term[] b
 */
void transpose(term a[], term b[]);
#endif