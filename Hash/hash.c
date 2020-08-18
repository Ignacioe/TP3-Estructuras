#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

Tree *hash_crear() {
    Tree *tabla = malloc(sizeof(Tree) * MAXSIZE);
    int index = 0;
    while (index < MAXSIZE){
        tabla[index] = NULL;
        index++;
    }
    return tabla;
}

void hash_eliminar(Tree *tabla){
    int index = 0;
    while (index < MAXSIZE){
        free(tabla[index]->alias);
        tree_destruir(tabla[index]);
        index++;
    }
    free(tabla);
}