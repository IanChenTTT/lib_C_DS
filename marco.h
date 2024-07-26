#ifndef MARCO_H_
#define MARCO_H_
typedef enum { false, true } bool;
#define SWAP(first, second, temp) ((temp) = (first) , (first) = (second) ,(second) = (temp))
#define COMPARE(x,y)((x) < (y) ? -1 : ((x) == (y))? 0 : 1)
#define MALLOC(ptr, size)                                                      \
  if (!((ptr) = malloc(size))) {                                               \
    fprintf(stderr, "Insufficent memory");                                     \
    exit(EXIT_FAILURE);                                                        \
  }
#define REALLOC(ptr, size)                                                     \
  if (!((ptr) = realloc(ptr, size))) {                                         \
    fprintf(stderr, "Insufficent memory");                                     \
    exit(EXIT_FAILURE);                                                        \
  }
#define IS_EMPTY (first) (! (first))

#endif
