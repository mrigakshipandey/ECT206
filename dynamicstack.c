#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
       int info;
       struct node* next;
};

typedef struct node node1;


void initlist(node1 **l)
{
     *l=NULL;
}

int emptylist(node1 *l)
{
    if(l==NULL)
    return 1;
    
    else
    return 0;
}

void enterlist(node1 **l, int x)
{ 
     node1 *p;
     p=(node1*)(malloc(sizeof(node1)));
     
     p->info=x;
     p->next=*l;
     *l=p;
     
}

void deletelist(node1 **l, int *x)
{
     node1 *p;
     if(emptylist(*l)==0)
     {
           p=*l;
           *x=p->info;
           *l=p->next;
           free(p);
     }
     
     else
     printf("\nList is empty\n");
}

void traverselist(node1*l)
{
     node1 *p;
     p=l;
     
     while(p!=NULL)
     {
           printf("%d\n", p->info);
           p=p->next;
     }
}

main()
{
      node1 *list;
      int v,c=1;
      
      initlist(&list);
      while(c!=3)
      {
                 
      printf("\nEnter Your Choice\n\n1.\tEnter a Value\n2.\tDelete a value\n3.\tExit\n\nChoice:\t");
      scanf("%d",&c);
      
      
      switch(c)
      {
               case 1:
                      printf("\nEnter the value to be entered:\t");
                      scanf("%d",&v);
                      enterlist(&list,v);
                      printf("\nThe Stack Now\n");
                      traverselist(list);
                      printf("\n..................................................................\n");
                      break;
                      
               case 2:
                      deletelist(&list,&v);
                      printf("\nThe Stack Now\n");
                      traverselist(list);
                      printf("\n..................................................................\n");
                      break;
                      
               default: 
                        c=3;
      }
      }
      getch();
}
                        
