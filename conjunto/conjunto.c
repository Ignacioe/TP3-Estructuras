#include "conjunto.h"
#include "intervalo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Conjunto conjunto_agregar_intervalo(Conjunto conj, Intervalo *interv){
    GNodo *nuevo = malloc(sizeof(GNodo));
    nuevo->dato = interv;
    nuevo->sig= NULL;
    nuevo->ant = conj->ultimo;
    if (conj->ultimo != NULL) 
        conj->ultimo->sig = nuevo;
    if (conj->primero == NULL) 
        conj->primero = nuevo;
    conj->cantidad ++;
    conj->ultimo = nuevo;
    return conj;
}

void conjunto_imprimir(Conjunto conj){
    GNodo *nodo = conj->primero;
    while(nodo->sig != NULL){
        intervalo_imprimir(nodo->dato);
        nodo = nodo->sig;
    }
}

Conjunto conjunto_append(GNodo *nodo, Conjunto conj) {
  nodo->ant = NULL;
  nodo->sig = conj->primero;
  conj->primero->ant = nodo;
  conj->primero = nodo;
  conj->cantidad++;

  return conj;
}

Conjunto conjunto_merge(Conjunto conj1, Conjunto conj2, Compara c) {
  if (conj1->cantidad == 0)
    return conj2;
  if (conj2->cantidad == 0)
    return conj1;
  if (c(conj1->primero->dato, conj2->primero->dato) <= 0) {
    if (conj1->cantidad == 1) {
      conj1 = conjunto_append(conj1->primero, conj2);
    } else {
      GNodo *nodoAux = conj1->primero;
      conj1->primero = conj1->primero->sig;
      conj1->cantidad--;
      conj1 = conjunto_merge(conj1, conj2, c);
      conj1 = conjunto_append(nodoAux, conj1);
    }

    return conj1;
  } else {
    if (conj2->cantidad == 1) {
      conj2 = conjunto_append(conj2->primero, conj1);
    } else {
      GNodo *nodoAux = conj2->primero;
      conj2->primero = conj2->primero->sig;
      conj2->cantidad--;
      conj2 = conjunto_merge(conj1, conj2, c);
      conj2 = conjunto_append(nodoAux, conj2);
    }

    return conj2;
  }
}

Conjunto conjunto_split(Conjunto conj) {
  int medio = conj->cantidad / 2, indice = 0;
  GNodo *nodoAux = conj->primero;
  Conjunto conj2 = malloc(sizeof(Extremos));
  for (; indice < medio; indice++, nodoAux = nodoAux->sig);
  conj2->primero = nodoAux;
  conj2->ultimo = conj->ultimo;
  conj->ultimo = nodoAux->ant;
  conj2->cantidad = conj->cantidad - medio;
  conj->cantidad = medio;

  conj2->primero->ant = NULL;
  conj->ultimo->sig = NULL;

  return conj2;
}

Conjunto conjunto_mergeSort(Conjunto conj, Compara c) {
  if (conj->cantidad <= 1)
    return conj;
  Conjunto aux = conj;
  Conjunto derecha = conjunto_split(conj);
  derecha = conjunto_mergeSort(derecha, c);
  conj = conjunto_mergeSort(conj, c);

  conj = conjunto_merge(conj, derecha, c);
  aux->primero = conj->primero;
  aux->ultimo = conj->ultimo;
  aux->cantidad = conj->cantidad;
  conj = aux;
  free(derecha);

  return conj;
}

Conjunto conjunto_colapsar(Conjunto conj){
    GNodo *nodo = conj->primero;
    GNodo *aux;
    while(nodo->sig != NULL){
        aux = nodo->sig;
        if(nodo->dato->final >= aux->dato->inicio){
            nodo->dato->final = aux->dato->final;
            nodo->sig = aux->sig;
            aux->sig->ant = nodo;
            intervalo_destruir(aux->dato);
            free(aux);
            conj->cantidad --;
        }
        else{
            nodo = aux;
        }
    }
}

Conjunto conjunto_inicializar(){
    Conjunto conj = malloc(sizeof(Conjunto));
    conj->primero = NULL;
    conj->ultimo = NULL;
    conj->cantidad = 0;
}
