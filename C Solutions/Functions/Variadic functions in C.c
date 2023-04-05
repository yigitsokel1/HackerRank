#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000


int  sum (int count,...) {
    int i;
    int sum =0;
    va_list values;
    va_start(values, count);
    for(i=0;i<count;i++){
        int n = va_arg(values, int);
        sum += n;
    }
    va_end(values);
    return sum;
}

int min(int count,...) {
    int min = MAX_ELEMENT;
    va_list values;
    va_start(values, count);
    for(int i=0; i<count;i++){
        int n = va_arg(values, int);
        if(n < min)
            min = n;
    }
    va_end(values);
    return min;
    
    
    
}

int max(int count,...) {
    int max = MIN_ELEMENT;
    va_list values;
    va_start(values, count);
    for(int i=0; i<count;i++){
        int n = va_arg(values, int);
        if(n > max)
            max = n;
    }
    va_end(values);
    return max;
    
}




