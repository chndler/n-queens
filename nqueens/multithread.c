#include "nqueens_library.h"

int main(int argc, char *argv[]){
    int i, j, rc, solutions, n, out_flag;
    pthread_attr_t attr;
    void *status;
    solutions = 0;
    struct timeval start, end;
    double t1, t2;

    printf("Multi threaded\n"); 
    if(argc != 2){
        printf("Usage: %s n\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    
    /* Initialize and set thread and thread_info_t
     * arrays to size of n*/
    thread_info_t infopointer[n];
    pthread_t tid[n];
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    /* Get start time */
    if(gettimeofday(&start, NULL)){
        printf("Time failed\n");
        exit(1);
    }
    t1 = start.tv_sec+(start.tv_usec/1000000.0);

    /* Initialize threads and variables */
    for(i = 0; i < n; i++){   
        infopointer[i].n = n;
        infopointer[i].out_flag = 0; // 1 == TRUE    
        infopointer[i].first = i;
        rc = pthread_create(&tid[i], &attr, queens_thread, &infopointer[i]);
        if (rc) {
            printf("Error, return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    /* Wait for threads to finish using pthread_join */
    pthread_attr_destroy(&attr);
    for(j = 0; j < n; j++){
        rc = pthread_join(tid[j], &status);
        if (rc) {
            printf("Error, return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        solutions += infopointer[j].result;
    }
    /* Get end time */
    if(gettimeofday(&end, NULL)){
        printf("Time failed\n");
        exit(1);
    }
    t2 = end.tv_sec+(end.tv_usec/1000000.0);

    printf("Total solutions: %d\n", solutions);
    printf("Elapsed time: %f\n", t2-t1);
    return 0;
}
