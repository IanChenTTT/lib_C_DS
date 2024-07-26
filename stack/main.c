#include "stack.h"
#include "stdio.h"
#include "stdlib.h"
void CalcPermunation(int);
int main() {
  Stack *s;
  // Initial value will be 1 2 3
  s = CreateS(20);
  // Push(s,4);
  // Push(s,5);
  // Push(s,6);
  // Push(s,7);
  // Push(s,8);
  // Pop(s);
  // Pop(s);
  for (int i = 0; i <= s->TOP; i++) {
    printf("%d \n", s->element[i].key);
  }
  Clear(s);

  // Bus error
  //  if(Pop(s) != -1 ) printf("You pop");
  //  else{
  //     printf("Something went wrong");
  //  }
  return 0;
}
/**
 * N == 3
 * N N-1 N-2
 * 1 2   3
 * 1 3   2
 * 2 1   3
 * 2 3   1
 * 3 1   2
 * 3 2   1
 */
void CalcPermunation(int N) {
  // while(N--){
  //    if(N <= 0)return;  //Recursive end condition
  //    printf("%d ",N);
  //    CalcPermunation(N-1);
  // }
  int temp;
  for (int i = 1; i <= N; i++) {
    printf("%d ", i);
    temp = i + 1;
    while (temp != i) {
      printf("%d ", temp);
      temp++;
      if (temp > N)
        temp = 1;
    }
    printf("\n");
  }
}
