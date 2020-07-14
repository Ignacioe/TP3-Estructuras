#include "conjunto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Conjunto *conjunto_extension(char* datos){
    int i, j = 0, bandera = 0;
    char* ext;
    Conjunto *nuevoConj = malloc(sizeof(Conjunto));
    int inicio, final;
    for (i = 0; datos[i] != '{'; i++);
    while( datos[i] != '}'){
        if( atoi(datos[i]) != 0 || datos[i] == '0'){
            ext[j] = datos[i];
            j++;   
        }
        if(datos[i] == ':'){
            ext[j] = '\n';
            j = 0;
            inicio = atoi(ext);
            bandera = 1;
        }
        if(datos[i] == ','){
            ext[j] = '\n';
            j = 0;
            final = atoi(ext);
            if(bandera == 0) inicio = atoi(ext);
            conjunto_agregar_int(nuevoConj, inicio, final);
            bandera = 0;
        }
        i++;
    }
        ext[j] = '\n';
        final = atoi(ext);
        if(bandera == 0) inicio = atoi(ext);
        conjunto_agregar_int(nuevoConj, inicio, final);
}