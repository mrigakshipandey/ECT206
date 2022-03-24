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
      
     
      for(i=1;i<n;i++)
      {
                      t=a[i];
                      j=i-1;
                      
                      while(j>=0 && t<a[j])
                      {
                                        a[j+1]=a[j];
                                        j--;
                      }
                      
                      a[j+1]=t;
      }
      
      printf("\n\nSorted Array:");
      for(j=0;j<n;j++)
      {
                   printf("\n%d",a[j]);
      }
      getch();
}
