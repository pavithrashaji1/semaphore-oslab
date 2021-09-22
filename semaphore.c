#include<stdio.h>
#include<stdlib.h>
 
int a=1, full=0, empty=3, x=0;
void main()
{
   int n;
   void p();
   void c();
   int wait(int);
   int signal(int);
   printf("\n1.Producer\n2.Consumer\n3.Exit");
   while(1)
   {
      printf("\n\nEnter your choice: ");
      scanf("%d",&n);
      switch(n)
      {
         case 1: if((a==1)&&(empty!=0))
                        p();
                     else
                        printf("Buffer is full!!");
                     break;
         case 2: if((a==1)&&(full!=0))
                        c();
                     else
                        printf("Buffer is empty!!");
                     break;
        case 3:  exit(0);
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
 
void p()
{
   a = wait(a);
   full = signal(full);
   empty = wait(empty);
   x++;
   printf("Producer produces the item %d", x);
   a = signal(a);
}
 
void c()
{
   a = wait(a);
   full = wait(full);
   empty = signal(empty);
   printf("Consumer consumes item %d", x);
   x--;
   a = signal(a);
}
