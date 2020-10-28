#include<stdio.h>
#include<omp.h>
int main()
{
	int n,i,sum=0,tid;
	printf("Enter the size of the array:");
	scanf("%d",&n);
    printf("\nEnter the elements of the array:\n");
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}

	#pragma omp parallel num_threads(2)
	{
		tid=omp_get_thread_num();
		#pragma omp for schedule(static,4) reduction(+:sum)
		for(i=0;i<n;i++)
		{
			sum+=A[i];
		}
	}

	printf("sum is :%d\n",sum);

	return 0;
}