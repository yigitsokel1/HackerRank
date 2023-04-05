#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int marks_summation(int* marks, int number_of_students, char gender) {
    int i;
    int sum=0;
    if(gender == 'b'){
        for(i=0;i<number_of_students;i=i+2)
            sum += marks[i];
    }
    else{
        for(i=1;i<number_of_students;i=i+2)
            sum += marks[i];
    }
    return sum;
}


