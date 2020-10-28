#include<stdlib.h>
#include<omp.h>
#include<stdio.h>
int main() {
    int SIZE;
    printf("ENTER THE SIZE(n):\n");
    scanf("%d",&SIZE);
    //Sequencial
    printf("SEQUENTIAL MATRIX MUlTIPLICATION: matrices of size: %d\n", SIZE);
   int **mat1 = (int **) malloc (SIZE * sizeof(int*));
   int **mat2 = (int **) malloc (SIZE * sizeof(int*));
   int **res  = (int **) malloc (SIZE * sizeof(int*));
   for(int i=0; i<SIZE; ++i) {
       mat1[i] = (int*) malloc (SIZE * sizeof(int));
       mat2[i] = (int*) malloc (SIZE * sizeof(int));
       res[i]  = (int*) malloc (SIZE * sizeof(int));
   }

   for(int i=0; i<SIZE; ++i) {
       for(int j=0; j<SIZE; ++j) {
           mat1[i][j] = rand()%100;
           mat2[i][j] = rand()%100;
       }
   }

   //perform matrix multiplication 
   double st1 = omp_get_wtime();
   for(int i=0; i<SIZE; ++i) {
       for(int j=0; j<SIZE; ++j) {
           for(int k=0; k<SIZE; ++k) {
               res[i][j] = mat1[i][k] * mat2[k][j];
           }
       }
   }
   double et1 = omp_get_wtime();
   printf("total time=%f\n", et1 - st1);
    //Parallel
    printf("PARALLEL MATRIX MULTIPLICATION: matrices of size=%d\n", SIZE);
    int** mat3 = (int **) malloc (SIZE * sizeof(int*));
    int** mat4 = (int **) malloc (SIZE * sizeof(int*));
    int** res2  = (int **) malloc (SIZE * sizeof(int*));
    
    for(int i=0; i<SIZE; ++i) {
        mat3[i] = (int*) malloc (SIZE * sizeof(int));
        mat4[i] = (int*) malloc (SIZE * sizeof(int));
        res2[i]  = (int*) malloc (SIZE * sizeof(int));
    }

    //initialize matrices
    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            mat3[i][j] = rand()%100;
            mat4[i][j] = rand()%100;
        }
    }

    //perform parallel matrix multiplication
    double st2 = omp_get_wtime();
    #pragma omp parallel for shared(mat1, mat2, res)
    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            int tmp = 0;
            for(int k=0; k<SIZE; ++k) {
                tmp += mat1[i][k] * mat2[k][j];
            }
            #pragma omp critical
            {
                res2[i][j] = tmp;
            }
        }
    }
    double et2 = omp_get_wtime();
    printf("total time=%f\n", et2 - st2);
}