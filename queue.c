#include<stdio.h>
#include<conio.h>

#define N 4

void initq(int *f, int *r)
{
     *f=0;
     *r=0;
}

int emptyq(int f, int r)
{
    if(f==r)
    return 1;
    
    else
    return 0;
}

int fullq(int f, int r)
{
    if(r==N)
    return 1;
    
    else
    return 0;
}

int enterq(int *a, int *f, int *r, int x)
{
    if(fullq(*f,*r)==0)
    {
           a[*r]=x;
           *r=*r+1;
    }
    
    else
    printf("\n\nQueue Overflow");
}

void deleteq(int *a, int *f, int *r, int *x)
{
     int i;
     if(emptyq(*f,*r)==0)
     {
            *x=a[*f];
            
            for(i=1; i<*r; i++)
            a[i-1]=a[i];
            *r=*r-1;
     }
     
     else
     printf("\n\nEmpty Queue");
}

main()
{
      int queue[N], front, rear, n, p, q, i, j;
      
      initq(&front, &rear);
      q=1;
      while(q!=3)
      {
      printf("\n\nQueue Implementation\n\nEnter your choice\n\n1.\tEnter Element\n2.\tDelete Element\n3.\tExit\n\n");
      scanf("%d",&q);
      
      
      switch(q)
      {
               case 1: printf("\n\nEnter the element to be entered:\t");
                       scanf("%d",&p);
                       enterq(queue, &front, &rear, p);
                       printf("\nThe queue is:\n"); 
                       for(i=0;i<rear;i++)
                       {
                               printf("%d ",queue[i]);
                       }
                       break;
                       
               case 2: deleteq(queue, &front, &rear, &p);
                       printf("\n\n The queue is:\n",p);
                       for(i=0;i<rear;i++)
                       {
                               printf("%d ",queue[i]);
                       }
                       break;
      }
      }
getch();
}
