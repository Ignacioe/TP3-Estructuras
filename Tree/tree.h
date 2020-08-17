#ifndef __TREE_H__
#define __TREE_H__

#include "../Conjunto/Conjunto.h"

typedef struct _Nodo {
  char *alias;
  Conjunto conj;
  int altura;
  struct _Nodo *izq;
  struct _Nodo *der;
} Nodo;

typedef Nodo *Tree;


/**
 * Devuelve un arbol vacío.
 */
Tree tree_crear();

/**
 * Devuelve un nuevo nodo con el valor de conjunto dado
 */
Tree tree_nuevo_nodo(Conjunto conj, char *alias);

/**
 * Destruye el arbol dado
 */
void tree_destruir(Tree tree);

/**
 * Destruye unicamente el nodo dado
 */
void tree_destruir_nodo(Nodo *tree);

/**
 * Inserta un conjunto dado en el arbol indicado
 */
Tree tree_insertar(Tree tree, Conjunto conj, char *alias);

/**
 * Devuelve la altura asignada al arbol dado
 */
int tree_altura(Tree tree);

/**
 * Calcula y devuelve la altura que debe tener el arbol dado
 */
int tree_nueva_altura(Tree tree);

/**
 * Devuelve el factor de balance del arbol dado
 */
int tree_balance_factor(Tree tree);

/**
 * Aplica la rotacion a derecha al arbol dado
 */
Tree tree_rotar_derecha(Tree tree);

/**
 * Aplica la rotacion a derecha al arbol dado
 */
Tree tree_rotar_izquierda(Tree tree);

/**
 * Balancea el arbol dado
 */
Tree tree_balancear(Tree tree);

/**
 * Elimina un conjunto dado por el alias en el arbol indicado
 */
Tree tree_eliminar(Tree tree, char *alias);

/**
 * Recorre un arbol dado con DFS y 
 * aplica la funcion visitante a cada nodo
 */
void tree_imprimir(Tree tree);

#endif                          /* __TREE_H__ */