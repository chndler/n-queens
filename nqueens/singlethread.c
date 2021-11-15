#include "nqueens_library.h"

int main(int argc, char *argv[]){
    int i, rc, solutions, n, out_flag;
    thread_info_t infopointer;
    void *status;
    struct timeval start, end;
    double t1, t2;

    printf("Single thread\n"); 
    if(argc != 2){
        printf("Usage: %s n\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    
    // solutions = generate_n_queens_serial(n, out_flag);   
    // solutions = generate_n_queens_serial_one(n, print_flag, 2);   

    solutions = 0;
    if(gettimeofday(&start, NULL)){
        printf("Time failed\n");
        exit(1);
    }
    t1 = start.tv_sec+(start.tv_usec/1000000.0);
    for(i = 0; i < n; i++){
        infopointer.n = n;
        infopointer.out_flag = 0; // 1 == TRUE    
        infopointer.first = i;
        queens_thread(&infopointer); 
        solutions += infopointer.result;
    }
    if(gettimeofday(&end, NULL)){
        printf("Time failed\n");
        exit(1);
    }
    t2 = end.tv_sec+(end.tv_usec/1000000.0);
    printf("Total solutions: %d\n", solutions);
    printf("Elapsed time: %f\n", t2-t1);
    return 0;
}
