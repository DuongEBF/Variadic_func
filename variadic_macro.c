#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define LOG(...)   printf(__VA_ARGS__)
#define LOG1(Format, ...)   printf("%s (%d) " Format, __FILE__, __LINE__, ##__VA_ARGS__)

void simple_printf(const char* fmt, ...){
    va_list args;
    va_start(args,fmt);
    while(*fmt != '\0'){
        if(*fmt == 'd'){
            int i = va_arg(args, int);
            printf("%d\n", i);
        }
        else if(*fmt == 'c'){
            int c = va_arg(args,int); //sizeof('A') = 4byte nen ta phai luu vao int
            printf("%c\n",c);
        }
        else if(*fmt == 'f'){
            double d = va_arg(args, double); //quy dinh cua C khi sizeof(1.999) thi no se ra 8 byte nen ta can su dung kieu double de luu
            printf("%f\n", d);
        }
        ++fmt;
    }
    va_end(args);
}
int main(void){
    printf("Hello word\n");
    LOG("Hello word\n");
    simple_printf("dcff",3,'a', 1.999, 42.5);
    LOG1("Ten Toi La %s", "Duong");
    return 0;
}