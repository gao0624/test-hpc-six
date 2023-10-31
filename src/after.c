#include<stdio.h>
#define ON_ARM 1

/**
 * 条件编译是预编译指示命令，可以使编译器按不同的条件编译不同的程序部分，用于控制是否编译某段代码
 * #if如果为真则编译后续代码
 * #ifdef如果宏已经定义，则编译后续代码
 * #ifndef如果没有宏定义则编译后续代码
 * #elif如果前面的 #if给定条件没有满足，当前条件满足，则编译这部分代码
 * #endif 结束一个#if   #else 条件编译
 * 
 * 由于宏条件在编译时已经确定，编译器就可以直接忽略不成立的分支，所以条件编译时在编译时进行判断的，而普通分支判断是在运行时判断的
 * 故编译后的代码比较长，效率也不如条件编译。条件编译需要多个程序来支持多个条件编译分支版本，而运行时分支版本却只有一个。
 * 
 * 下面代码6-88
*/

#ifdef ON_ARM
void arm_f(){
    printf("ON_ARM\n");
}
#endif

#ifdef ON_X86
void x86_f(){
    printf("ON_X86 \n");
}
#endif

int main(){
    printf("条件编译代码：");
    #ifdef ON_ARM
        arm_f();
    #elif ON_X86
        x86_f();
    #endif

    return 0;
}