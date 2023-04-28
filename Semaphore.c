//The following program executes a Semaphore algorithm.
//Semaphores are used in OS to prevent critical section problems and they are synchronization primitive.
//Semaphore is a variable or abstract data type used to control access to a common resource by multiple threads.



#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,x=0;
//Producer process creates new items.
void producer()
{
--mutex;
++full;
x++;
printf("\n Item_%d is produced.",x);
mutex++;
}
//Consumer process consumes the recently produced items
void consumer()
{
mutex++;
full--;
if(x!=0)
 {
 printf("\n Item_%d is consumed.",x);
 x--;
empty--;
--mutex;
 }
}
//Main Function
void main()
{
int n,i;
printf("\nEnter 1->Producer   2->Consumer   (Any other number)->Exit \n");
do
{
 printf("\nEnter the choice: ");
 scanf("%d",&n);
 switch(n)
  {
   case 1:
         if ((mutex==1)&&(empty!=0))
           producer();                //Calls producer function
         else
           printf("Buffer full");
  break;
  case 2:
        if ((mutex==1)&&(full!=0))
           consumer();              //Calls consumer function
        else
          printf("Buffer empty");
   break;
  }
 }while(n==1||n==2);                       
}
