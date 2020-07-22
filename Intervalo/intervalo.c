#include "intervalo.h"
#include <stdlib.h>
#include <stdio.h>

Intervalo *intervalo_crear(int extIzq, int extDer) {
  Intervalo *nuevo = malloc(sizeof(Intervalo));
  nuevo->inicio = extIzq;
  nuevo->final = extDer;

  return nuevo;
}

void intervalo_destruir(Intervalo *intervalo) {
  free(intervalo);
}

int intervalo_validar(Intervalo *intervalo) {
  return intervalo->inicio < intervalo->final;
}

int intervalo_interseca(Intervalo *intervaloA, Intervalo *intervaloB) {
  return !(intervaloA->final < intervaloB->inicio
           || intervaloA->inicio > intervaloB->final);
}

Intervalo *intervalo_interseccion(Intervalo *intervaloA, Intervalo *intervaloB){
  int inicio, final;
  if(intervaloA->inicio < intervaloB->inicio){
    inicio = intervaloB->inicio;
  } else {
    inicio = intervaloA->inicio;
  }
  if(intervaloA->final < intervaloB->final){
    final = intervaloA->final;
  } else {
    final = intervaloB->final;
  }
  Intervalo *interseccion = intervalo_crear(inicio, final);
  return interseccion;
}

void intervalo_imprimir(Intervalo *intervalo) {
  if(intervalo->inicio == intervalo->final){
    printf("%d\n", intervalo->inicio);
  }
  else{
    printf("%d:%d\n", intervalo->inicio, intervalo->final);
  }
}

int intervalo_coinciden(Intervalo *intervaloA, Intervalo *intervaloB) {
  return intervaloA->inicio == intervaloB->inicio
      && intervaloA->final == intervaloB->final;
}

int intervalo_comparar(Intervalo *intervaloA, Intervalo *intervaloB) {
  return (intervaloA->inicio < intervaloB->inicio ||(intervaloA->final < intervaloB->final && intervaloA->inicio == intervaloB->inicio));
}
