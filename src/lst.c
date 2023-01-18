#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions
#include "lst.h"
#include "outils.h"

struct lst_t * new_lst() {
	/**
	 * @note : calloc fonctionne de manière identique à malloc
	 * et de surcroît met à NULL(0) tous les octets alloués
	 **/
	struct lst_t * L = (struct lst_t *)calloc(1,sizeof(struct lst_t));
	assert(L);
	return L;
}

void del_lst(struct lst_t ** ptrL,void (*ptrFct) ()) {

	assert(ptrL && *ptrL);
	for(struct lst_elm_t *E = (*ptrL)->head;E; ){
		struct lst_elm_t * T = E;
		E = E->suc;
		//del_lst_elm_t(&T);
		//freeInteger(T->datum);
		(*ptrFct)(T->datum);
	}
	free(*ptrL);
	*ptrL =NULL;
}

bool empty_lst(const struct lst_t * L ) {
	assert(L);// L doit exister !
	return L->numelm == 0;
}
void cons(struct lst_t * L, void * datum) {
	struct lst_elm_t *E = new_lst_elm(datum);
	E->suc = L->head;
	L->head = E;
	if(L->numelm==0) L->tail = E;
	L->numelm++;
}

void queue(struct lst_t * L, void * datum){
	struct lst_elm_t *E = new_lst_elm(datum);
	L->tail->suc = E;
	L->tail = E;
	if(L->numelm==0) L->head = E;
	L->numelm++;
}

void insert_after(struct lst_t * L, void * datum, struct lst_elm_t * place){
	if(empty_lst(L)){
		cons(L,datum);
	}else{
		struct lst_elm_t *E = new_lst_elm(datum);
		E->suc = place->suc;
		place->suc = E;
	}
}

void insert_ordered(struct lst_t * L, void * datum, bool (*ptrFct) ()){
	if(empty_lst(L) || ((*ptrFct)(datum,getDatum(L->head)))){
		printf("insertion au début\n");
		cons(L,datum);
	}else if(((*ptrFct)(getDatum(L->tail),datum))){
		printf("insertion à la fin\n");
		queue(L,datum);
	}else{
		printf("Insertion entre\n");
		struct lst_elm_t *E = L->head;

		//while(intcmp(getDatum(E->suc),datum)){
		while(((*ptrFct)(getDatum(E->suc),datum))){
			E = E->suc;
		}
		insert_after(L, datum,E);
	}
	// ((*ptrf)(E->datum,datum))
	// ((*ptrf)(getDatum(E->suc),datum))
}

/*void print_lst(struct lst_t * L ) {
	printf( "[ " );
	for( struct lst_elm_t * E = L->head; E; E = E->suc) {
		printf( "%d ", E->x );
	}
	printf( "]\n\n" );
}*/

/** @brief Consulter la tête de la liste */
struct lst_elm_t * getHead(struct lst_t * L){
	return L->head;
}

/** @brief Consulter la queue de la liste */
struct lst_elm_t * getTail(struct lst_t * L){
	return L->tail;
}

/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm(struct lst_t * L){
	return L->numelm;
}

/** @brief Modifier le nombre d'éléments rangés dans la liste */
void setNumelm(struct lst_t * L, int numElm){
	L->numelm = numElm;
}

/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_lst(struct lst_t * L, void (* ptrFct) () ){
	for(struct lst_elm_t * E = L->head; E; E=E->suc){
		(*ptrFct)(E->datum);
	}
}
