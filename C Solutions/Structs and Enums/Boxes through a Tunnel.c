#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b) {
	int mul;
    mul = b.height * b.length * b.width;
    return mul;
}

int is_lower_than_max_height(box b) {
	if(b.height < MAX_HEIGHT)
        return 1;
    return 0;
}


