#ifndef _ALFA_H_
#define _ALFA_H_
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

#include "tablaHash.h"
#include "tablaSimbolos.h"
#include "generacion.h"

typedef struct{
    char lexema[MAX_LONG_ID+1];
    int tipo;
    int valor_entero;
    int es_direccion;
    int etiqueta;
}TIPO_ATRIBUTOS;
#endif