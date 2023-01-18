#include <stdlib.h>
#include <stdio.h>

struct elmlstent {
  int x;
  struct elmlstent * suc;
};

int main(int argc, char ** argv) {
  struct elmlstent E = {43, NULL};
  struct elmlstent * refE = (struct elmlstent *)calloc(1, sizeof(struct elmlstent));

  printf("(*) %d octets pour un char... ", sizeof(char));
  printf("Et %d octets pour un entier court !!!\n", sizeof(short));
  printf("(*) %d octets pour un entier\n", sizeof(int));
  printf("(*) %d octets pour un réel\n", sizeof(double));
  printf("(*) %d octets pour une référence\n", sizeof(void *));
  printf("(*) %d octets pour un élément de liste d'entiers déclaré en statique\n", sizeof(E));
  printf("\nSoit une référence (i.e. un pointeur) d'élément de liste d'entiers.\nIl y a :\n");
  printf("\t(*) %d octets pour la référence à l'élément et\n", sizeof(refE));
  printf("\t(*) %d octets pour l'élément proprement dit\n", sizeof(*refE));
  return 0;
}
