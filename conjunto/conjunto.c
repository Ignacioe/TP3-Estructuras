#include "conjunto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

Conjunto conjunto_inicializar(){
  Conjunto conj = malloc(sizeof(Extremos));
  conj->primero = NULL;
  conj->ultimo = NULL;
  conj->cantidad = 0;
  return conj;
}

int conjunto_igualdad(Conjunto conjA, Conjunto conjB){
  int band = 0;
  GNodo *indexA = conjA->primero, *indexB = conjB->primero;
  while(indexA != NULL && indexB != NULL && band == 0){
    if(intervalo_coinciden(indexA->dato, indexB->dato) != 0){
      band = 1;
    }
    indexA = indexA->sig;
    indexB = indexB->sig;
  }
  if(indexA != NULL || indexB != NULL){
    band = 1
  }
  return band;
}

void conjunto_agregar_intervalo(Conjunto conj, Intervalo *interv){
  GNodo *nuevo = malloc(sizeof(GNodo));
  nuevo->dato = interv;
  nuevo->sig = NULL;
  nuevo->ant = conj->ultimo;
  if (conj->ultimo != NULL)
    conj->ultimo->sig = nuevo;
  if (conj->primero == NULL) {
    conj->primero = nuevo;
  }
  conj->cantidad ++;
  conj->ultimo = nuevo;
}

Conjunto conjunto_append(GNodo *nodo, Conjunto conj) {
  nodo->ant = NULL;
  nodo->sig = conj->primero;
  conj->primero->ant = nodo;
  conj->primero = nodo;
  conj->cantidad++;
  return conj;
}

void conjunto_imprimir(Conjunto conj){
  GNodo *index = conj->primero;
  printf("[");
  while(index != NULL){
    intervalo_imprimir(index->dato);
    if(index->sig != NULL) printf(",");
    index = index->sig;
  }
  printf("]\n");
}

void conjunto_destruir(Conjunto conj){
  GNodo *aux;
  while(conj->primero != NULL){
    aux = conj->primero;
    conj->primero = conj->primero->sig;
    intervalo_destruir(aux->dato);
    free(aux);
  }
  free(conj);
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

void conjunto_colapsar(Conjunto conj){
  GNodo *nodo = conj->primero;
  GNodo *aux;
  while(nodo->sig != NULL){
    aux = nodo->sig;
    if(nodo->dato->final +1 >= aux->dato->inicio){
      if(nodo->dato->final < aux->dato->final) nodo->dato->final = aux->dato->final;
      nodo->sig = aux->sig;
      if(aux->sig != NULL) aux->sig->ant = nodo;
      intervalo_destruir(aux->dato);
      free(aux);
      conj->cantidad --;
    }
    else{
      nodo = aux;
    }
  }
}

Conjunto conjunto_union(Conjunto conjuntoA, Conjunto conjuntoB){
  Conjunto nuevo = conjunto_inicializar();
  Intervalo *aux;
  GNodo *indexA = conjuntoA->primero, *indexB = conjuntoB->primero;
  while (indexA != NULL){
    aux = intervalo_crear(indexA->dato->inicio, indexA->dato->final);
    conjunto_agregar_intervalo(nuevo, aux);
    indexA = indexA->sig;
  }
  while (indexB != NULL){
    aux = intervalo_crear(indexB->dato->inicio, indexB->dato->final);
    conjunto_agregar_intervalo(nuevo, aux);
    indexB = indexB->sig;
  }
  nuevo = conjunto_mergeSort(nuevo, &intervalo_comparar);
  conjunto_colapsar(nuevo);
  return nuevo;
}

Conjunto conjunto_interseccion(Conjunto conjuntoA, Conjunto conjuntoB){
  Conjunto nuevo = conjunto_inicializar();
  GNodo *indexA = conjuntoA->primero, *indexB = conjuntoB->primero;
  Intervalo *interseccion;
  while(indexA != NULL && indexB != NULL){
    if(intervalo_interseca(indexA->dato, indexB->dato)){
      interseccion = intervalo_interseccion(indexA->dato, indexB->dato);
      conjunto_agregar_intervalo(nuevo, interseccion);
    }
    if(indexA->dato->final > indexB->dato->final){
      indexB = indexB->sig;
    } else {
      indexA = indexA->sig;
    }    
  }
  return nuevo;
}

Conjunto conjunto_clonar(Conjunto conj){
  Conjunto nuevo = conjunto_inicializar();
  Intervalo *aux;
  GNodo *indexA = conj->primero;
  while (indexA != NULL){
    aux = intervalo_crear(indexA->dato->inicio, indexA->dato->final);
    conjunto_agregar_intervalo(nuevo, aux);
    indexA = indexA->sig;
  }
  return nuevo;
}

void conjunto_restar_intervalo(Conjunto conj, Intervalo *inter){
  GNodo *index = conj->primero, *nodoAux = malloc(sizeof(GNodo));
  Intervalo *aux;
  int bandera = 0;
  while (index != NULL && bandera == 0){
    if(index->dato->final >= inter->final) bandera = 1;
    if(intervalo_interseca(inter, index->dato)){
      if(inter->inicio > index->dato->inicio){
        if(inter->final < index->dato->final){
          aux = intervalo_crear(inter->final +1, index->dato->final);
          nodoAux->sig = index->sig;
          if(index->sig != NULL) index->sig->ant = nodoAux;
          nodoAux->ant = index;
          nodoAux->dato = aux;
          index->sig = nodoAux;
        } 
        index->dato->final = inter->inicio -1;
      } else {
        if(inter->final >= index->dato->final){
          if(index->ant != NULL){
            index->ant->sig = index->sig;
          }
          if(index->sig != NULL){
            index->sig->ant = index->ant;
          }
          intervalo_destruir(index->dato);
        } else {
          index->dato->inicio = inter->final;
        }
      }
      if(inter->final == index->dato->inicio) {
        index->dato->inicio = index->dato->inicio +1; 
      } 
      if(inter->inicio == index->dato->final) {
        index->dato->final = index->dato->final-1;
      }
    }
    index = index->sig;
  }
}

Conjunto conjunto_resta(Conjunto conjuntoA, Conjunto conjuntoB){
  Conjunto nuevo = conjunto_clonar(conjuntoA);
  GNodo *index = conjuntoB->primero;
  while (index != NULL){
    conjunto_restar_intervalo(nuevo, index->dato);
    index = index->sig;
  }
  return nuevo;
}

Conjunto conjunto_complemento(Conjunto conj){
  Conjunto universo = conjunto_inicializar();
  Intervalo *aux = intervalo_crear(INT_MIN+1, INT_MAX-1);
  conjunto_agregar_intervalo(universo, aux);
  Conjunto nuevo = conjunto_resta(universo, conj);
  return nuevo;
}
