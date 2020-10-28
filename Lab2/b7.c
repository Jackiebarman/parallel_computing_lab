// // #include<stdio.h>
// // #include<omp.h>
// // int main()
// //    {
// //       for (i = 0; i < MAX; i++)
// //          x[i] = random()/(double)1147483648;


// //       #pragma omp parallel
// //       {
// //          int id;
// //          int i, n, start, stop;
// //          double my_min;

// //          n = MAX/omp_get_num_threads();   // step = MAX/number of threads.

// //          id = omp_get_thread_num();       // id is one of 0, 1, ..., (num_threads-1)

// //          start = id * n;

// //          if ( id != (num_threads-1) )
// //          {
// //             stop = start + n;
// //          }
// //          else
// //          {
// //             stop = MAX;
// //          }

// //          my_min = x[start];

// //          for (i = start+1; i < stop; i++ )
// //          {

// //             if ( x[i] < my_min )
// //                my_min = x[i];
// //          }

// //          min[id] = my_min;	// Store result in min[id]   
// //       }
// //       my_min = min[0];

// //       for (i = 1; i < num_threads; i++)
// //          if ( min[i] < my_min )
// //             my_min = min[i];
// //    }

// #include<stdio.h>
// #include<omp.h>
// #define MAX 1000000
// #define MINI -1000000
// int main()
// {
//    int n,i,maxi=MINI,tid;
//    printf("Enter the size of the array:");
//    scanf("%d",&n);
//    int b[n];
//    printf("\nEnter the elements of the array:\n");
//    for(i=0;i<n;i++)
//    {
//       scanf("%d",&b[i]);
//    }

//    #pragma omp parallel 
//    #pragma omp for 
//    for(int i = 0; i < n; ++i)
//    {
//       tid=omp_get_thread_num();
//       printf("Thread %d :%d\n",tid,b[i]);
//       if(b[i]>maxi)
//       {
//          maxi=b[i];
//       }
//    }
//    printf("\nMinimum/Largest value among the array: %d\n",maxi);

//    return 0;
// }

#include<stdio.h>
#include<omp.h>
int main()
{
int tid,maximum=0;
int a[5]={1,2,3,4,5};
#pragma omp parallel for reduction(max:maximum)
for(int i = 0; i < 5; ++i)
{
tid=omp_get_thread_num();
if(a[i]>maximum)
{
maximum=a[i];
}
}
printf("maximum=%d\n",maximum);
return 0;
}