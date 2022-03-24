#include<stdio.h>
#include<conio.h>

void write_a(int p,char* q)
{
	int i;
	
	for (i=0;i<600;i++)
	q[i]=0;
	
	q[0]=p%10;
	p=p/10;
	q[1]=p%10;
	p=p/10;
	q[2]=p%10;
}

void multiply_ab(char* p, int q)
{
	int i,carry,mul;
	carry=0;
	for(i=0;i<600;i++)
	{mul=p[i]*q+carry;
	p[i]= mul%10;
	carry=mul/10;
	}
}

void printfact(char* p)
{
	int i;
	for (i=599;i>=0;i--)
	printf("%d",p[i]);
}
main()
{
	char a[600];
	int x,i,num;
	printf("\n\n\nEnter a number :");
	scanf("%d",x);
	num=x;
	write_a(x,a);
	
	for(i=num-1;i>=1;i--)
			multiply_ab(a,i);
	
	
	printf("\n\nfactorial of %d is",num);
	printfact(a);
	
	getch();
}
