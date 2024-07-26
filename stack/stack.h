#ifndef STACK_H_
#define STACK_H_

#define MAX_SIZE 100
#include "../marco.h"
#include <stdlib.h>
#include <stdio.h>
#define DEFAULT_STACK {{MAX_SIZE},-1}
typedef struct Element{
   int key;
   /* other field input*/
} Element;
typedef struct Stack{
   Element* element;
   int TOP;
   int CAP;
}Stack;

bool IsFull(Stack s);
bool IsEmpty(Stack s);
void Stackfull(Stack* s);
bool Push(Stack* s, int item);
int Pop(Stack* s);
void Clear(Stack* stack);
Stack* CreateS(unsigned int maxStackSize);
#endif
