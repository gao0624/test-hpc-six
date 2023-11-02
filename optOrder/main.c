#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void optOrder_before();
void optOrder_after();
void start();

int a = 4, b = 5;
int x;

/*
* count time
*/
struct timespec start_time, end_time;
unsigned long long elapsed_time;


int main(){
    start();
    return 0;
}


void optOrder_before(){

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    if(a > 0){
        x = a;
    }else{
        x = b;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void optOrder_after(){
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    x = (a > 0 ? a : b);

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void start(){
    optOrder_before();
    optOrder_after();
}
