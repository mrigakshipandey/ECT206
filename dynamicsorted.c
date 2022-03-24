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
void entersortedlist(node1 **l, int x)
{ 
     node1 *p,*q,*back;
     p=(node1*)(malloc(sizeof(node1)));
     
     p->info=x;
     q=*l;
     back=*l;
     
     if(*l==NULL)
     {
           p->next=NULL;
           *l=p;
     }
     
     else
     {
         while(q!=NULL && (q->info)<x)
         {
                back=q;
                q=q->next;
         }
         
         if(back==q)
         {
                p->next=*l;
                *l=p;
         }
         
         else 
         {
              back->next=p;
              p->next=q;
         }
         
     }
}

void deletesortedlist(node1 **l, int *x)
{
     node1 *p, *q, *back;
     q=*l;
     back=*l;
     
     if(q==NULL)
     printf("\nList is Empty\n");
     
     else
     {
         while(q!=NULL && q->info!=*x)
         {
               back=q;
               q=q->next;
         }
         
         if(q==NULL)
         printf("\nValue not in the list\n");
         
         else
         {
             if(back==q)
             {
                   *l=(*l)->next;
                   free(q);
             }
             
             else
             {
                 back->next=q->next;
                 free(q);
             }
         }
     }    
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
                      entersortedlist(&list,v);
                      printf("\nThe Stack Now\n");
                      traverselist(list);
                      printf("\n..................................................................\n");
                      break;
                      
               case 2:
                      printf("\nEnter the value to be delete:\t");
                      scanf("%d",&v);
                      deletesortedlist(&list,&v);
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
