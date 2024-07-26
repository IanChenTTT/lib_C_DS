#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../marco.h"

/// SINGLY LINKED LIST

typedef enum { false, true } bool;
typedef struct listNode *listPointer;
typedef struct listNode {
  int data;
  listPointer link;
} Node;
// create a linked list with
// two nodes
listPointer create2(int d1, int d2) {
  listPointer first;
  listPointer second;
  MALLOC(first, sizeof(*first));
  MALLOC(second, sizeof(*second));
  second->link = NULL;
  second->data = d2;
  first->link = second;
  first->data = d1;
  return first;
}
void insertTail(listPointer *tail,int d){
  // x->oldTail->null
  // x->oldTail->newTail->null;
  listPointer temp;
  MALLOC(temp, sizeof(*temp));
  temp->data = d;
  (*tail)->link = temp; // old

  (*tail) = temp;
  (*tail)->link = NULL; // ensure
}
void insert(listPointer *first, listPointer x, int d)
{
  listPointer t;
  MALLOC(t, sizeof(*t));
  t->data = d;
  if (*first)
  {
    t->link = x->link;
    x->link = t;
    return;
  }
  t->link = NULL;
  *first = t;
}
listPointer searchTrail(listPointer first, int n) {
  int it = 0;
  // PROBLEM: delete first and trail is first conflict
   if(first){
     if(first->data == n) return NULL;
  }
  while (first) {
    it++;
    if (first->link) {
      if (first->link->data == n) {
        //printf("iterate through: %4d \n", it); // DEBUG
        return first;
      }
    }
    first = first->link;
  }
  return NULL;
}
// search first number if found
listPointer search(listPointer first, int n) {
  int it = 0;
  while (first) {
    it++;
    if (first->data == n) {
      // printf("iterate through: %4d \n", it); //DEBUG
      return first;
    }
    first = first->link;
  }
  return NULL;
}
// TODO wierd 
// delete x node by giving trail Node
void delete(listPointer *first, listPointer trail) { // trail->x
  if (trail) { // if there is previous node
    // trail->link = x->link; //trail link next = x
    // free(x);
    return;
  }
  *first = (*first)->link; // else remove first
  free(trail->link);
}
// deleteN search first number(N) to delete
void deleteN(listPointer *first, int n) {
  // trail->xN->x
  // trail->link = xN
  // trail->link->link = x
  listPointer t = searchTrail(*first, n);
  if (t) {
    //printf("trail is: %4d ", t->data); //DEBUG
    listPointer xN = t->link;
    t->link = t->link->link;
    free(xN);
    return;
  } else if (*first) {
    if ((*first)->data == n){
       listPointer xN = (*first);
       (*first) = (*first)->link;
       free(xN);
    }
  }
}
int count(listPointer first){
  int count = 0;
  while(first){
    count++;
    first = first->link;
  }
  return count;
}
void print(listPointer first) {
  printf("the list contains: ");
  while (first) {
    printf("%4d", first->data);
    first = first->link;
  }
  printf("\n");
}
void freeL(listPointer first) {
  listPointer t;
  while (first) {
    t = first;
    /*
    printf("the list delete: "); // DEBUG
    printf("%4d", first->data);
    printf("\n");
    */
    first = t->link;
    free(t);
  }
}
// invert list 
// trail->mid->first
void invert(listPointer first){
  listPointer mid,trail = NULL;
  while(first){
    trail = mid;         // move to next position
    mid = first;         // move to next position
    first = first->link; // move to next position

    mid->link = trail; // invert link was trail->mid 
  }
  return mid;
}
///
/// TODO
/// DOUBLE LINKED LIST 

typedef struct dNode *dNodePointer;
typedef struct dNode
{
  dNodePointer lLink;
  element data;
  dNodePointer rLink;
} dNode;

// dInsert insert newnode to the right of node 
void dInsert(dNodePointer node, dNodePointer newNode){
}

///

///
/// LINKED STACK 
///

typedef struct {
  int key;
}element;
typedef struct lStack *stackPointer;
typedef struct lStack{
  element data;
  stackPointer link;
}lStack;

// push insert before old top
// top->old top-> ...
void push(stackPointer *top, int d){
  stackPointer t;
  MALLOC(t,sizeof(*t));
  t->data = (element){d};

  if((*top) == NULL){ // lStack is empty
    (*top) = t;
    return;
  }

  t->link = (*top);
  (*top) = t;
}
void isEmpty(stackPointer top){
  if (!top){
    fprintf(stderr, "lStack is empty can't add any element\n");
    exit(EXIT_FAILURE);
  }
}
// Pop top element
element pop(stackPointer *top){
  isEmpty(*top);
  stackPointer t = (*top);
  element t1 = t->data;
  (*top) = (*top)->link;
  free(t);
  return t1;
}
void printS(stackPointer top){
  isEmpty(top);
  printf("lStack is:");
  while(top){
    printf("%4d",top->data.key);
    top = top->link;
  }
  printf("\n");
}
//TODO EXERCISES p159 palindrome


///
/// LINKED QUEUES

//TODO

///
///
void testSinglyList(){

  listPointer first = create2(20, 30);
  listPointer tail = first->link;
  insertTail(&tail, 20);
  printf("count: %4d\n", count(first));
  print(first);
  printf("search %4d \n", search(first, 20)->data);
  print(first);

  insertTail(&tail, 20);
  insertTail(&tail, 30);
  insertTail(&tail, 40);
  insertTail(&tail, 50);
  insertTail(&tail, 60);
  print(first);
  printf("count: %4d \n", count(first));

  deleteN(&first, 30);
  printf("search %4d \n", search(first, 40)->data);
  print(first);
  printf("count: %4d \n", count(first));

  deleteN(&first, 20);
  print(first);

  freeL(first);
}
void testLinkedStack(){
  stackPointer top = NULL;
  push(&top, 2);
  printf("Pop: %4d \n", pop(&top).key);
  push(&top, 3);
  push(&top, 4);
  push(&top, 5);
  push(&top, 6);
  push(&top, 7);
  printS(top);
  printf("Pop: %4d \n", pop(&top).key);
  printS(top);
  printf("Pop: %4d \n", pop(&top).key);
  printS(top);
  printf("Pop: %4d \n", pop(&top).key);
  printS(top);
}
int main() {
  testLinkedStack();
  return 0;
}
