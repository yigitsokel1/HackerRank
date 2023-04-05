#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char str1[100];
    char str2[100];
    scanf("%c",&ch);
    scanf("%s",str1);
    scanf(" %[^\n]s",str2);
    printf("%c\n", ch);
    printf("%s\n", str1);
    printf("%s", str2);
    
    return 0;
}
