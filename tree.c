#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
       int info;
       struct node *l, *r;
};

typedef struct node node1;


void inittree(node1 **root)
{
     *root=NULL;
}


void addtree(node1 **root, int x)
{ 
     node1 *p,*q,*back;
     p=(node1*)(malloc(sizeof(node1)));
     
     p->info=x;
     p->r=NULL;
     p->l=NULL;
     
     if(*root==NULL)
     {
                    *root=p;
     }
         
     
     else
     {
         q=*root;
         back=*root;
         
         while(q!=NULL)
         {
                       back=q;
                       
                       if(x<=q->info)
                       {
                                     q=q->l;
                       }
                       
                       else
                       {
                                     q=q->r;
                       }
         }
                       if(x<=back->info)
                       back->l=p;
                       
                       else
                       back->r=p;
     }
     
         
}
     



void inaorder(node1*root)
{
     if(root!=NULL)
     {
                   inaorder(root->l);
                   printf("%d ",root->info);
                   inaorder(root->r);
     }
}

void indorder(node1*root)
{
     if(root!=NULL)
     {
                   indorder(root->r);
                   printf("%d ",root->info);
                   indorder(root->l);
     }
}

void preorder(node1*root)
{
     if(root!=NULL)
     {
                   printf("%d ",root->info);
                   preorder(root->l);
                   preorder(root->r);
     }
}

void postorder(node1*root)
{
     if(root!=NULL)
     {
                   postorder(root->l);
                   postorder(root->r);
                   printf("%d ",root->info);
     }
}

int searchtree(node1 *root, int x)
{
    node1 *p;
    p=root;
    
    while(p!=NULL && p->info!=x)
    {
                  if(x<=p->info)
                  p=p->l;
                  else
                  p=p->r;
    }
    
    if(p==NULL)
    return 0;
    else
    return 1;
}

void deletetree(node1 **root, int x)
{ 
     node1 *p,*q,*back;
     
     p=*root; back=*root;
     
     while(p!=NULL && p->info!=x)
     {
            back=p;
            if(x<=p->info)
            p=p->l;
            else
            p=p->r;
     }
     
     if(p==NULL)
     printf("\nValue is not present in tree\n");
     
     else
     {
         if(back==p)
         {
                    if(p->l==NULL && p->r==NULL)
                    {
                                  free(p);
                                  *root=NULL;
                    }
                    
                    else if(p->l==NULL || p->r==NULL)
                    {
                         if(p->l==NULL)
                         {
                                 *root=p->r;
                                 free(p);
                         }
                         else
                         {
                              *root=p->r;
                              free(p);
                         }
                    }
                    else
                    {
                        //Third Secton
                        back=p;
                        q=p->l;
                 
                        while(q->r!=NULL)
                        {
                               back=q;
                               q=q->r;
                        }
                               p->info=q->info;
                               
                               if(back==p)
                               back->l=q->l;
                               else
                               back->r=q->l;
                               
							   free(q);
					}
                 
         }
         else
         {
             if(p->l==NULL && p->r==NULL)
             {
                    if(back->l=p)
                    back->l=NULL;
                    
                    else
                    back->r=NULL;
                    
                    free(p);
             }
             
             else if(p->l==NULL || p->r==NULL)
             {
                  if(p->l==NULL)
                  {
                                if(back->l==p)
                                back->l=p->r;
                                else
                                back->r=p->r;
                  }
                  
                  else
                  {
                                if(back->l==p)
                                back->l=p->l;
                                else
                                back->r=p->l;
                  }
                  
                  free(p);
             }
             else
                    {
                        //Third Secton
                        back=p;
                        q=p->l;
                 
                        while(q->r!=NULL)
                        {
                               back=q;
                               q=q->r;
                        }
                               p->info=q->info;
                               
                               if(back==p)
                               back->l=q->l;
                               else
                               back->r=q->l;
                               
							   free(q);
					}
         }
     }
}

main()
{
      node1 *list;
      int v,c=1,w;
      
      inittree(&list);
      while(c!=8)
      {
                 
      printf("\nEnter Your Choice\n\n1.\tEnter a Value\n2.\tSearch a Value\n3.\tPrint in ascending order\n4.\tPrint in descending order\n5.\tPrint in pre-order\n6.\tPrint in post-order\n7.\tDelete a Value\n8.\tExit\n\nChoice:\t");
      scanf("%d",&c);
      
      
      switch(c)
      {
               case 1:
                      printf("\nEnter the value to be entered:\t");
                      scanf("%d",&v);
                      addtree(&list,v);
                      printf("\n..................................................................\n");
                      break;
                      
               case 2:
                      printf("\nEnter the value to be searched:\t");
                      scanf("%d",&v);
                      w=searchtree(list,v);
                      if(w)
                      printf("\nValue present in tree\n");
                      else
                      printf("\nValue is not present in tree\n");
                      printf("\n..................................................................\n");
                      break;
               case 3:
                      printf("\nThe Tree in ascending order\n");
                      inaorder(list);
                      printf("\n..................................................................\n");
                      break;
               case 4:
                      printf("\nThe Tree in descending order\n");
                      indorder(list);                      
                      printf("\n..................................................................\n");
                      break;
               case 5:
                      printf("\nThe Tree in pre-order\n");
                      preorder(list);                      
                      printf("\n..................................................................\n");
                      break;
               case 6:
                      printf("\nThe Tree in post-order\n");
                      postorder(list);                      
                      printf("\n..................................................................\n");
                      break;
                      
               case 7:
                      printf("\nEnter the Value to be deleted:\t\n");
                      scanf("%d",&v);
                      deletetree(&list,v);                      
                      printf("\n..................................................................\n");
                      break;
                     
               default: 
                        c=8;
      }
      }
      getch();
}
