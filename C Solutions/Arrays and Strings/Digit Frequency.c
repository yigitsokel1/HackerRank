#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i;
    char *text;
    text = malloc(1024 * sizeof(char));
    scanf("%s",text);
    int numbers[10];
    for(i = 0; i<10; i++){
        numbers[i] = 0;
    }
    i=0;
    while(text[i] != '\0'){
        if(text[i] < 58 && text[i] > 47 ){
            numbers[text[i]- 48]++;
        }
        i++;
    }
    
    for(i=0;i<10;i++){
        printf("%d ",numbers[i]);
    }
    

        
    return 0;
}

