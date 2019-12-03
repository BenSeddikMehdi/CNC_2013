#include <stdio.h>
#include "First_Problem.h"
#include "Second_Problem.h"

int main() {
    pathList_t* temp = NULL;
    temp = AtoB();
    printf("the address of the first element = %x", (unsigned) temp);
    
    return 0;
}