#include<stdio.h>
#include<conio.h>

#define MAX 100

void merge(int *a, int l, int m, int r)
{
	int n1, n2, i, j, k, left[MAX], right[MAX];
	
	n1=m-l+1;
	n2=r-m;
	
	for(i=0;i<n1;i++)
	left[i]=a[l+i];
	
	for(j=0;j<n2;j++)
	right[j]=a[m+j+1];
	
	i=0;
	j=0;
	k=l;
	
	while(i<n1&&j<n2)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		
		else
		{
			a[k]=right[j];
			j++;
		}
		
		k++;
	}
	
	while(i<n1)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	
		while(j<n2)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int *a, int l, int r)
{
	int m;
	
	if(l<r)
	{
		m=(l+r)/2;
		
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}



main()
{
	int x[MAX],n,i;
	
	printf("\n\nEnter the number of elements in the Array : ");
	scanf("%d",&n);
	
	printf("\n\nEnter the elements one by one : \n");
	
	for(i=0;i<n;i++)
	scanf("%d",&x[i]);
	
	mergesort(x,0,n-1);
	
	printf("\n\nThe Sorted Array is : \n");
	for(i=0;i<n;i++)
	printf("%d ",x[i]);
	
	getch();
}
