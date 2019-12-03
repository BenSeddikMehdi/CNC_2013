#include <stdio.h>
#include "First_Problem.h"
#include "Second_Problem.h"

int main() {
    pathList_t* temp_A_to_B = NULL, *temp_B_to_A = NULL;
    temp_A_to_B = AtoB();
    printPath(temp_A_to_B);
    temp_B_to_A = BtoA();
    printPath(temp_B_to_A);
    free(temp_A_to_B);
    free(temp_B_to_A);
    return 0;
}