#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions
#include "lst_elm.h"
/***
  * DÉFINITIONS DES FONCTIONS
  ***/
/** @todo Définissez les fonctions publiques :
 * + new_lst_elm
 * + del_lst_elm
 * + getX
 * + getSuc
 * + setX
 * + setSuc
 * des éléments de liste d'entiers.
 **/

struct lst_elm_t * new_lst_elm(void * datum){
	struct lst_elm_t * Liste = (struct lst_elm_t*)calloc(1,sizeof(struct lst_elm_t));
	Liste->datum = datum;
	Liste->suc = NULL;
	return Liste;
}

void del_lst_elm_t(struct lst_elm_t ** ptrE){
	assert(ptrE && *ptrE);
	free(*ptrE);
	(*ptrE) = NULL;
}

int * getDatum ( struct lst_elm_t * E ){
	return E->datum;
}

struct lst_elm_t * getSuc ( struct lst_elm_t * E ){
	return E->suc;
}

struct lst_elm_t * getPred ( struct lst_elm_t * E ){
	return E->pred;
}

void setDatum (struct lst_elm_t * E, void * datum ){
	E->datum = datum;
}

void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S ){
	E->suc = S;
}

void setPred ( struct lst_elm_t * E, struct lst_elm_t * S ){
	E->pred = S;
}
