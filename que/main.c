#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "./que.h"
// #include "./deque.h"
#include "./AdvanceQue.h"
void Traverse();
//[start][end][destination]
int main(){
   CreateQ(3);
   TestQ();
   Traverse();
   ReleaseQ();
   int a;
   a = 5;
   int *b = &a;

   return 0;
}
void Traverse(){
   int i;
   for(i = 0 ; i < capacity ; i++)
      printf("NUM is %c \n",ADqueue[i].key);
}
