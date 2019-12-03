//
// Created by HP-EliteBook on 11/18/2019.
//

#ifndef CNC_2013_SECOND_PROBLEM_H
#define CNC_2013_SECOND_PROBLEM_H

#include <math.h>
#include <stdlib.h>
#include <stdint.h>

/**************************************************/
/* A : Itinerary Construction using tables/arrays */
/**************************************************/

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
    n = (int8_t) abs(A.x - B.x), m = (int8_t) abs(A.y - B.y);
    for (int8_t k = n+m+1; k < Max; ++k) {
        C[k].x = C[k].y = -1;
    }
}

/* Question A-3-a */
/****************/
#define Nc 4
/*point_t tabC[Nc][Max] =
{2,6, 2,5, 2,4, 2,3, 3,3, 3,4, 4,4, 4,3, -1,-1, -1,-1,
 2,6, 3,6, 4,6, 4,5, 4,6, 5,6, 5,5, 5,4, 5,3, 4,3,
 2,6, 2,5, 3,5, 4,5, 4,4, 4,3, -1,-1, -1,-1, -1,-1, -1,-1,
 2,6, 2,5, 3,5, 4,5, 5,5, 5,4, 4, 4,  4,3, -1,-1, -1,-1};*/

/*int8_t distance(int8_t num) {
    for (int8_t i = 0; i < Max; ++i) {
        if (tabC[num-1][i].x == -1)
            return i-1;
    }
    return Max-1;
}*/

/* Question A-3-b */
/****************/
/*int8_t minimumDistance() {
    int8_t min = distance(0);
    for (int8_t i = 1; i < Nc; ++i) {
        if (distance(i) < min) min = distance(i);
    }
    return min;
}*/

/**************************************************/
/* B : Itineraries Construction using Linked List */
/**************************************************/

typedef struct pathType {
    point_t p;
    struct pathType *next;
} pathList_t;

/* Question B-1 */
/****************/
pathList_t* newNode(int8_t i) {
    pathList_t* temp = malloc(sizeof(pathList_t));
    temp->p.x = C[i].x;
    temp->p.y = C[i].y;
    temp->next = NULL;
    return temp;
}
void push(pathList_t** pList, int8_t i) {
    if ((*pList) == NULL) {
        pathList_t* temp = newNode(i);

        temp->next = (*pList);

        (*pList) = temp;
    } else
        push(&(*pList)->next, i);
}

point_t A = {2, 6}, B = {4, 3};

pathList_t* AtoB() {
    horizontalPath(A,B);
    pathList_t* firstElement = NULL;
    for (int8_t i = 0; i < Max; ++i) {
        push(&firstElement, i);
    }
    return firstElement;
}

#endif //CNC_2013_SECOND_PROBLEM_H
