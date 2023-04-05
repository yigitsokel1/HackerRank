#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int character_count(const char* a){
    int characters[128] = {0};
    int count = 0;
    int i= 0;
    while(a[i] != '\0'){
        if(characters[a[i]] == 0){
            characters[a[i]]++;
            count++;
        }
        i++;   
    }
    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
    if(character_count(a) > character_count(b))
        return 1;
    else if(character_count(a) == character_count(b))
        return lexicographic_sort(a, b);
    return 0;
    
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) > strlen(b)){
       return 1;
    }
    else if(strlen(a) == strlen(b))
        return lexicographic_sort(a, b);
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
 
    int con = 0;
    while(!con)
    {
        con = 1;
        for(int i = 0; i < len - 1; i++)
        {
            if(cmp_func(arr[i], arr[i + 1]) > 0) 
            {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;
            }
        }
    }
    
  

}


