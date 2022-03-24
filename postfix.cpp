#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define N 80

int prio(char x)
{
    if(x=='=')
    return 1;
    
    if(x=='+' || x=='-')
    return 2;
    
    if(x=='*' || x=='/')
    return 3;
    
    if(x=='^')
    return 4;
}

void intstack(int* t)
{
     *t=-1;
}

int emptystack(int t)
{
    if(t==-1)
    return 1;
    
    else
    return 0;
}

    
void push(char *x, int *t, char p)
{
     *t++;
     x[*t]=p;
}

void pop(char *x, int* t, char*p)
{
     *p=x[*t];
     t=t-1;
}
main()
{
      char s[N], x[N], p;
      int l,top,i,j;
      
      printf("Enter Expression in Infix:\t");
      scanf("%s",s);
      l=strlen(s);
      printf("Expression in postfix: \t\t");
      intstack(&top);
      
      for(i=0; i<l; i++)
      {
               if(isalpha(s[i]))
               printf("%c",s[i]);
               
               
               else if(s[i]=='(')
               push(x,&top,s[i]);
               
               else if(s[i]==')')
               do
               {
                    pop(x,&top,&p);
                    
                    if(p!='(')
                    printf("%c",p);
                    
               }while(p!='(');
               
               else
               {
               	
               		
                   if(!emptystack(top))
                   {
                          pop(x,&top,&p);
                          push(x,&top,p);
                          printf(" hello ");
                   }
                   
                   while((!emptystack(top))&& (p!='(') && (prio(s[i])<=prio(p)))
                   {
                          pop(x,&top,&p);
                          printf("%c",&p);
                   }
                   printf(" hello ");
               
                   
                   if(emptystack(top))
                   push(x,&top,s[i]);
                   
               } 
      }
      
      while(!emptystack(top))
      {
                        pop(x,&top,&p);
                        printf("%c",&p);
      }
      
      getch();
}
