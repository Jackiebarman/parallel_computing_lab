#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
int main()
{
srand(time(0));
struct timeval TimeValue_Start;
struct timezone TimeZone_Start;
struct timeval TimeValue_Final;
struct timezone TimeZone_Final;
long time_start, time_end;
double time_overhead;
int n, cur_min = 2147483647;
printf("Enter number of elements in the array: ");
scanf("%d", &n);
int array[1000000] = {2147483647};
for (int a = 0; a < n; a++)
{
array[a] = rand();
}
gettimeofday(&TimeValue_Start, &TimeZone_Start);
// #pragma omp parallel for schedule()
// #pragma omp parallel for schedule(static)
// #pragma omp parallel for schedule(static,3)
// #pragma omp parallel for schedule(dynamic,3)
// #pragma omp parallel for schedule(guided)
 #pragma omp parallel for schedule(runtime)
for (int i = 0; i < n; i = i + 1)
{
#pragma omp critical
if (array[i] < cur_min)
cur_min = array[i];
}
gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
printf("Smallest number = %d\n", cur_min);
printf("Time in Seconds (T) = %lf\n",time_overhead);
}