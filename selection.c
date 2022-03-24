#include<stdio.h>
#include<conio.h>
#define N 100

main()
{
      int i,j,n,t,s;
      int a[N];
      
      printf("Enter the number of elements of the array:\t");
      scanf("%d",&n);
      
      printf("Enter the of elements of the array:\n");
      
      for(j=0; j<n; j++)
      scanf("%d",&a[j]);
      
     
      for(i=0;i<n;i++)
      {
                      s=i;
                      
                      for(j=i+1;j<n;j++)
                      {
                                        if(a[j]<a[s])
                                        s=j;
                      }
                      
                      t=a[i];
                      a[i]=a[s];
                      a[s]=t;
      }
      
      printf("\n\nSorted Array:");
      for(j=0;j<n;j++)
      {
                   printf("\n%d",a[j]);
      }
      getch();
}
