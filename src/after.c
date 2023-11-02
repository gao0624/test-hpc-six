#include<stdio.h>
#define ON_ARM 1

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