#ifndef ADVQUE_H_
#define ADVQUE_H_
#define MAX_SIZE 5
#define bool int
#define false 0
#define true 1
#define DEFAULT_STACK \
   {                  \
      {MAX_SIZE}, -1  \
   }
#define MALLOC(ptr, size)                    \
   if (!((ptr) = malloc(size)))              \
   {                                         \
      fprintf(stderr, "Insufficent memory"); \
      exit(EXIT_FAILURE);                    \
   }
#define REALLOC(ptr, size)                   \
   if (!((ptr) = realloc(ptr, size)))        \
   {                                         \
      fprintf(stderr, "Insufficent memory"); \
      exit(EXIT_FAILURE);                    \
   }
void Copy(void * ptStart,int endNum , void * dst){
   //std::copy(array2, array2 + 4, arrayV + i + 4);
   printf("%d \n",endNum);
   memcpy(dst,ptStart,sizeof(*ptStart) * endNum);
   //memcpy(arrayV + i + 4, array2, sizeof(*array2) * 4);
   // memcpy(dst,ptStart,sizeof(*ptStart)*(ptEnd-ptStart));
}
typedef struct
{
   char key;
   /* other field input*/
} Element;
int rear = 0;
int front = 0;
int capacity;
Element *ADqueue;
bool isFull()
{
   if (rear == MAX_SIZE - 1)return true;
   return false;
}
bool isEmpty()
{
   if (front == rear)return true;
   return false;
}
void queFull()
{
   // allocate an array with twice the capacity
   Element *TempQue;
   MALLOC(TempQue, 2 * sizeof(Element *) * capacity);
   // copy from queue to newQue
   int start = (front + 1) % capacity;
   if(start < 2){
      //NO SWAP
      printf("%d \n",start);
      Copy(ADqueue+start, (start+capacity-1),TempQue);
   }
   else{
      /*Queue wraps around */
      Copy(ADqueue+start, capacity,TempQue);
      Copy(ADqueue, start+rear+1,TempQue + capacity-start);
   }
   // switch to new Queue
   front = 2 * capacity -1;
   rear = capacity -2;
   capacity *= 2;
   free(ADqueue);
   ADqueue = TempQue;
   printf("%d rear is: \n",rear);
}
Element queEmpty()
{
   return (Element){'0'};
}
void CreateQ(int Max_Size)
{
   REALLOC(ADqueue, sizeof(Element*) * Max_Size);
   capacity = Max_Size;
}

void addq(Element item)
{
   rear = (rear + 1) % capacity;
   printf("%d rear is: \n",rear);
   if (front == rear)
      queFull(); //Doubling array capacity
   ADqueue[rear] = item;
}
void TestQ(){
   addq((Element){'A'});
   addq((Element){'B'});
   addq((Element){'C'});
}
void ReleaseQ(){
   free(ADqueue);
}
#endif

/*
EX:
   EX:
   capacity is 8;
   front = 5;
   rear = 4; //IS FULL
   1.
   start = (front + 1) % capacity
   start = (5 + 1) % 8 -> 6
   2.
   //que is start pointer
   //void *memcpy(void *to, const void *from, size_t numBytes);
   Copy(que+start, que+capacity,TempQue);
   Copy(que, que+start+rear+1,TempQue + capacity-start);
   (0+6,0+8,Tempque)
*/
