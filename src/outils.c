#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "outils.h"

void printInteger ( int * i ) {
    printf( "La valeur est enti¨¨re et vaut : %d\n", (*i) );
}

void rmInteger ( int * i ) {
    free( i );
}

bool intcmp ( int * i, int * j ) {
    return (*i) < (*j);
}

void printDouble ( double * d ) {
    printf( "La valeur est r¨¦elle et vaut : %lf\n", (*d) );
}

void rmDouble ( double * d ) {
    free( d );
}

bool reelcmp ( double * u, double * v ) {
    return (*u) < (*v);
}

void freeInteger(int * i){
    assert(i);
    free(i);
}

/** Is *a greater than *b */
bool gt_int(int *a,int *b){
    return (*a) >= (*b);
}

bool gt_double(double *x,double *y){
    return (*x) >= (*y);
}

bool gt_string(char *s1,char *s2){
    int i = strcmp(s1,s2);
    if(i>=0){
        return true;
    }else{
        return false;
    }
}

/** Is *a less than *b */
bool lt_int(int *a, int *n){
    return (*a) < (*n);
}

bool lt_double(double *x,double *y){
    return (*x) < (*y);
}

bool lt_string(char *s1, char *s2){
    int i = strcmp(s1,s2);
    if(i<0){
        return true;
    }else{
        return false;
    }
}
