#ifndef _OUTILS_
#define _OUTILS_

#include <stdbool.h>


void printInteger ( int * i );
void rmInteger ( int * i );
bool intcmp ( int * i, int * j );


void printDouble ( double * d );
void rmDouble ( double * d );
bool reelcmp ( double * u, double * v );

void freeInteger(int *i);

/** Is *a greater than *b */
bool gt_int(int *a,int *b);

bool gt_double(double *x,double *y);

bool gt_string(char *s1,char *s2);

/** Is *a less than *b */
bool lt_int(int *a, int *n);

bool lt_double(double *x,double *y);

bool lt_string(char *s1, char *s2);

#endif 

