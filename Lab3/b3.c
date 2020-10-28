#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
int i,j;
#pragma omp parallel 
{
   #pragma omp for schedule(static,3) private(i,j) collapse(2)
     for(i=0;i<6;i++)
     {	
      	for(j=0;j<5;j++)
     	{ 
     		for(int k=0;k<4;k++)
     		{
      			int tid2=omp_get_thread_num();
       			printf("tid=%d, i=%d  j=%d k=%d\n",omp_get_thread_num(),i,j,k);
     		}
     	}
    }
 
}
return 0;
}