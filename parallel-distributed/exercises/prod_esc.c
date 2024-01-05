#include <stdlib.h>
#include <stdio.h>
#include<omp.h>
#include <time.h>

int main(int argc, char* argv[]){
     double sum = 0;
     int n = 256;
     register int i;
     double a[n], b[n];
     
     for (i=0; i<n; i++){
         a[i] = i * 0.5;
         b[i] = i * 2.0;
     }
     
     
     int num_threads = atoi(argv[1]);
     int num_procs = omp_get_num_procs();
    
     omp_set_dynamic(0);
     omp_set_num_threads(num_threads);
    
     printf("--------------------------------------------------\n");
    
     clock_t start = clock();

    #pragma omp parallel for shared(a,b,n) private(i) reduction(+: sum)
     for (i=0; i<n; i++){
        printf("numero de thread = %d  ,  indice = %d\n",omp_get_thread_num(),i);
        sum += a[i]*b[i];
     }
     
     clock_t end = clock();
     float seconds = (float)(end - start) / CLOCKS_PER_SEC;
     
     printf("--------------------------------------------------\n");
     
     printf ("sum = %f\n", sum);
     printf("numero de cores = %d\n",omp_get_num_procs());
     printf("numero de threads = %d\n",omp_get_max_threads());
     printf("segundos = %lf\n\n",seconds);
     return 0;
}
