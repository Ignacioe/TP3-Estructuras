#ifndef __CONJUNTO_H__
#define __CONJUNTO_H__

#include "../Intervalo/intervalo.h"

typedef struct _GNodo {
  Intervalo *dato;
  struct _GNodo *sig;
  struct _GNodo *ant;
} GNodo;

typedef struct {
  GNodo *primero;
  GNodo *ultimo;
  int cantidad;
} Extremos;

typedef Extremos *Conjunto;

typedef int (*Compara) (Intervalo *dato1, Intervalo *dato2);

/**
 * Inicializa un conjunto
 */
Conjunto conjunto_inicializar();

/**
 * Agrega un intervalo al final del conjunto.
 */
void conjunto_agregar_intervalo(Conjunto conj, Intervalo *interv);

/**
 * Agrega un nodo al principio del conjunto.
 */
Conjunto conjunto_append(GNodo *nodo, Conjunto conj);

/**
 * Imprime en pantalla un conjunto.
 */
void conjunto_imprimir(Conjunto dato);

/**
 * Libera la memoria de un conjunto.
 */
void conjunto_destruir(Conjunto conj);

/**
 * Une dos conjuntos de manera ordenada.
 */
Conjunto conjunto_merge(Conjunto conj1, Conjunto conj2, Compara c);

/**
 * Divide un conjunto en dos partes.
 */
Conjunto conjunto_split(Conjunto conj);

/**
 * Ordena un conjunto pediante el algoritmo mergeSort
 */
Conjunto conjunto_mergeSort(Conjunto conj, Compara c);

/**
 * Recorre la lista juntando los intervalos solapados
 */
void conjunto_colapsar(Conjunto conj);

/**
 * Devuelve la union de dos conjuntos.
 */
Conjunto conjunto_union(Conjunto a, Conjunto b);

/**
 * Devuelve la interseccion de dos conjuntos.
 */
Conjunto conjunto_interseccion(Conjunto a, Conjunto b);

/**
 * Devuelve la resta de dos conjuntos.
 */
Conjunto conjunto_resta(Conjunto a, Conjunto b);

/**
 * Devuelve el complemento de un conjunto.
 */
Conjunto conjunto_complemento(Conjunto dato);

#endif                          /* __CONJUNTO_H__ */