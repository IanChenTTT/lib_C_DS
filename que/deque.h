#ifndef DEQUE_H_
#define DEQUE_H_
/**
 * ADT DEQUE
 * OBJECTS:
 * A DEQUE is sub contain of que
 * which is linear order list
 * when a object place in que can either place in
 * front of the que, or end que,either does the remove
 * FUNCTION:
 * addFront()
 * addRear()
 * deleteFront()
 * deleteRear()
 * NOTE:
 * using one dymansional array inplemention
 * front and rear start at -1;
 * 
*/
#define MAX_SIZE 5
#define bool int
#define false 0
#define true 1
#define DEFAULT_STACK {{MAX_SIZE},-1}
#define MALLOC(ptr, size)                      \
    if (!((ptr) = malloc(size)))               \
    {                                          \
        fprintf(stderr, "Insufficent memory"); \
        exit(EXIT_FAILURE);                    \
    }
#define REALLOC(ptr, size)                      \
    if (!((ptr) = realloc(ptr, size)))               \
    {                                          \
        fprintf(stderr, "Insufficent memory"); \
        exit(EXIT_FAILURE);                    \
    }
typedef struct Element{
   char key;
   /* other field input*/
} Element;
int front = -1 ; 
int rear = -1; 
Element queue[MAX_SIZE]; 
void queFull(){
   fprintf(stderr, "Que is full, cannot add element");
   exit(EXIT_FAILURE);
}
Element queEmpty(){
   return (Element){'0'};
}
void addFront(Element element){ //SHIFTING origin array right one block
    if(rear == MAX_SIZE - 1 ) queFull();
    rear++;
    int i;
    for(i = rear ; i  > 0 ; i--){
        queue[i] = queue[i-1];
    }
    queue[0] = element;
    
}
void addRear(struct Element element){ // NORMAL QUE
    if(rear == MAX_SIZE - 1)queFull();
    queue[++rear] = element;
}
Element deleteFront(){
    if(front == rear)queEmpty();
    Element temp = queue[front];
}
void deleteRear(){}
#endif