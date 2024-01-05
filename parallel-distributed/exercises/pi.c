#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n, i;
    double pi, h, sum, x, a;
    n = atoi(argv[1]);
    h = 1.0 / (double) n;
    sum = 0.0;
    
    int num_threads = atoi(argv[2]);
    int num_procs = omp_get_num_procs();
    
    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);
    
    printf("--------------------------------------------------\n");
    
    clock_t start = clock();
    
    #pragma omp parallel for private(i,x) shared(h) reduction(+: sum)
    for (i = 1; i <= n; i ++) {
        printf("numero de thread = %d  ,  indice = %d\n",omp_get_thread_num(),i);
        x = h * ((double) i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    printf("--------------------------------------------------\n");
    
    pi = h * sum;
    printf("\npi is approximately %.16f\n", pi);
    printf("numero de cores = %d\n",omp_get_num_procs());
    printf("numero de threads = %d\n",omp_get_max_threads());
    printf("segundos = %lf\n\n",seconds);
    return 0;
}
