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

/**
 * 一些平台支持选择指令，选择指令是一个三目运算指令，在某些情况下可以将分支指令用选择指令进行替换，达到提升效率的目的
 * 下面代码6-85为例进行说明
*/

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

/**
 * 可以使用三目运算符将分支判断指令改写，使用一条选择指令来移除分支判断，实现对分支语句的优化，如代码6-86所示
*/

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
