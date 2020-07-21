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

typedef int (*Compara) (void *dato1, void *dato2);

/**
 * Crea un nuevo conjunto definido por extension.
 */
Conjunto conjunto_agregar_intervalo(Conjunto conj, Intervalo *interv);

/**
 * Crea un nuevo conjunto definido por comprension.
 */
Conjunto conjunto_comprension(char* ley);

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

/**
 * Imprime en pantalla un conjunto.
 */
void conjunto_imprimir(Conjunto dato);

/**
 * Recorre la lista juntando los intervalos solapados
 */
Conjunto conjunto_colapsar(Conjunto conj);

/**
 * Inicializa un conjunto
 */
Conjunto conjunto_inicializar();

#endif                          /* __CONJUNTO_H__ */