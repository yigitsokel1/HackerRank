#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int i=0, j;
    int n, tmp, temp, cont=0;
    scanf("%d", &n);

    int matrix[2*n-1][2*n-1];
    tmp = 2*n-1;
    temp = n;
    
    while(temp > 0){
        for(i=cont;i<tmp;i++){
            for(j=cont;j<tmp;j++){
                matrix[i][j] = temp;
            }
        }
        cont++;
        temp--;
        tmp--;
    }
     for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
      
    
    return 0;
    
}

