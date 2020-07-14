#ifndef __CONJUNTO_H__
#define __CONJUNTO_H__

typedef struct {
  int inicio;
  int final;
} Intervalo;

typedef struct _Elemento {
    Intervalo* dato;
    struct _Elemento *sig;
} Conjunto;


/**
 * Crea un nuevo conjunto definido por extension.
 */
Conjunto *conjunto_extension(char* datos);

/**
 * Crea un nuevo conjunto definido por comprension.
 */
Conjunto *conjunto_comprension(char* ley);

/**
 * Devuelve la union de dos conjuntos.
 */
Conjunto *conjunto_union(Conjunto a, Conjunto b);

/**
 * Devuelve la interseccion de dos conjuntos.
 */
Conjunto *conjunto_interseccion(Conjunto a, Conjunto b);

/**
 * Devuelve la resta de dos conjuntos.
 */
Conjunto *conjunto_resta(Conjunto a, Conjunto b);

/**
 * Devuelve el complemento de un conjunto.
 */
Conjunto *conjunto_complemento(Conjunto dato);

/**
 * Imprime en pantalla un conjunto.
 */
void conjunto_imprimir(Conjunto dato);

/**
 * Reordena un conjunto de acuerdo al orden de los numeros naturales.
 */
Conjunto *conjunto_ordenar(Conjunto dato);

#endif                          /* __CONJUNTO_H__ */