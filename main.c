#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int cong(int number, ...){
    int sum = 0;
    //định nghĩa 1 con trỏ,trỏ tới argument list
    va_list ptr;
    va_start(ptr, number);
    for(int i = 0; i < number; i++){
        sum = sum + va_arg(ptr, int);
    }
    va_end(ptr);
    return sum;
}
int maxx(int n, ...){
    int max = 0;
    va_list ptr;
    va_start(ptr, n);
    for(int i = 0; i < n; i++){
        int m = va_arg(ptr, int);
        if(max < m){
            max = m;
        }
    }
    va_end(ptr);
    return max;
}

float gttb(int n, ...){
    float sum;
    float gttb;
    va_list ptr;
    va_start(ptr,n);
    for(int i = 0; i < n; i++){
        sum = sum + va_arg(ptr,int);
    }
    gttb = sum/n;
    va_end(ptr);
    return gttb;
}
void in(int n, ...){
    va_list ptr;
    va_start(ptr,n);
    
    
}

int main(void){
    int res = cong(3,1,2,3);
    printf("%d", res);
    return 0;
}