#include <stdio.h>
#include "tablaSimbolos.h"

TABLA_HASH *TablaSimbolosGlobal = NULL;
TABLA_HASH *TablaSimbolosLocal = NULL;

/* LAS DOS SIGUIENTES LÍNEAS SON PARA EL MODO EXTENDIDO CON VARIAS
   TABLAS DE SIMBOLOS LOCALES (FUNCIONES ANIDADAS)
   SI QUEREMOS LA IMPLEMENTACION QUE SIRVE PARA EL COMPILADOR,
   BASTARIA CON DECLARAR:
   
   TABLA_HASH *TablaSimbolosLocal = NULL;
*/
/*TABLA_HASH *TablaSimbolosLocal[TABLA_SIMBOLOS_LOCAL_NIVELES];
int nivelActual = 0;*/

STATUS declarar(const char *id, /*int num*/ INFO_SIMBOLO *is) {

    if(!TablaSimbolosLocal){
        return declararGlobal(id, /*num*/ is);
    }
    return declararLocal(id, /*num*/is);
}

STATUS declararGlobal(const char *id, /*int num*/ INFO_SIMBOLO *is) {

    if(!TablaSimbolosGlobal){
        TablaSimbolosGlobal = crear_tabla(TABLA_SIMBOLOS_GLOBAL_TAM);
        if(!TablaSimbolosGlobal) return ERR;

    }
    
    if(!buscar_simbolo(TablaSimbolosGlobal, id)){
        return insertar_simbolo(TablaSimbolosGlobal, id, is->categoria, is->tipo, is->clase, is->adicional1, is->adicional2/*id, VARIABLE, ENTERO, ESCALAR, num, 0*/); 
    }

    return ERR;    
}

STATUS declararLocal(const char *id, INFO_SIMBOLO *is/*int num*/) {

    if(!buscar_simbolo(TablaSimbolosLocal, id)){
        return insertar_simbolo(TablaSimbolosLocal, id, is->categoria, is->tipo, is->clase, is->adicional1, is->adicional2/*id, VARIABLE, ENTERO, ESCALAR, num, 0*/);
    }

    return ERR;   
}

INFO_SIMBOLO *usoGlobal(const char *id) {

    if(!TablaSimbolosGlobal) return NULL;

    return buscar_simbolo(TablaSimbolosGlobal, id);
}

INFO_SIMBOLO *usoLocal(const char *id) {

    INFO_SIMBOLO *is = NULL;

    if(!TablaSimbolosLocal) return usoGlobal(id);

    is = buscar_simbolo(TablaSimbolosLocal, id);

    if(!is) return usoGlobal(id);
    else return is;
}

STATUS declararFuncion(const char *id, INFO_SIMBOLO *is/*int num*/) {

    if(!buscar_simbolo(TablaSimbolosGlobal ,id)){
        if (insertar_simbolo(TablaSimbolosGlobal, id, is->categoria, is->tipo, is->clase, is->adicional1, is->adicional2/*FUNCION, ENTERO, ESCALAR, num, 0*/) == ERR) return ERR;
        liberar_tabla(TablaSimbolosLocal);
        TablaSimbolosLocal = crear_tabla(TABLA_SIMBOLOS_LOCAL_TAM);
        if(!TablaSimbolosLocal){
            borrar_simbolo(TablaSimbolosGlobal, id);
            liberar_tabla(TablaSimbolosLocal);
            TablaSimbolosLocal = NULL;
            return ERR;
        }
        if(insertar_simbolo(TablaSimbolosLocal, id, is->categoria, is->tipo, is->clase, is->adicional1, is->adicional2/*FUNCION, ENTERO, ESCALAR, num, 0*/) == ERR){
            borrar_simbolo(TablaSimbolosGlobal, id);
            liberar_tabla(TablaSimbolosLocal);
            TablaSimbolosLocal = NULL;
            return ERR;
        }
        return OK;
    }

    return ERR;
}


STATUS cerrarFuncion() {
    if(!TablaSimbolosLocal) return ERR;
    liberar_tabla(TablaSimbolosLocal);
    TablaSimbolosLocal = NULL;
    return OK;
}

int EsLocal(const char *id){

    if(!TablaSimbolosLocal) return 0;

    return buscar_simbolo(TablaSimbolosLocal, id)!=NULL;
}

void terminar() {
    if(TablaSimbolosLocal) liberar_tabla(TablaSimbolosLocal);
    liberar_tabla(TablaSimbolosGlobal);
    return;
}
