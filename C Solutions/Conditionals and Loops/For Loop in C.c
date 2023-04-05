#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    int i;
    scanf("%d\n%d", &a, &b);
  	
    char labels[11][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd"};
    
    for(i=a; i <= b; i++){
        if(i<10){
            printf("%s\n",labels[i-1]);
        }
        else if(i % 2 == 0)
            printf("%s\n",labels[9]);
        else {
            printf("%s\n",labels[10]);
        }
    }
    
    return 0;
}

