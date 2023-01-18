#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#include<assert.h> 
#include "lst_elm.h"
#include "lst.h"
#include "outils.h"
#include "double.h"


void listehomoreelle ();
void listehomoentiere ();

int main() {
	
	struct form * (* ptr_read)(FILE *, enum mode_t) = &read_form;
 	// form view function pointer
	void (* ptr_view)(struct form *) = &view_form;
	// form write into file function pointer
	void (* ptr_write)(struct form *, enum mode_t , FILE *) = &write_form;
	// form deletion function pointer
	void (* ptr_del)(struct form *) = &del_form;

	// create form list from text/binary file
	struct lst_t * L = read_list(TEXT , (void * (*)()) ptr_read , ptr_del);
	// view form list

	view_lst(L, ptr_view);

	// write form list into text/binary file
	write_list(L, BINARY , ptr_write);
	// delete form list
	del_lst(&L, ptr_del);


	// create form list from text/binary file
	L = read_list(BINARY , (void * (*)()) ptr_read , ptr_del);

	// view form list
	view_lst(L, ptr_view);

	// delete form list
	del_lst(&L, ptr_del);
	return EXIT_SUCCESS;
}

void listehomoreelle () {
	struct lst_t * L = new_lst ();
 	double * v;

	do {
		double u;

		printf ( "Entrez un reel (0 pour s'arreter): " );
		scanf ("%lf", &u );
		//printf("1\n");
	if ( u == 0 ) break;
	//printf("2\n");
 	v = (double *) calloc (1, sizeof(double));
	//printf("3\n");
 	*v = u;
	//printf("4\n");
 	insert_ordered (L, v, &reelcmp);
	//printf("5\n");
 	}while(true);
 	view_lst(L, &printDouble);
 	del_lst (&L, &rmDouble);
}

void listehomoentiere () {
	struct lst_t * L = new_lst ();
 	int * v;

 	do {
 	int u;

 	printf ( "Entrez un entier (0 pour s'arreter): " );
 	scanf ("%d", &u );
 	if ( u == 0 ) break;

 	v = (int *) calloc ( 1, sizeof(int) );
 	*v = u;
 	insert_ordered (L,v,&intcmp);
 	}while ( true );

 	view_lst(L, &printInteger);
 	del_lst (&L, &rmInteger);
}
