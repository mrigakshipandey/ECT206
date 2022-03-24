#include<stdio.h>
#include<conio.h>
#include<math.h>

#define N 100

void intl(int* x)
{
	int i;
	for( i=0; i< N; i++)
	x[i]=0;
}

void getl(int*x)
{
	int p[N],i=1;
	char d;
	
	while( (d=getche())!=13)
	{
		if(d>=48&&d<=57)
		{
			p[i]=d-48;
			i++;
		}
	}
	
	x[0]=i-1;
	
	for(i=x[0];i>0;i--)
	{
		x[x[0]-i+1]=p[i];
		
	}
}

void printl(int* x)
{
	int i;
	if(x[0]>0)
	{
		for(i=x[0]; i>0; i--)
		printf("%d",x[i]);
		printf("\n");
	}
	
	else
	printf("0\n");
}

void convertl(int n, int* x)
{
	int i=1;
	
	while(n>0)
	{
		x[i]=n%10;
		n=n/10;
		i++;
	}
	
	x[0]=i-1;
}

void addl(int*x, int*y, int*p)
{
	int d,i,c=0,z[N];
	
	 d=(x[0]>y[0])?x[0]:y[0];
	 z[0]=d;
	 
	 
	for(i=1; i<=d; i++)
	{
		z[i]=(x[i]+y[i]+c)%10;
		c=(x[i]+y[i]+c)/10;
	} 
	 
	if(c==1) 
	{
		z[0]=d+1;
		z[d+1]=1;
	}
	
	for(i=0; i<=d+1; i++)
	{
		p[i]=z[i];
	
	} 
	
}

int compl(int*x,int*y)
{
	int i=0,d;
	d=(x[0]>y[0])?x[0]:y[0];
	
	while(i==0&&d>0)
	{
		if(x[d]<y[d])
		i=-1;
		
		if(x[d]>y[d])
		i=1;
		
		d--;
	}
	
	return i;
}

void difl(int*x,int*y,int*z)
{
	int w,i,d;
	d=(x[0]>y[0])?x[0]:y[0];
	z[0]=d;
	w=compl(x,y);
	
	if(w==1)
	{
		for(i=1;i<=d;i++)
		{
			if(x[i]>=y[i])
			z[i]=x[i]-y[i];
			
			else
			{
				z[i]=x[i]-y[i]+10;
				x[i+1]= x[i+1]-1;
			}
		}
	}
	
	if(w==-1)
	{
		for(i=1;i<=d;i++)
		{
			if(x[i]<=y[i])
			z[i]=y[i]-x[i];
			
			else
			{
				z[i]=y[i]-x[i]+10;
				y[i+1]= y[i+1]-1;
			}
		}
		
	}	
}

void mull(int*x,int*y,int*z)
{
	int i,j,buff[N],carry;
	z[0]=x[0]+y[0];
	
		
	for(i=1;i<=z[0];i++)
	{	
		carry=0;
		intl(buff);
		buff[0]=x[0]+y[0];
		
		for(j=1;j<=z[0]||carry!=0;j++)
		{
			buff[i+j-1]=((x[j]*y[i])+carry)%10;
			carry=((x[j]*y[i])+carry)/10;
		}
			
		addl(z,buff,z);
	}
	
}

main()
{
	int a[N],b[N],c[N];
	printf("\n\tEnter First Number:\n\t");
	getl(a);
	
	printf("\n\n\tEnter Second Number:\n\t");
	getl(b);
	
	intl(c);
	printf("\n\n\tAdding the two numbers:\n\t");
	addl(a,b,c);
	printl(c);
	
	printf("\n\tComparing the two numbers:\n\t");
	switch(compl(a,b))
	{
		case 1: printf("First number is greater\n");
				break;
				
		case 0: printf("Both numbers are equal\n");
				break;
				
		case -1: printf("Second number is greater\n");
				break;
	}
	
	intl(c);
	printf("\n\tDifference between the two numbers two numbers:\n\t");
	difl(a,b,c);
	printl(c);
	
	intl(c);
	printf("\n\tProduct of the two numbers two numbers:\n\t");
	mull(a,b,c);
	printl(c);
	
}
