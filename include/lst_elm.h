#ifndef _LSTELMT_
#define _LSTELMT_
/** @brief Le type d'un élément de liste:
 * + datum - un type quelconque,
 * + suc - un pointeur sur son successeur (ou NULL s'il n'y en a pas)
 */
struct lst_elm_t {
  void * datum;
  struct lst_elm_t * suc, *pred;
};

/***
 * DÉCLARATION DES FONCTIONS PUBLIQUES
 ***/
/** @brief Création d'un nouvel élément de liste d'entiers */
struct lst_elm_t * new_lst_elm(void * datum);
/** @brief Suppression d'un élément de liste d'entiers */
void del_lst_elm_t(struct lst_elm_t ** ptrE);
/** @ brief Accéder au champ datum de l'élément de liste d'entiers */
int * getDatum ( struct lst_elm_t * E );
/** @ brief Accéder au champ suc de l'élément de liste d'entiers */
struct lst_elm_t * getSuc ( struct lst_elm_t * E );
/** @ brief Accéder au champ pred de l'élément de liste d'entiers */
struct lst_elm_t * getPred ( struct lst_elm_t * E );
/** @brief Modifier la valeur du champ x de l'élément de liste d'entiers */
void setDatum (struct lst_elm_t * E, void * datum );
/** @brief Modifier la valeur du champ suc de l'élément de liste d'entiers */
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );
/** @brief Modifier la valeur du champ pred de l'élément de liste d'entiers */
void setPred ( struct lst_elm_t * E, struct lst_elm_t * S );

#endif//_LSTELMT_
