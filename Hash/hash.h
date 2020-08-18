#ifndef __HASH_H__
#define __HASH_H__

#include "../Tree/Tree.h"

/**
 * Crea una nueva tabla hash
 */
Tree *hash_crear();

/**
 * Libera la memoria de una tabla hash
 */
void hash_eliminar(Tree *tabla);

#endif                          /* __HASH_H__ */