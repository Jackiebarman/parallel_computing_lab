#include<stdio.h>
#include<omp.h>
int main()
{
	int a=0,tid;
	#pragma omp parallel num_threads(2) private(a)
	{
		tid=omp_get_thread_num();
		printf("thead %d:%d\n",tid,a);
		a=10;
		printf("thead %d:%d\n",tid,a);
		a=a+1;
		printf("thead %d:%d\n",tid,a);


	}


	printf("outside %d",a);
return 0;
}

// #include<stdio.h>
// #include<omp.h>
// int main()
// {
// int i=10;
// printf("Value before pragma i=%d\n",i);
// #pragma omp parallel num_threads(4) firstprivate(i)
// {
 
// printf("Value after entering pragma i=%d tid=%d\n",i, omp_get_thread_num());
// i=i+omp_get_thread_num(); //adds thread_id to i
// printf("Value after changing value i=%d tid=%d\n",i, omp_get_thread_num());
// }
// printf("Value after having pragma i=%d tid=%d\n",i, omp_get_thread_num());
// }

