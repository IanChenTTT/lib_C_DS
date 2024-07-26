#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#define MAX_DEGREE 101 /*Max degree of polynomial*/
/**
 * polyNomial structure
 * @struct Polynomial
 * @param float coefficient
 * @param expon exponent
*/
typedef struct{
    float coef;
    int expon;
} Polynomial;

typedef struct{
    int degree;
    int capacity;
    float *coef;
} dpolynomial;

int avail = 0;
Polynomial terms[MAX_DEGREE];
/**
 *  Polynomial add function
 *  add A(x) and B(x) to obtain D(x)
 *
 * @param  int startA
 * @param int endA
 * @param int startB
 * @param int endB
 * @param int* startD
 * @param int* endD
 */
void padd(int, int, int, int, int *, int *);
/**
 * add a new term to polynomial
 *
 * @param int coefficient
 * @param int exponent
 */
void attach(float, int);

/**
 * This function create polynomial
 * pointer refrence to array,
 * dynamic allocate memory
 * need to free;
 * 
 * @param Polynomial**
 * @return int size;
*/
int readPoly(Polynomial**);

/**
 * This function print polynomial;
 * @param Polynomial[]poly
 * @param const int size
*/
void printPoly(Polynomial[], int n);

/**
 * Polynomial multiplication 
 * poly1 * poly2 = poly3
 * Dynamic array free(poly3)
 * @param Polynomial poly1
 * @param Polynomial poly2
 * @param Polynomial poly3
 * @param int Capacity1
 * @param int Capacity2
 * @return Polynomial poly3
*/
int pmult(Polynomial[], Polynomial[],Polynomial**,int,int);
#endif