#include<stdio.h>
#include<conio.h>
#define N 100

main()
{
      int j,n,t,R,L,P;
      int a[N];
      
      printf("Enter the number of elements of the array:\t");
      scanf("%d",&n);
      
      printf("Enter the of elements of the array:\n\n");
      
      for(j=0; j<n; j++)
      scanf("%d",&a[j]);
      
     R=1;
     L=n-1;
     P=0;
     while(P<n)
     {
                R=P+1;
                L=n-1;
                

                          
                          while(a[L]>=a[P] && L>P)
                          L--;
                          
                
                          while(a[R]<a[P] && R<n-1)
                          R++;
                          
                          
                          if(R<L)
                          {
                                 t=a[R];
                                 a[R]=a[L];
                                 a[L]=t;
                          }
                          
                          else
                          {
                                 t=a[P];
                                 a[P]=a[L];
                                 a[L]=t; 
                          }
                          
                          if(P==L)
                          P++;
                          
                }
                
                
    
      
      
      printf("\n\nSorted Array:");
      for(j=0;j<n;j++)
      {
                   printf("\n%d",a[j]);
      }
      getch();
}
