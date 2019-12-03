//
// Created by HP-EliteBook on 11/18/2019.
//

#ifndef CNC_2013_SECOND_PROBLEM_H
#define CNC_2013_SECOND_PROBLEM_H

/**************************************************/
/* A : Itinerary Construction using tables/arrays */
/**************************************************/

#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define Nb 12
#define Max 10
typedef struct point{
    int8_t x;
    int8_t y;
} point_t;

point_t C[Max];

/* Question A-1 */
/****************/
void initializeC() {
    for (int8_t i = 0; i < Max; ++i) {
        C[i].x = C[i].y = -1;
    }
}

/* Question A-2 */
/****************/
void horizontalPath(point_t A, point_t B) {// A(2,5) B(3,4) => C[0] = P(2,5), C[1] = P(3,5), C[2] = P(3,4)
    int8_t n = (A.x - B.x), m = 0;
    int32_t i = 0;
    C[0] = A;
    if (n < 0) {
        for (i = 1; i <= -n; ++i) {
            C[i].x = C[i-1].x + 1;
            C[i].y = C[i-1].y;
        }
    } else {
        for (i = 1; i <= n; ++i) {
            C[i].x = C[i-1].x - 1;
            C[i].y = C[i-1].y;
        }
    }
    n = (A.x - B.x), m = (A.y - B.y);
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    C[n+m] = B;
    m = (A.y - B.y);
    if (m < 0) {
        m = -m;
        m += i;
        for (int8_t j = i; j < m-1; ++j) {
            C[j].x = C[j-1].x;
            C[j].y = C[j-1].y + 1;
        }
    } else {
        m += i;
        for (int8_t j = i; j < m-1; ++j) {
            C[j].x = C[j-1].x;
            C[j].y = C[j-1].y - 1;
        }
    }
    n = (int8_t) fabs(A.x - B.x), m = (int8_t) fabs(A.y - B.y);
    for (int8_t k = n+m+1; k < Max; ++k) {
        C[k].x = C[k].y = -1;
    }
}

/* Question A-3-a */
/****************/
point_t A = {2, 6}, B = {4, 3};
#define Nc 1
point_t tabC[Nc][Max];

void fillTabC(point_t c_tab[Nc][Max]) {
    point_t anotherArray[Nc][2];
}

int8_t distance(int8_t num) {
    for (int8_t j = 0; j < Nc; ++j) {
        horizontalPath(A,B);
        for (int8_t i = 0; i < Max; ++i) {
            tabC[j][i] = C[i];
        }
    }
    for (int8_t i = 0; i < Max; ++i) {
        if (tabC[num-1][i].x == -1)
            return i-1;
    }
}

/* Question A-3-b */
/****************/
int8_t minimumDistance() {
    int8_t min = 1;
    for (int8_t i = 0; i < Nc; ++i) {
        if (distance(i) < min) min = distance(i);
    }
    return min;
}

/***********************************************/
/* B : Itinerary Construction using LinkedList */
/***********************************************/

typedef struct pathType {
    point_t p;
    struct pathType *next;
} pathList;

/* Question B-1 */
/****************/
pathList *AtoB() {
    horizontalPath(A,B);
    return NULL;
}
#endif //CNC_2013_SECOND_PROBLEM_H
