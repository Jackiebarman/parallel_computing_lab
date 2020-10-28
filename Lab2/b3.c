// #include<stdio.h>
// #include<omp.h>
// int main()
// {
// 	int n,i,tid,low,high,p;
// 	scanf("%d",&n);
// 	int A[n],sum[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&A[i]);
// 	}

// 	#pragma omp parallel default(shared) private(tid,i,low,high) num_threads(2)
// 	{
		
// 		p=omp_get_num_threads();
// 		tid=omp_get_thread_num();
// 		if(tid==0)
// 			printf("no of thread:%d\n",p);

// 		low=(n*tid)/p;
// 		high=(n*(tid+1))/p;

// 		printf("thread %d low=%d,high=%d\n",tid,low,high);

// 		sum[tid]=0;
// 		for(i=low;i<high;i++)
// 		{
// 			sum[tid]+=A[i];
// 		}
// 		printf("sum by thread%d:%d\n",tid,sum[tid]);
// 	}

// 	int finalsum=0;
// 	for(int i=0;i<p;i++)
// 	{
// 		finalsum+=sum[i];
// 	}

// 	printf("%d",finalsum);
// 	return 0;
// }



#include<stdio.h>
#include<omp.h>
void main()
{ int x=0,i,n;
printf("Enter the value of n");
scanf("%d",&n);
#pragma omp parallel
{
int id=omp_get_thread_num();
#pragma omp for lastprivate(i)
for(i=0;i<n;i++)
{
printf("Thread %d: value of i : %d\n",id,i);
x=x+i;
printf("Thread %d: x is %d\n",id,x);
}
}
printf("x is %d\n",x);
printf("i IS %d\n",i);
}
