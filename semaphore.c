#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;

int main( )
{
 int n;
 void producer();
 void consumer();
 int wait(int);
 int signal(int);
 printf("\n1.producer\n2.consumer\n3.exit");
 while(1)
 {
  printf("\nenter your choice");
  scanf("%d",&n);
  switch(n)
  { 
    case 1: if((mutex==1)&&(empty!=0))
          producer();
         else
          printf("buffer is full");
          break;
    case 2:if((mutex==1)&&(full!=0))
          consumer();
         else
           printf("buffer is empty");
           break;
    case 3:
         exit(0);
         break;
  }
 }
}
  int wait(int s)
  {
    return (--s);
  }
  int signal(int s)
  {
    return(++s);
  }
  void producer()
  {
   mutex=wait(mutex);
   full=signal(full);
   empty=wait(empty);
   printf("\nproducers produce the  item %d",x);
   x++;
   mutex=signal(mutex);
  }
  void consumer()
  {
   mutex=wait(mutex);
   full=wait(full);
   empty=signal(empty);
   printf("\nconsumer consumes item %d",x);
   x--;
   mutex=signal(mutex);
  }

output
1.producer
2.consumer
3.exit
enter your choice1

producers produce the  item 0
enter your choice2

consumer consumes item 0
enter your choice2
buffer is empty
enter your choice1

producers produce the  item -1
enter your choice2

consumer consumes item -1
enter your choice1

producers produce the  item -2
enter your choice2

consumer consumes item -2
enter your choice2
buffer is empty
enter your choice3
vitcse@vitcse-ThinkCentre-M70t-Gen-4:~$ gedit sema.c



  
   
          
