#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i, n;
    int *s;
    int sum = 0;
    scanf("%d",&n);
    s = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++){
        scanf("%d", &s[i]);
    }
    for(i=0;i<n;i++){
        sum = sum + *(s+i);
    }
    printf("%d",sum);
        
    return 0;
}

