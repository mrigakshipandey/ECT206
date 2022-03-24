#include<stdio.h>
#include<conio.h>

#define MAX 50

main()
{
	int a[MAX][MAX], s, d, i,j, mdn, x, di[MAX], fn[MAX], t[MAX],n;
	
	printf("\n\nEnter the number of vertices (n): ");
	scanf("%d",&n);
	
	printf("\n\nEnter the distance matrix row wise [Enter a relatively large number (eg 10000) in place of infinity] :\n");
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	
	printf("\n\nEnter the source (0 to n-1) : ");
	scanf("%d",&s);
	
	printf("\n\nEnter the destination (0 to n-1) : ");
	scanf("%d",&d);
	
	//Initializing the matrices
	
	for(i=0;i<n;i++)
	{
		di[i]=10000;
		fn[i]=10000;
		t[i]=0;
	}
	
	//Seting up initial conditions
	
	di[s]=0;
	fn[s]=s;
	mdn=s;
	
	while(mdn!=d)
	{
		for(i=0;i<n;i++)
		{
			x=di[mdn]+a[mdn][i];
			if(di[i]>x)
			{
				di[i]=x;
				fn[i]=mdn;
				t[i]=0;
			}
		}
		
		t[mdn]=1;
		
		i=0;
		
		while(i<n&&t[i]==1)
		i++;
		
		mdn=i;
		
		for(i=mdn+1;i<n;i++)
		if(t[i]==0&&di[i]<di[mdn])
		mdn=i;
	}
	
	printf("\n\nShortest distance from source to destination : %d units \nFollowing the path : %d", di[d],d);
	
	x=d;
	while(x!=s)
	{
		x=fn[x];
		printf("-%d",x);
	}
	
	getch();
}
