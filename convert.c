#include<stdio.h>

void binary(int x)
{
	if(x!=0)
	{
		int rem, q;
		q=x/2;
		rem=x%2;
	
		binary(q);
		printf("%d",rem);
	}
}

void octal(int x)
{
	if(x!=0)
	{	
		int rem, q;
		q=x/8;
		rem=x%8;
	
		octal(q);
		printf("%d",rem);
	}
}

void hexa(int x)
{
	if(x!=0)
	{	
		int rem, q;
		q=x/16;
		rem=x%16;
	
		hexa(q);
		if(rem<10)
		printf("%d",rem);
		else
		printf("%c",55+rem);
	}
}

main()
{
	int x;
	printf("\nEnter a number in Decimal:\t");
	scanf("%d",&x);
	printf("\n\nBinary:\t");
	binary(x);
	printf("\n\nOctal:\t");
	octal(x);
	printf("\n\nHexadecimal:\t");
	hexa(x);
		
	getch();
}
