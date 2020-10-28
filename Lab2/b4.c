// #include<stdio.h>
// #include<omp.h>
// int main()
// {
// 	int n,i,tid,low,high,p,finalsum=0;
// 	scanf("%d",&n);
// 	int A[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&A[i]);
// 	}

// 	#pragma omp parallel default(shared) private(tid,i,low,high) num_threads(2) reduction(+:finalsum)
// 	{
		
// 		p=omp_get_num_threads();
// 		tid=omp_get_thread_num();
// 		if(tid==0)
// 			printf("no of thread:%d\n",p);

// 		low=(n*tid)/p;
// 		high=(n*(tid+1))/p;

// 		printf("thread %d low=%d,high=%d\n",tid,low,high);

// 		//sum[tid]=0;
// 		for(i=low;i<high;i++)
// 		{
// 			finalsum+=A[i];
// 		}
// 		//printf("sum by thread%d:%d\n",tid,sum[tid]);
// 	}

	

// 	printf("%d",finalsum);
// 	return 0;
// }

#include<stdio.h>
#include<omp.h>
void main()
{
int x=0;
#pragma omp parallel num_threads(6) reduction(+:x)
{
int id=omp_get_thread_num();
int threads=omp_get_num_threads();
x=x+1;
printf("Hi from %d\n value of x : %d\n",id,x);
}
printf("Final x:%d\n",x);
}
