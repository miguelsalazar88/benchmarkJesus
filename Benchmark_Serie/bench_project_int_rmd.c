/**********************************************************************************
 * Fecha: 9 de agosto 2022
 * Autor: Jesus Chaves
 * Tema: Construccion Benchmark Multiplicacion de matrices
**********************************************************************************/
#include "bench_lib.h" /* -> Pragmas */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

/* Se requiere reservar un espacio de memoria */
#define DATA_SIZE (1024*1024*64*3)
static int MEM_CHUNK[DATA_SIZE];

/* Se implementa la multiplicacion de matrices con iguales dimensiones
 * Se inicializan las matrices con numeros aleatorios */

int main(int argc, char **argv){
    int N;
    N = (int) atof(argv[1]);

    /* Inicialización de matrices */
    int *a, *b, *c;
    a = MEM_CHUNK;
    b = a + N*N;
    c = b + N*N;
    inicializacion_int_rmd(a, b, c, N);

    /* Impresión de matriz */

    punto_prueba_inicial();
    multiplicacion_int(a, b, c, N);
    punto_prueba_final();

    return 0;
}