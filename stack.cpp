#include<conio.h>
#include<stdio.h>

#define N 4

int initstack()
{
	return -1;
}

int emptystack(int t)
{
	if(t==-1)
	return 1;
	
	else
	return 0;
}

int fullstack(int t)
{
	if(t==N-1)
	return 1;
	
	else return 0;
}

void push(char *x, int *t, char p)
{
	*t++;
	x[*t]=p;
}

void pop(char *x, int *t, char *p)
{
	*p=x[*t];
	*t--;
}

main()
{
      int top, n, i,q;
      char a[N],p;
      
      top=initstack();
      q=1;
      while(q!=3)
      {
      printf("\n\nStack Implementation\n\nEnter your choice\n\n1.\tEnter Element\n2.\tDelete Element\n3.\tExit\n\n");
      scanf("%d",&q);
      
      
      switch(q)
      {
               case 1: 	if(!fullstack(top))
               		{
			   			printf("\n\nEnter the element to be entered:\t");
                       	p=getche();
                       	push(a, &top, p);
                       	printf("\nThe the stack is:\n"); 
                       for(i=0;i<=top;i++)
                       {
                               putch(a[i]);
                       }
                   }
                   
                   else printf("\n\nStack Overflow");
                       break;
                       
               case 2: if(!emptystack(top))
               		{
			   			pop(a, &top, &p);
                       	printf("\nThe the stack is:\n"); 
                       for(i=0;i<=top;i++)
                       {
                               printf("%c ",a[i]);
                       }
                   }
                   
                   else printf("\n\nStack Underflowflow");
                       break;
                             }
      }
getch();
}
