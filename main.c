#include <stdio.h>
#include "First_Problem.h"
#include "Second_Problem.h"

int main() {
    horizontalPath(A,B);
    for (int i = 0; i < Max; ++i) {
        printf("C[%d] = P(%d,%d)\n", i, C[i].x, C[i].y);
    }
    printf("num = %d\n", distance(1));
    return 0;
}