#include <stdio.h>
#include <omp.h>
#include <iostream>

int main() {
    int N = 6;
    int i, id;
    double avg = 0;

    omp_set_num_threads(5);
# pragma omp parallel for  private(i, id) reduction(+: avg) schedule(dynamic)
    for (i = 0; i < N; ++i) {
        id = omp_get_thread_num();
        std::cout<<"Thread "<<id<<" is working on iteration "<<i<<std::endl;
        std::cout<<omp_get_num_threads()<<std::endl;
        #pragma omp critical
        {
            avg += id + i;
        }

    }

    std::cout<<"Number of threads: "<<omp_get_num_threads()<<std::endl;
    avg /= N;
    printf("%.2f\n", avg);
    return 0;
}
