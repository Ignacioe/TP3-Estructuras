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
    char comando[BUFFER];
    while(input != -1){
        imprimir_readme();

    }
}