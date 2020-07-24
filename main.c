#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Conjunto/conjunto.h"
#include "./Intervalo/intervalo.h"

int main(){
    Conjunto conj = conjunto_inicializar();
    Intervalo *inter1 = intervalo_crear(1,10);
    Intervalo *inter2 = intervalo_crear(6,8);    
    Intervalo *inter3 = intervalo_crear(12,14);
    Intervalo *inter4 = intervalo_crear(16,17);
    Intervalo *inter5 = intervalo_crear(9,12);
    Intervalo *inter6 = intervalo_crear(2,3);    
    Intervalo *inter7 = intervalo_crear(3,4);
    Intervalo *inter8 = intervalo_crear(4,5);

    printf("Conjunto 1: \n");
    conjunto_agregar_intervalo(conj, inter4);
    conjunto_imprimir(conj);
    conjunto_agregar_intervalo(conj, inter3);
    conjunto_imprimir(conj);
    conjunto_agregar_intervalo(conj, inter2);
    conjunto_imprimir(conj);
    conjunto_agregar_intervalo(conj, inter1);
    conjunto_imprimir(conj);
    printf("Ordeno: \n");
    conj = conjunto_mergeSort(conj, &intervalo_comparar);
    conjunto_imprimir(conj);
    printf("Colapso: \n");
    conjunto_colapsar(conj);
    conjunto_imprimir(conj);


    Conjunto conj2 = conjunto_inicializar();
    printf("\nConjunto 2: \n");
    conjunto_agregar_intervalo(conj2, inter8);
    conjunto_imprimir(conj2);
    conjunto_agregar_intervalo(conj2, inter7);
    conjunto_imprimir(conj2);
    conjunto_agregar_intervalo(conj2, inter6);
    conjunto_imprimir(conj2);
    conjunto_agregar_intervalo(conj2, inter5);
    conjunto_imprimir(conj2);
    printf("Ordeno: \n");
    conj2 = conjunto_mergeSort(conj2, &intervalo_comparar);
    conjunto_imprimir(conj2);
    printf("Colapso: \n");
    conjunto_colapsar(conj2);
    conjunto_imprimir(conj2);

    printf("Union: ");
    Conjunto conjUnion = conjunto_union(conj, conj2);
    conjunto_imprimir(conjUnion);

    printf("Interseccion: ");
    Conjunto conjInter = conjunto_interseccion(conj, conj2);
    conjunto_imprimir(conjInter);

    printf("Fin\n");
}