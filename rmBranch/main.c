#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ranNum();
void rmBranch_before();
void rmBranch_after();
void start();

/*
* count time
*/
struct timespec start_time, end_time;
unsigned long long elapsed_time;

char msg[] = { 'D','D','D','D','D','D','D','C','B','A' };

int main(){
    start();
    return 0;
}

int ranNum(){
    /**
     * creat random num 1-100 srand: prevent same num
    */
    srand(time(NULL));
    int num = rand() % 100 + 1;
    printf("%d\n",num);

    return num;
}

void rmBranch_before(){
    /**
     * func() -> score
    */
    int score = ranNum();

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    if( score >= 90 ){
        //printf("A")
    }
    else if( score >= 80 ){
        //printf("B")
    }
    else if( score >= 70 ){
        //printf("C")
    }
    else{
        //printf("D")
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void rmBranch_after(){
    /**
     * func() -> score
    */
    int score = ranNum();

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    msg[score/10];
    //printf("%c",msg[score/10])
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}

void start(){
    rmBranch_before();
    rmBranch_after();
}