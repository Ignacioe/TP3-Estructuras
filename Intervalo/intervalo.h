#ifndef __INTERVALO_H__
#define __INTERVALO_H__

typedef struct {
  int inicio;
  int final;
} Intervalo;

/**
 * Devuelve un intervalo formado por los extremos dados.
 */
Intervalo *intervalo_crear(int inicio, int final);

/**
 * Destruye el intervalo dado
 */
void intervalo_destruir(Intervalo * intervalo);

/**
 * Indica si el intervalo dado es valido
 */
int intervalo_validar(Intervalo * intervalo);

/**
 * Indica si los dos intervalos dados se intersecan
 */
int intervalo_interseca(Intervalo * intervaloA, Intervalo * intervaloB);

/**
 * Devuelve la interseccion entre dos intervalos
 */
Intervalo *intervalo_interseccion(Intervalo *intervaloA, Intervalo *intervaloB);

/**
 * Imprime en pantalla el intervalo dado
 */
void intervalo_imprimir(Intervalo * intervalo);

/**
 * Indica si dos intervalos dados son iguales
 */
int intervalo_coinciden(Intervalo * intervaloA, Intervalo * intervaloB);

/**
 * Compara dos intervalos y calcula cual es el "menor"
 */
int intervalo_comparar(Intervalo *intervaloA, Intervalo *intervaloB);


#endif                          /* __INTERVALO_H__ */
