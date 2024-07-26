#ifndef MARCO_H_
#define MARCO_H_
#define FALSE 0;
#define TRUE 0;
#define SWAP(first, second, temp) ((temp) = (first) , (first) = (second) ,(second) = (temp))
#define COMPARE(x,y)((x) < (y) ? -1 : ((x) == (y))? 0 : 1)
/**
 * system calloc with extra memory guard
 * @param ptr
 * @param capacity //capacity
 * @param size //size of type
 */
#define CALLOC(ptr, capacity, size)                      \
    if (!((ptr) = calloc(capacity, size)))               \
    {                                          \
        fprintf(stderr, "Insufficent memory"); \
        exit(EXIT_FAILURE);                    \
    }
#endif
