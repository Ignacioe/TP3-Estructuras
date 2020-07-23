#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Conjunto/conjunto.h"
#include "./Intervalo/intervalo.h"

int main(){
    Conjunto conj = conjunto_inicializar();
    Conjunto conj2 = conjunto_inicializar();
    Intervalo *int1 = intervalo_crear(9,10);
    Intervalo *int2 = intervalo_crear(4,7);    
    Intervalo *int3 = intervalo_crear(1,3);
    Intervalo *int4 = intervalo_crear(6,7);
    conj = conjunto_agregar_intervalo(conj, int1);
    conj = conjunto_agregar_intervalo(conj, int2);
    conj2 = conjunto_agregar_intervalo(conj2, int3);
    conj2 = conjunto_agregar_intervalo(conj2, int4);

    conj = conjunto_mergeSort(conj, &intervalo_comparar);
    conj = conjunto_colapsar(conj);
    conjunto_imprimir(conj);

    conj2 = conjunto_mergeSort(conj2, &intervalo_comparar);
    conj2 = conjunto_colapsar(conj2);
    conjunto_imprimir(conj2);

    Conjunto conjUnion = conjunto_union(conj, conj2);
    printf("Union: ");
    conjunto_imprimir(conjUnion);

    printf("Fin\n");
}