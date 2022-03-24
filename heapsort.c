#include<stdio.h>
#include<conio.h>

#define MAX 100

void heapify(int *a, int root, int end)
{
	int maxchild, left, right, t;
	
	if(root<=((end-1)/2))
	{
		left=root*2+1;
		right=root*2+2;
		
		if(left==end)
		maxchild=left;
		
		else if(a[left]>a[right])
		maxchild=left;
		
		else
		maxchild=right;
		
		if(a[root]<a[maxchild])
		{
			t=a[root];
			a[root]=a[maxchild];
			a[maxchild]=t;
			
			heapify(a,maxchild,end);
		}
	}
}

void initheap(int *a, int n)
{
	int i;
	
	for(i=((n-2)/2); i>=0; i--)
	heapify(a,i,n-1);
}

void heapsort(int *a, int root, int end)
{
	int t;
	if(root<end)
	{
		heapify(a,root,end);
		
		t=a[root];
		a[root]=a[end];
		a[end]=t;
		
		heapsort(a,root,end-1);
	}
}

main()
{
	int a[MAX],n,i;
	
	printf("\n\nEnter the number of elements in the heap : ");
	scanf("%d",&n);
	
	printf("\n\nEnter the elements one by one : \n");
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	initheap(a,n);
	
	heapsort(a,0,n-1);
	
	printf("\n\nThe Sorted Array is : \n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	getch();
}
