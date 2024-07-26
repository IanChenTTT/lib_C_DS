#ifndef DEFINE_H_
#define DEFINE_H_
#define FALSE 0;
#define TRUE 1;
/**
 * system calloc with extra memory guard
 * @param ptr
 * @param n //capacity
 * @param s //size of type
 */
#define CALLOC(ptr, n, s)                      \
    if (!((ptr) = calloc(n, s)))               \
    {                                          \
        fprintf(stderr, "Insufficent memory"); \
        exit(EXIT_FAILURE);                    \
    }
/**
 * system relloc with extra memory guard
 * @param ptr
 * @param n //capacity
 * @param s //size of type
 */
#define REALLOC(ptr, s)                      \
    if (!((ptr) = realloc(ptr, s)))               \
    {                                          \
        fprintf(stderr, "Insufficent memory"); \
        exit(EXIT_FAILURE);                    \
    }
/**
 * swap to variable
 * @param int first
 * @param int second
 * @param int temp
*/
#define SWAP(first, second, temp) ((temp) = (first) , (first) = (second) ,(second) = (temp))
#endif
