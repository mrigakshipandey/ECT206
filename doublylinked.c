#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
       int info;
       struct node *f, *b;
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
     p->f=NULL;
     p->b=NULL;
     
     q=*l;
     back=*l;
     
     if(*l==NULL)
     {
           *l=p;
     }
     
     else
     {
         q=*l;
         if(x>q->info)
         {
                      while(q!=NULL && x>q->info)
                      {
                                    back=q;
                                    q=q->f;
                      }
                      
                      p->f=q;
                      p->b=back;
                      back->f=p;
                      if(q!=NULL)
                      q->b=p;
                      *l=p;
         }
         
         else
         {
                      while(q!=NULL && x<=q->info)
                      {
                                    back=q;
                                    q=q->b;
                      }
                      
                      
					  p->f=back;
                      p->b=q;
                      back->b=p;
                      if(q!=NULL)
                      q->f=p;
                      *l=p;
         }
         
     }
}

void deletesortedlist(node1 **l, int x)
{
     node1 *p, *q, *back;
     q=*l;
     back=*l;
     
     if(*l==NULL)
     printf("\nList is Empty\n");
     
     
     else
     {
         while(q->b!=NULL)
                q=q->b;
                
         if(x>=q->info)
         {
                      
                      while(q!=NULL && x!=q->info)
                      {
                                    back=q;
                                    q=q->f;
                      }
                      
                      if(q==NULL)
                      printf("\nNODE NOT FOUND\n");
                      
                      else
                      {
                          if(back==q)
                          {
                                back=q->f;
                                back->b=NULL;
                                free(q);
                                *l=back;
                          }
                          
                          else
                          {
                              
                          back->f=q->f;
                          if(q->f!=NULL)
                          (q->f)->b=back;
                          free(q);
                          *l=back;
                          }
                          
                      }
         }
         
         else
         {
                      
                      printf("\nNODE NOT FOUND\n");
                      
         }
     }    
}

void traverselist(node1*l)
{
     node1 *q;
     
     if(l!=NULL)
     {
				q=l;
                while(q->b!=NULL)
                q=q->b;
                
                while(q!=NULL)
                {
                              printf(" %d",q->info);
                              q=q->f;
                }
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
                      printf("\nEnter the value to be deleted:\t");
                      scanf("%d",&v);
                      deletesortedlist(&list,v);
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
