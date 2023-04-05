#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};


void sort_by_area(triangle* tr, int n) {
    double p[n];
    int i, j;
    double tmpP;
    triangle tmp;
    for(i=0;i<n;i++){
        tmpP = (tr[i].a + tr[i].b + tr[i].c)/2.0;
        p[i] = tmpP * (tmpP - tr[i].a) * (tmpP - tr[i].b) * (tmpP - tr[i].c);
        p[i] = sqrt(p[i]);
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j] > p[j+1]){
                tmpP = p[j];
                p[j] = p[j+1];
                p[j+1] = tmpP;
                tmp = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = tmp;
            }
        }
    }
  
}


