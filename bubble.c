#include<stdio.h>
#define N 100

int main()
{
      int i=0, flag=0,n,j,t;
      int a[N];
      
      printf("Enter the number of elements of the array:\t");
      scanf("%d",&n);
      
      printf("Enter the of elements of the array:\n");
      
      for(j=0; j<n; j++)
      scanf("%d",&a[j]);
      
     
      while(flag==0)
      {
      flag=1;
      for(j=0;j<n-1-i; j++)
      {
            if(a[j]>a[j+1])
            {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    
                    flag=0;
            }
      }
      i++;
      }
      
      printf("\n\nSorted Array:");
      for(j=0;j<n;j++)
      {
                   printf("\n%d",a[j]);
      }
      return 0;
}
