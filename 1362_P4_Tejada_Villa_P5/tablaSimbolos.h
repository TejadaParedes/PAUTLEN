#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "tablaHash.h"

#define TABLA_SIMBOLOS_GLOBAL_TAM       65536
#define TABLA_SIMBOLOS_LOCAL_TAM        65536

/*SOLO PARA EL MODO EXTENDIDO CON VARIAS TABLAS DE SIMBOLOS LOCALES (FUNCIONES ANIDADAS)*/
#define TABLA_SIMBOLOS_LOCAL_NIVELES    5

STATUS declarar(const char* id, int num);
STATUS declararGlobal(const char* id, int num);
STATUS declararLocal(const char* id, int num);
INFO_SIMBOLO *usoGlobal(const char* id);
INFO_SIMBOLO *usoLocal(const char* id);
STATUS declararFuncion(const char* id, int num);
STATUS cerrarFuncion();
void terminar();

#endif /* TABLASIMBOLOS_H */