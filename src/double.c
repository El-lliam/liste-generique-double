#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // librairie du type booléen
#include<assert.h> // librairie d'assertions
#include<string.h>
#include "double.h"
#include "lst.h"


/** Delete a form */
void del_form(struct form * F){
    assert(F);
    free(F);
    F = NULL;
}

/** Read a form from FILE */
struct form * read_form(FILE * fd, enum mode_t mode){
    //fd is already open and mode is eq to TEXT or BINARY
    assert (fd != NULL);

    //create a form
    struct form * F = (struct form *) calloc(1,sizeof(struct form));
    assert(F != NULL);

    if(mode == TEXT){ //eitehr fd is a text file
        /*fscanf(fd, " %s", F->product);
        F->product[len_max-1]='\0';
        fscanf(fd, " %d", &(F->stock));
        fscanf(fd, " %lf", &(F->pbt));*/
        fscanf(fd,"%s\n%d\n%lf\n",F->product,&(F->stock),&(F->pbt));
    }else{
        fread(F, sizeof(struct form),1,fd);
    }
    return F;
}

/** Write a form to FILE */
void write_form(struct form * F, enum mode_t mode, FILE * fd){
    printf("Formulaire %s écrit\n", F->product);
    if(mode == TEXT){
        /*fprintf(fd,"Nom : %s",F->product);
        fprintf(fd,"Stock : %d",F->stock);
        fprintf(fd,"Prix : %lf",F->pbt);*/
        fprintf(fd,"%s\n%d\n%lf\n",F->product,F->stock,F->pbt);
    }else{
        fwrite(F,sizeof(struct form),1,fd);
    }
}

/** Get the product name of the form F */
char * get_product(struct form * F){
    return F->product;
}

/** Get the stock of the form F */
int get_stock(struct form * F){
    return F->stock;
}

/** Get the price before tax of the form F */
double get_price(struct form * F){
    return F->pbt;
}

/** Display a form on stdout stream */
void view_form(struct form * F){

    printf("Nom du produit : %s\n",F->product);
    printf("Nombre en stock : %d\n",F->stock);
    printf("Prix avant les taxes : %lf\n",F->pbt);
}

/** Is F1's product name less than or equal to F2's product name ? */
bool gt_form(struct form * F1, struct form * F2){
    int i = strcmp(F1->product,F2->product);
    if(i<=0){
        return true;
    }else{
        return false;
    }
}

void write_list(struct lst_t * L, enum mode_t mode , void (*ptrf)()) {
    FILE * fd;
    char fname [20];
    if (mode == TEXT) {
        printf("\t\tWrite list to text file (.txt)\n\tfile name :");
        scanf("%s", fname);
        fd = fopen(fname , "wt");
    } else {
        printf("\t\tWrite list to binary file (.bin)\n\tfile name :");
        scanf("%s", fname);
        fd = fopen(fname , "wb");
    }
    assert(fd != NULL);

/** TODO
Vous devez parcourir la liste et écrire les formulaires qui y sont rangés grâce au pointeur de fonctions
*/
    for(struct lst_elm_t *E = L->head;E; E=E->suc){
        (*ptrf)(E->datum,mode,fd);
        //E = E->suc;
    }

    fclose(fd);
}

struct lst_t * read_list(enum mode_t mode , void * (* ptr_data)(), void (ptr_del)()) {
/**
    on peut ajouter en argument un pointeur sur la fonction de comparaison des formulaires gt_form si l'on souhaite faire une insertion
        ordonnée (insert_ordered)
    */
    FILE * fd;
    char fname [20];

    if (mode == TEXT) {
        printf("\t\tRead list from text file (.txt)\n\tfile name :");
        scanf("%s", fname);
        fd = fopen(fname , "rt");
    }else {
        printf("\t\tRead list from binary file (.bin)\n\tfile name :");
        scanf("%s", fname);
        fd = fopen(fname , "rb");
    }
    assert(fd != NULL);

/** TODO
    Vous devez parcourir l'ensemble du fichier pour y collecter les formulaires et les ranger dans la liste.
    ATTENTION : il est possible que vous créiez un élément de trop (un formulaire vide) en fin de liste.
    Il faut alors penser à le supprimer grâce au code suivant :
        E = get_tail (L);
        struct elmlist * T = getPred(E);
        set_suc(T, NULL);
        L−>tail = T;
        del_elmlist(E, ptr_del);
    où ptr_del est le pointeur sur la fonction de suppression de la donnée (ici la donnée est un formulaire)
     }
*/
    struct lst_t *L = new_lst();

    while(!feof(fd)){
        struct form *F = read_form(fd,mode);
        cons(L,F);
    }

    if(mode == BINARY){
        struct lst_elm_t *E = L->head;
        L->head = L->head->suc;
        free(E);
        L->numelm--;
    }

    fclose(fd);
    return L;
}
