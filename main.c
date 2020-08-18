#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Conjunto/conjunto.h"
#include "./Intervalo/intervalo.h"
#include "./Tree/tree.h"
#include "./Hash/hash.h"

#define BUFFER 1000

void imprimir_readme(){
    printf("Formatos validos de comandos:\n");
    printf("    - Imprimir un conjunto:\n        imprimir alias\n");
    printf("    - Agregar conjuntos por extension:\n        alias = [...]\n");
    printf("    - Agregar conjuntos por comprension:\n        alias = [x/a<=x<=b]\n");
    printf("    - Union de intervalos:\n        aliasUnion = aliasA | aliasB\n");
    printf("    - Interseccion de intervalos:\n        aliasInter = aliasA & aliasB\n");
    printf("    - Resta de intervalos:\n        aliasResta = aliasA - aliasB\n");
    printf("    - Complemento de un intervalo:\n        aliasComp = ~aliasA\n");
    printf("    - Salir del interprete:\n        salir\n");
}

int main(){
    int input = 0;
    //char comando[BUFFER];
    while(input != -1){
        imprimir_readme();
        input = -1;
    }


    //empiezan ejemplos
    Conjunto conj = conjunto_inicializar();
    Intervalo *inter1 = intervalo_crear(1,10);
    Intervalo *inter2 = intervalo_crear(12,20);    
    Intervalo *inter3 = intervalo_crear(23,30);
    Intervalo *inter4 = intervalo_crear(34,40);
    Intervalo *inter5 = intervalo_crear(10,12);
    Intervalo *inter6 = intervalo_crear(2,3);    
    Intervalo *inter7 = intervalo_crear(4,4);
    Intervalo *inter8 = intervalo_crear(4,7);

    printf("Conjunto 1: \n");
    conjunto_agregar_intervalo(conj, inter4);
    conjunto_agregar_intervalo(conj, inter3);
    conjunto_agregar_intervalo(conj, inter2);
    conjunto_agregar_intervalo(conj, inter1);
    conj = conjunto_mergeSort(conj, &intervalo_comparar);
    conjunto_colapsar(conj);
    conjunto_imprimir(conj);

    Conjunto conj2 = conjunto_inicializar();
    printf("\nConjunto 2: \n");
    conjunto_agregar_intervalo(conj2, inter8);
    conjunto_agregar_intervalo(conj2, inter7);
    conjunto_agregar_intervalo(conj2, inter6);
    conjunto_agregar_intervalo(conj2, inter5);
    conj2 = conjunto_mergeSort(conj2, &intervalo_comparar);
    conjunto_colapsar(conj2);
    conjunto_imprimir(conj2);
    printf("\n");

    printf("Union: ");
    Conjunto conjUnion = conjunto_union(conj, conj2);
    conjunto_imprimir(conjUnion);

    printf("Interseccion: ");
    Conjunto conjInter = conjunto_interseccion(conj, conj2);
    conjunto_imprimir(conjInter);

    printf("Resta: ");
    Conjunto conjResta = conjunto_resta(conj, conj2);
    conjunto_imprimir(conjResta);

    printf("Complemento: ");
    Conjunto conjComp = conjunto_complemento(conj2);
    conjunto_imprimir(conjComp);
    printf("\n");

    Tree *hash = hash_crear();
    hash = hash_insertar(hash, conjComp, "Complemento");
    hash = hash_insertar(hash, conjUnion, "Union");
    hash = hash_insertar(hash, conj2, "4");
    hash = hash_insertar(hash, conj, "1");
    hash = hash_insertar(hash, conjInter, "Inter");
    hash = hash_insertar(hash, conjResta, "Resta");
    hash_imprimir(hash);

    printf("\nFin\n");
}