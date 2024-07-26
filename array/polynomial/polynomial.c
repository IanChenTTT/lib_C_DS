#include <stdio.h>
#include <stdlib.h>
#include "marco.h"
#include "polynomial.h"
int main()
{
    Polynomial *poly1;
    Polynomial *poly2;
    Polynomial *poly3;
    const int size = readPoly(&poly1);
    const int size2 = readPoly(&poly2);
    printPoly(poly1,size);
    printPoly(poly2,size2);
    const int size3 = pmult(poly1,poly2,&poly3,size,size2);
    printPoly(poly3,size3);
    free(poly1);
    free(poly2);
    free(poly3);
    return 0;
}
void padd(int startA, int endA, int startB, int endB, int *startD, int *endD)
{
    float coefficient;
    *startD = avail;
    while (startA <= endA && startB <= endB)
    {
        switch (COMPARE(terms[startA].expon,
                        terms[startB].expon))
        {
        case -1: /* a expon > b expon*/
            attach(terms[startB].coef, terms[startB].expon);
            startB++;
            break;
        case 0: /* a expon == b expon*/
            coefficient = terms[startA].coef + terms[startB].coef;
            if (coefficient)
                attach(coefficient, terms[startA].expon);
            startA++;
            startB++;
            break;
        case 1: /* a expon > b expon*/
            attach(terms[startA].coef, terms[startA].expon);
            startA++;
            break;
        }
    }
}
void attach(float coefficient, int exponent)
{
    /* add new term to polynomial */
    if (avail >= MAX_DEGREE)
    {
        fprintf(stderr, "Too many terms in polynomial \n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}
void printPoly(Polynomial term[], int n)
{
    for (int i = 0; i < n-1; i++)
        printf("%.1fX^%d + ", term[i].coef,term[i].expon);
    printf("%.1fX^%d \n", term[n-1].coef,term[n-1].expon);
}
int readPoly(Polynomial ** term){
    int i;
    printf("please input size of by Poly: ");
    scanf("%d",&i);
    while(i >= MAX_DEGREE)
    {
        printf("please input correct size of by Poly: ");
        scanf("%d",&i);
    }
    int exp[i];
    float coef[i];
    CALLOC(*term, i, sizeof(Polynomial));
    printf("Coefficient by line: ");
    for (int x = 0; x < i; x++)
    {
        scanf("%f", &coef[x]);
        (*term)[x].coef = coef[x];
    }
    printf("\nExponent by line: ");
    for (int x = 0; x < i; x++)
    {
        scanf("%d", &exp[x]);
        (*term)[x].expon = exp[x];
    }
    return i;
}
int pmult(
 Polynomial poly1[],
 Polynomial poly2[],
 Polynomial** poly3,
 const int size1,
 const int size2){
    int term = 0;
    for(int y = 0 ; y < size1 ; y++)
    {
      for(int x = 0 ; x < size2 ; x++)
      {
        printf("%.1fX * \n", poly1[y].coef*poly2[x].coef);
        CALLOC(*poly3,1,sizeof(Polynomial));
        (*poly3)[term].coef = (poly1[y].coef)*(poly2[x].coef);
        (*poly3)[term++].expon = (poly1[y].expon)+(poly2[x].expon);
      }
    }
    return term;
}