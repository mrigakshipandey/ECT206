#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

typedef struct node node1;

void initq(node1 **list)
{
	*list=NULL;
}

int emptyq(node1 *list)
{
	if(list==NULL)
	return 1;
	
	else
	return 0;
}

void addq(node1 **list, int x)
{
	node1 *p;
	
	p=(node1*)(malloc(sizeof(node1)));
	
	p->info=x;
	
	if(*list==NULL)
	{
		p->next=p;
		(*list)=p;
	}
	
	else
	{
		p->next=(*list)->next;
		(*list)->next=p;
		(*list)=p;
	}
}

void deleteq(node1 **list, int *x)
{
	node1 *p;
	
	if((*list)==NULL)
	{
		printf("\n\nList is Empty");
	}
	
	else if(((*list)->next)==(*list))
	{
		*x=(*list)->info;
		free(*list);
		(*list)=NULL;
	}
	
	else
	{
		p=(*list)->next;
		*x=p->info;
		(*list)->next=p->next;
		free(p);
	}
}

void traverseq(node1 *list)
{
	int c=1;
	node1 *p;
	p=list;
	
	if(list!=NULL)
	{
		printf("\n");
	
		while(c)
		{
			p=p->next;
			printf("%d ", p->info);
		
			if(p==list)
			c=0;		
		}
	}
	
}

main()
{
	int p, q;
	node1 *list;
      
      initq(&list);
      q=1;
      while(q!=3)
      {
      printf("\n\nQueue Implementation\n\nEnter your choice\n\n1.\tEnter Element\n2.\tDelete Element\n3.\tExit\n\n");
      scanf("%d",&q);
      
      
      switch(q)
      {
               case 1: printf("\n\nEnter the element to be entered:\t");
                       scanf("%d",&p);
                       addq(&list, p);
                       printf("\n\nThe queue is:");
					   traverseq(list);
					   printf("\n..................................................................\n"); 
					   break;
                       
               case 2: deleteq(&list, &p);
                       printf("\n\n The queue is:");
                       traverseq(list);
                       printf("\n..................................................................\n");
                       break;
      }
    }
getch();
}
		
		
	
