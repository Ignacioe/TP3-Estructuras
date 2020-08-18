#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 991

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

int hash_key(char* alias){
    long long int key = 1, index = 0;
    while(alias[index] != "\0"){
        key *= alias[index];
    }
    key *= (MAXSIZE - strlen(alias));
    key = key % MAXSIZE;
    return key;
}

Tree *hash_insertar(Tree *tree, char *alias, Conjunto conj){
    int key = hash_key(alias);
    tree[key] = tree_insertar(tree[key], conj, alias);
    return tree;
}

void hash_imprimir(Tree *tree){
    int index = 0;
    while(index < MAXSIZE){
        if(tree[index] != NULL){
            printf("Posicion: %d\n", index);
            tree_imprimir(tree[index]);
        }
    }
}