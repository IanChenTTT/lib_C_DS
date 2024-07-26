#include "stack.h"
bool IsFull(Stack s){
   if(s.TOP == MAX_SIZE - 1) return true;
   return false;
}
bool IsEmpty(Stack s){
   if (s.TOP == -1)return true;
   return false;
}
void Stackfull(Stack* s){
   REALLOC(s->element, (2 * s->CAP * sizeof(*(s->element))));
   s->CAP *= 2;
}
bool Push(Stack* s, int item){
   if(IsFull(*s) == 1) Stackfull(s);
   s->TOP++;
   s->element[s->TOP].key = item;
   return true;
}
int Pop(Stack* s){
   if(IsEmpty(*s)) return -1;
   return s->element[s->TOP--].key;
}
void Clear(Stack* stack){
   free(stack->element);
}
Stack* CreateS(unsigned int maxStackSize){
   Stack *s;
   // s->List = (int *)calloc(maxStackSize,sizeof(unsigned int));
   MALLOC(s->element,sizeof(*(s->element)));
   s->TOP = -1; //DEFAULT VALUE
   s->CAP = 1; // DEFAULT CAPACITY
   return s;
}