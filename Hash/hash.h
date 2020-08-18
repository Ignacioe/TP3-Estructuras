#ifndef __HASH_H__
#define __HASH_H__

#include "../Tree/Tree.h"

/**
 * Crea una nueva tabla hash.
 */
Tree *hash_crear();

/**
 * Libera la memoria de una tabla hash.
 */
void hash_eliminar(Tree *tabla);

/**
 * Devuelve una key para un alias dado.
 */
int hash_key(char *alias);

/**
 * Busca un conjunto en la tabla hash.
 */
Conjunto hash_seek(Tree *tabla, char* buffer);

/**
 * Inserto un conjunto y su alias en la tabla hash
 */
Tree *hash_insertar(Tree *, Conjunto conj, char *alias);

/**
 * Imprimo la tabla hash
 */
void hash_imprimir(Tree *tree);

#endif                          /* __HASH_H__ */