#include <stdlib.h>
#include <stdio.h>
#include "../marco.h"
///  
/// Tree using List TODO
/// GO TO REAME ListReprentation
/// GOAL
/// 1. Input A(B(E(K,L),F), C(G) , D(H(M),I,J)),output list tree
/// 2. Input List tree- output parenthesized tree(like above)
/// Analize using stack handle input
/// if char == (  
/// push to operator stack AS oper
/// else if char == )
/// 
/// else if char == ,
/// scan next in    t

#define K 3 // max degree of tree

typedef struct tNode *tNodePointer;
typedef struct tNode{
   bool tag;//MEMO OR NOT
   int data;
   tNodePointer link;
}tNode;

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

///  
/// Binary Tree List representation
///
/// Create()
/// IsEmpty(bt)
/// MakeBT(bt1,item,bt2)
/// Lchild(bt)
/// Rchild(bt)
/// Data(Bt)

typedef struct btNode *treePointer;
typedef struct btNode{
  int data;
  treePointer leftChild;
  treePointer rightChild;
}btNode;

// Create empty Binary tree
treePointer Create(){
  treePointer head;
  MALLOC(head,sizeof(*head));
  head->leftChild = NULL;
  head->rightChild = NULL;
  return head;
}



// inorder tree traversal recursive
void inorder(treePointer ptr){
  if(ptr){
    inorder(ptr->leftChild);
    printf("%d",ptr->data);
  }
}

int main(){
   printf("Hallo World\n");
   return 0;
}