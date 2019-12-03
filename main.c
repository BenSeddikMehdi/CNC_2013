#include <stdio.h>
#include "First_Problem.h"
#include "Second_Problem.h"

int main() {
    pathList_t* temp_A_to_B = NULL, *temp_B_to_A = NULL;
    temp_A_to_B = AtoB();
    printf("The address of the first Element (A-->B): %p %x\n", temp_A_to_B,  &temp_A_to_B);
    temp_B_to_A = BtoA();
    printf("The address of the first Element (B-->A): %p %x", temp_B_to_A,  &temp_A_to_B);
    free(temp_A_to_B);
    free(temp_B_to_A);
    return 0;
}