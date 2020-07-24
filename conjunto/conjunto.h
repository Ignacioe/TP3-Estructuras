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
 * Agrega un intervalo a un conjunto.
 */
void conjunto_agregar_intervalo(Conjunto conj, Intervalo *interv);

/**
 * Crea un nuevo conjunto definido por comprension.
 */
Conjunto conjunto_comprension(char* ley);

/**
 * Imprime en pantalla un conjunto.
 */
void conjunto_imprimir(Conjunto dato);

/**
 * 
 */
Conjunto conjunto_append(GNodo *nodo, Conjunto conj);

/**
 * 
 */
Conjunto conjunto_merge(Conjunto conj1, Conjunto conj2, Compara c);

/**
 * 
 */
Conjunto conjunto_split(Conjunto conj);

/**
 * 
 */
Conjunto conjunto_mergeSort(Conjunto conj, Compara c);

/**
 * Recorre la lista juntando los intervalos solapados
 */
void conjunto_colapsar(Conjunto conj);

/**
 * Inicializa un conjunto
 */
Conjunto conjunto_inicializar();

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