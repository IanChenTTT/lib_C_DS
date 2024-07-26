#ifndef QUE_H_
#define QUE_H_
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
Element queue[MAX_SIZE];
int rear = -1;
int front = -1;
int Erear = -1;
int Efront = MAX_SIZE;
bool isFull(){
   if(rear == MAX_SIZE - 1)
      return true;
   return false;
}
bool isEmpty(){
   if(front == rear)
      return true;
   return false;
}
void queFull(){
   fprintf(stderr, "Que is full, cannot add element");
   exit(EXIT_FAILURE);
}
Element queEmpty(){
   return (Element){'0'};
}
void addQ(Element item){ 
   /* add an item to the que*/
   if(rear == MAX_SIZE - 1)
      queFull();
   queue[++rear] = item;
}
void addCQ(Element item){
   /*
   *  Condition 1
   *  rear == MAX_size-1 && !front ->
   *  front is zero and rear is MAX_size -1; 
   *  Condition 2
   *  rear+1 == front->
   *  next rear is equal front
   */
   if ((rear+1 == front) ||
    ((rear == MAX_SIZE-1) && !front)) 
		queue_full();
   else {
       queue[rear] = item;
       rear = (rear+1) % MAX_SIZE;
   }
   // if(rear + 1 == MAX_SIZE){
   //    queue[rear] = item;
   //    rear++;
   // }
   // else{
   //    rear = (rear + 1) % MAX_SIZE;
   //    queue[rear] = item;
   // }
   // if(front == rear)
   //     queFull();
}
Element deleteCQ(){
   /* remove element at the front of the queue */
   if(front == rear)
      quefull();
   Element temp;
   temp = queue[front]; 
   front = front+1 % MAX_SIZE;
   return temp;
}

Element deleteQ(){ 
   /* remove element at the front of the queue */
   if(front == rear)
      quefull();
   return queue[++front];
}
#endif

/*
EX:
   Circular que front and rear start at 0;
   Capacity is 8;
   Formula is rear = (rear + 1) % Max_Que_Size 
   (0 + 1) % M
   (1 + 1) % M
   ...
   (7 + 1) % M  -> 8 % 8 = 0 
   //ERR front equal rear
   use M - 1 instead
   (0 + 1) % M - 1
   (1 + 1) % M - 1
   ...
   (6 + 1) % M - 1  -> 7 % 7 = 0 
   (7 + 1) % M - 1  -> 8 % 7 = 1 


*/