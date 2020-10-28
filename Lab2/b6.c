#include<stdio.h>
#include<omp.h>
int main()
{
	int n,m,i,sum=0,tid;
	printf("Enter the size of the first array:");
	scanf("%d",&n);
	printf("\nEnter the size of the second array:");
	scanf("%d",&m);
	int b[n],c[m];
	printf("\nEnter the elements of the first array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nEnter the elements of the second array:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&c[i]);
	}
	// int b[5]={1,2,3,4,5};
	// int c[5]={6,7,8,9,10};
	int a[n];

	#pragma omp parallel 
	#pragma omp for 
	for(int i = 0; i < n; ++i)
	{
		tid=omp_get_thread_num();
		a[i]=b[i]+c[i];
		printf("Thread %d :%d\n",tid,a[i]);

	}

	return 0;
}