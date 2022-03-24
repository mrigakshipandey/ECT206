#include<stdio.h>
main()
{
	
	
	float M[15][15]; int i,j,k,l; int n; float I[15][15];  int t; float q,r;
	
	
	printf("\n\n\n\n");
	
	printf("\n\nPlease Enter Order of the matrix ");
	scanf("%d", &n);
	
	printf("\n\nEnter the Elements of the matrix one by one:\n");
	for(i=0;i<n;i++)
	{  for(j=0;j<n;j++)
	     {   scanf("%f", &M[i][j]);
		 }	
	}
	
	
	for(i=0;i<n;i++)
	   {   for(j=0;j<n;j++)   
	   							 {        if(i==j)  I[i][j]=1;
	   							          else I[i][j]=0;
	  						    }
	   }
	
	
	
		printf("\n\n\n\tYour Matrix is: \n\n");
	for(i=0;i<n;i++)
	{  for(j=0;j<n;j++)
	     {   printf("\t%f",M[i][j]);
	     }
	    printf("\n");     
	}	


	printf("\n\n\n\tIdentity Matrix is: \n\n");
	for(i=0;i<n;i++)
	{  for(j=0;j<n;j++)
	     {   printf("\t%f",I[i][j]);
	     }
	    printf("\n");     
	}	




	 for(j=0;j<n;j++)
 {
  			for(i=0;i<n;i++)
   				{				q=M[i][j];
   									 			if(i==j)    {  for(k=0;k<n;k++)
		  																 			{  
																		   				 M[i][k]=M[i][k]/q; 
																		   				I[i][k]=I[i][k]/q; t=i;    }
											    			}
   				}
   		
		   	for(i=0;i<n;i++)						
				{
				               r=M[i][j];
									   			 if(i!=j)   {  for(k=0;k<n;k++)
		  																			 {     M[i][k]=M[i][k]-r*M[t][k];
		    																   			   I[i][k]=I[i][k]-r*I[t][k];    }
															}			
  				}
 }

			printf("\n\n\n\tThe Inverse of your Matrix is: \n\n");

	for(i=0;i<n;i++)
						{  for(j=0;j<n;j++)
	    											 {   printf("\t%f",I[i][j]);  }
	    											 
	   					 printf("\n");  
  						 }

printf("\n\n\n\n\n\n");

}
