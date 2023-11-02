#include<stdio.h>

void arm_f(){
    printf("ON_ARM \n");
}

void x86_f(){
    printf("ON_X86 \n");
}

int main(){
    int mode = 1;
    printf("条件分支代码");

    switch (mode)
    {
    case 1:
        arm_f();
        break;
    
    case 2:
        x86_f();
        break;
    }
    return 0;
}