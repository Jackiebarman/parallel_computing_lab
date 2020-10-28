#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
// int main()
// {
// 	int i=0,tid;
// 	#pragma omp parallel 
// 	#pragma omp for
// 	for(i=0;i<10;i++)
// 	{
// 			tid=omp_get_thread_num();
// 			printf("thread %d :%d\n",tid,i);
// 	}
// 	return 0;
// }


//
/*shared.c*/
//#include<omp.h>
int main()
{
int x=0;
#pragma omp parallel shared(x)
{
int tid=omp_get_thread_num();
x=x+1;
printf("Thread [%d] value of x is %d\n",tid,x);
}
}
