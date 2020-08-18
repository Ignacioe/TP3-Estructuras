#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Tree tree_crear() {
  return NULL;
}

Tree tree_nuevo_nodo(Conjunto conj, char* alias) {
  Tree nodo = malloc(sizeof(Nodo));
  nodo->alias = alias;
  nodo->izq = NULL;
  nodo->der = NULL;
  nodo->conj = conj;
  nodo->altura = 0;

  return nodo;
}

void tree_destruir(Tree tree) {
  if (tree != NULL) {
    free(tree->alias);
    tree_destruir(tree->izq);
    tree_destruir(tree->der);
    tree_destruir_nodo(tree);
  }
}

void tree_destruir_nodo(Nodo *tree) {
  if (tree != NULL) {
    free(tree->alias);
    conjunto_destruir(tree->conj);
    free(tree);
  }
}

Tree tree_insertar(Tree tree, Conjunto conj, char* alias) {
  if(tree == NULL) {
    tree = tree_nuevo_nodo(conj, alias);
  } else {
    if(strcmp(tree->alias, alias) != 0){
        if(strcmp(tree->alias, alias)>0){
            tree->izq = tree_insertar(tree->izq, conj, alias);
        } else {
            tree->der = tree_insertar(tree->der, conj, alias);
        }
        tree->altura = tree_nueva_altura(tree);
        tree = tree_balancear(tree);
    } else {
        printf("El alias %s ya ha sido utilizado.\n", alias);
    }
  }
  return tree;
}

int tree_altura(Tree tree) {
  if (!tree)
    return -1;
  return tree->altura;
}

int tree_nueva_altura(Tree tree) {
  if (!tree)
    return -1;
  if (tree_altura(tree->izq) > tree_altura(tree->der))
    return tree_altura(tree->izq) + 1;
  else
    return tree_altura(tree->der) + 1;
}

int tree_balance_factor(Tree tree) {
  return tree_altura(tree->izq) - tree_altura(tree->der);
}

Tree tree_rotar_derecha(Tree tree) {
  Tree aux = tree->izq;
  tree->izq = aux->der;
  aux->der = tree;

  tree->altura = tree_nueva_altura(tree);
  aux->altura = tree_nueva_altura(aux);

  return aux;
}

Tree tree_rotar_izquierda(Tree tree) {
  Tree aux = tree->der;
  tree->der = aux->izq;
  aux->izq = tree;

  tree->altura = tree_nueva_altura(tree);
  aux->altura = tree_nueva_altura(aux);

  return aux;
}

Tree tree_balancear(Tree tree) {
  if (tree) {
    int balanceFactor = tree_balance_factor(tree);
    if (balanceFactor == 2) {
      if (tree_balance_factor(tree->izq) < 0)
        tree->izq = tree_rotar_izquierda(tree->izq);
      tree = tree_rotar_derecha(tree);

    }
    if (balanceFactor == -2) {
      if (tree_balance_factor(tree->der) > 0)
        tree->der = tree_rotar_derecha(tree->der);
      tree = tree_rotar_izquierda(tree);
    }
  }

  return tree;
}

Tree tree_obtener_minimo(Tree tree) {
  Tree aux = tree;
  if (aux) {
    if (!aux->izq) {
      return aux;
    }
  }
  return tree_obtener_minimo(aux->izq);
}


Tree tree_eliminar(Tree tree, char* alias) {
  if (tree) {
    if (strcmp(tree->alias, alias) == 0){
      if (!tree->der && !tree->izq) {
        tree_destruir_nodo(tree);
        tree = NULL;
      } else {
        if (!tree->der || !tree->izq) {
          Tree nodoAux = tree->izq ? tree->izq : tree->der;
          tree_destruir_nodo(tree);
          tree = nodoAux;
        }
        else {
          Tree nodoAux = tree_obtener_minimo(tree->der);
          tree->conj = nodoAux->conj;
          tree->alias = nodoAux->alias;
          tree->der = tree_eliminar(tree->der, alias);
        }
        tree->altura = tree_nueva_altura(tree);
      }
    } else {
      if (strcmp(tree->alias, alias) > 0) {
        tree->izq = tree_eliminar(tree->izq, alias);
      } else {
        tree->der = tree_eliminar(tree->der, alias);
      }
    }
  } else {
    printf("El elemento a eliminar no se encuentra en el arbol\n");
  }
  return tree_balancear(tree);
}

void tree_imprimir(Tree tree) {
  if (tree) {
    tree_imprimir(tree->izq);
    printf("%s: \n", tree->alias);
    conjunto_imprimir(tree->conj);
    tree_imprimir(tree->der);
  }
}