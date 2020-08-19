#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Conjunto/conjunto.h"
#include "./Intervalo/intervalo.h"
#include "./Tree/tree.h"
#include "./Hash/hash.h"

#define MAXBUFFER 200

void imprimir_menu(){
    printf("Formatos validos de comandos:\n");
    printf("    - Imprimir un conjunto:\n        imprimir alias\n\n");
    printf("    - Agregar conjuntos por extension:\n        alias = {...}\n\n");
    printf("    - Agregar conjuntos por comprension:\n        alias = {x/a<=x<=b}\n\n");
    printf("    - Union de intervalos:\n        aliasUnion = aliasA | aliasB\n\n");
    printf("    - Interseccion de intervalos:\n        aliasInter = aliasA & aliasB\n\n");
    printf("    - Resta de intervalos:\n        aliasResta = aliasA - aliasB\n\n");
    printf("    - Complemento de un intervalo:\n        aliasComp = ~aliasA\n\n");
    printf("    - Salir del interprete:\n        salir\nIngrese su comando: ");
}

int is_char_digit(char caracter){
    int exit = 1;
    if(caracter > 47 && caracter < 58){
        exit = 0;
    }
    return exit;
}

Conjunto leer_extension(char *buffer){
    Conjunto conj = conjunto_inicializar();
    Intervalo *interAux;
    int index = 0, iniAux = 0, finAux = 0, bandera = 0, salida = 0, signo = 1;
    char *conjBuffer = &buffer[0] + 3;
    while(salida == 0){
        if(is_char_digit(conjBuffer[index]) == 0){
            if(bandera == 0){
                iniAux *= 10;
                iniAux += conjBuffer[index] - 48;
            }
            if(bandera == 1){
                finAux *= 10;
                finAux += conjBuffer[index] - 48;
            }
        }
        if(conjBuffer[index] == '-'){
            signo = -1;
        }
        if(conjBuffer[index] == ':'){
            iniAux *= signo;
            signo = 1; 
            bandera = 1;
        }
        if(conjBuffer[index] == ','){
            if(bandera == 0){
                interAux = intervalo_crear(iniAux, iniAux);
            } else {
                finAux *= signo;
                signo = 1; 
                interAux = intervalo_crear(iniAux, finAux);
            }
            iniAux = 0;
            finAux = 0;
            conjunto_agregar_intervalo(conj, interAux);
            bandera = 0;
        }
        if(conjBuffer[index] == '}'){
            if(bandera == 0){
                interAux = intervalo_crear(iniAux, iniAux);
            } else {
                interAux = intervalo_crear(iniAux, finAux);
            }
            conjunto_agregar_intervalo(conj, interAux);
            salida = 1;
        }
        index++;
    }
    conj = conjunto_mergeSort(conj, &intervalo_comparar);
    conjunto_colapsar(conj);
    return conj;
}


Conjunto operar(char *buffer, Tree *tabla){
    Conjunto aux1 = conjunto_inicializar(), aux2 = conjunto_inicializar();
    char aliasA[MAXBUFFER], aliasB[MAXBUFFER], operacion;

    if(buffer[2] == '~'){
        sscanf(buffer, "= ~%s", aliasA);
        aux1 = hash_seek(tabla, aliasA);
        if(aux1 != NULL) return conjunto_complemento(aux1);
        else printf("\n\n * *No se ha podido encontrar el conjunto * *\n\n");
    } else {
        sscanf(buffer, "= %s %c %s", aliasA, &operacion, aliasB);
        printf("aliasA %s, operacion %c, aliasB %s", aliasA, operacion, aliasB);
        aux1 = hash_seek(tabla, aliasA);
        aux2 = hash_seek(tabla, aliasB);
        if(aux1 != NULL && aux2 != NULL){
            if(operacion == '|'){
                return conjunto_union(aux1, aux2);
            } else {
                if(operacion == '&'){
                    return conjunto_interseccion(aux1, aux2);
                } else {
                    if(operacion == '-'){
                        return conjunto_resta(aux1, aux2);
                    } else {
                        printf("\n\n * * Operacion no reconocida * *\n\n");
                    }
                }
            } 
        } else {
            printf("\n\n * * No se ha podido encontrar uno de los conjuntos * * \n\n");
        }
    }
    return NULL;
}

int main(){
    int input = 0;
    Conjunto aux = conjunto_inicializar();
    char alias[MAXBUFFER], buffer[MAXBUFFER];
    Tree *tabla = hash_crear();
    Conjunto auxPrint;
    while(input != -1){
        imprimir_menu();
        fgets(buffer, MAXBUFFER, stdin);
        sscanf(buffer, "%s %[^\n]", alias, buffer);
        if(strcmp(alias, "imprimir") == 0){
            auxPrint = hash_seek(tabla, buffer);
            if(auxPrint != NULL) conjunto_imprimir(auxPrint);
        } else {
            if(strcmp(alias, "salir") == 0){
                printf("\n * * Saliendo del interprete * *\n");
                input = -1;
                hash_eliminar(tabla);
            } else {
                if(buffer[0] == '=' && buffer[1] == ' '){
                    if(buffer[2] == '{' && buffer[2] != '}'){
                        if((is_char_digit(buffer[3]) == 0) || (buffer[3] == '-')){
                            aux = leer_extension(buffer);
                            if(aux!= NULL) tabla = hash_insertar(tabla, aux, alias);
                        } else {
                            //aux = leer_comprension(buffer);
                            //tabla = hash_insertar(tabla, aux, alias);
                        }
                    } else {
                        aux = operar(buffer, tabla);
                        if(aux != NULL) tabla = hash_insertar(tabla, aux, alias);
                    }
                } else {
                    printf("\n * * Formato no aceptado * *\n\n * * Intente nuevamente * *\n");
                }
            }
        }
    }

    /*empiezan ejemplos
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
    */
    return 0;
}