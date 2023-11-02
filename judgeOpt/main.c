#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int a1 = 1, a2 = 2, a3 = 3;
int a = 4, b = 5;

/*
* count time
*/
struct timespec start_time, end_time;
unsigned long long elapsed_time;

void judgeOpt_before();
void judgeOpt_after();
void initValue();
void start();

int main(){
    start();
    return 0;
}

void judgeOpt_before(){

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    if ( (a1 != 0) && (a2 != 0) && ( a3 != 0) ){
        a = a + b;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void judgeOpt_after(){
    int ifZero = ( a1 && a2 && a3 );

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    if( ifZero ){
        a = a + b;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void start(){
    judgeOpt_before();
    judgeOpt_after();
}

