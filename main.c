#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./Conjunto/conjunto.h"
#include "./Intervalo/intervalo.h"

int main(){
    printf("Hola");
    Conjunto conj = conjunto_inicializar();
    Intervalo *int1 = intervalo_crear(0,1);
    intervalo_imprimir(int1);
    Intervalo *int2 = intervalo_crear(2,3);
    intervalo_imprimir(int2);
    conj = conjunto_agregar_intervalo(conj, int1);
    conjunto_imprimir(conj);
    printf("Hola");
    conj = conjunto_agregar_intervalo(conj, int2);
    conj = conjunto_colapsar(conj);
    conjunto_imprimir(conj);
}