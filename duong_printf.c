#include <stdarg.h>
#include <unistd.h>


static void print_string(const char *s){
    while(*s){
        write(1, s, 1);
        s++;
    }
}


static void print_int(int n){
    char buf[12];
    int i = 0;
    unsigned int u;
    if(n < 0){
        write(1, "-", 1);
        u = (unsigned int)(-n);
    } 
    else{
        u = (unsigned int)n;
    }
    do{ //chuyen so sang chuoi nguoc
        buf[i++] = '0' + (u % 10);
        u /= 10;
    }
    while(u);
    while(i--){ //xuat theo thu tu
        write(1, &buf[i], 1);
    }
}

int printd(const char *format, ...){
    va_list args;
    va_start(args, format);
    const char *p = format;
    while(*p){
        if (*p == '%'){
            p++;
            switch(*p){
                case 'd':
                    int d = va_arg(args, int);
                    print_int(d);
                    break;
                case 's':
                    char *s = va_arg(args, char*);
                    print_string(s);
                    break;
                case 'c':
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    break;
                case '%':
                    write(1, "%", 1);
                    break;
                default:
                    write(1, p, 1);
            }
            p++;
        }
        else{
            write(1, p, 1);
            p++;
        }
    }

    va_end(args);
    return 0;
}
