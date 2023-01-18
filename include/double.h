#include "lst.h"

#ifndef _DOUBLE_
#define _DOUBLE_
/**
2 Form of manufactured products modeled with:
3 −A product name (char *)
4 −A stock (int)
5 −A price before tax (double)
6 */
#define len_max 20

enum mode_t { TEXT, BINARY};

struct form {
    char product[len_max ];
    int stock;
    double pbt;
};

/** Delete a form */
void del_form(struct form * F);

/** Read a form from FILE */
struct form * read_form(FILE * fd, enum mode_t mode);

/** Write a form to FILE */
void write_form(struct form * F, enum mode_t mode , FILE * fd);

/** Get the product name of the form F */
char * get_product(struct form * F);

/** Get the stock of the form F */
int get_stock(struct form * F);

/** Get the price before tax of the form F */
double get_price(struct form * F);

/** Display a form on stdout stream */
void view_form(struct form * F);

/** Is F1's product name less than or equal to F2's product name ? */
bool gt_form(struct form * F1, struct form * F2);

/** write a list into a text or binary file acording to the mode */
void write_list(struct lst_t * L,enum mode_t,void (*ptrf)());

/** read a list from a text or binary file acording to the mode */
struct lst_t * read_list(enum mode_t mode, void * (*ptrf)(), void (ptr_del)());

#endif
