#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) {
  int maxAnd=0, maxOr=0, maxXor=0, tmp;
  int i, j;
  for(i=1;i<=k;i++){
      for(j=i+1;j<=n;j++){
        tmp = i & j;
        if(tmp<k && tmp > maxAnd)
            maxAnd = tmp;
        tmp = i | j;
        if(tmp<k && tmp > maxOr)
            maxOr = tmp;
        tmp = i^j;
        if(tmp<k && tmp > maxXor)
            maxXor = tmp;
      }
  }
  
  printf("%d\n%d\n%d",maxAnd,maxOr,maxXor);
  
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

