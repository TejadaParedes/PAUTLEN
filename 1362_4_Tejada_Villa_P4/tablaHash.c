#include "tablaHash.h"

INFO_SIMBOLO *crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){

    INFO_SIMBOLO *info_s = NULL;

    if(!lexema) return NULL;

    info_s = (INFO_SIMBOLO*)calloc(1, sizeof(INFO_SIMBOLO));

    if (!info_s) return NULL;

    info_s->lexema = (char*)calloc(strlen(lexema)+1, sizeof(char));

    if(!info_s->lexema){
        liberar_info_simbolo(info_s);
        return NULL;
    }

    strcpy(info_s->lexema, lexema);
    info_s->categoria = categ;
    info_s->tipo = tipo;
    info_s->clase = clase;
    info_s->adicional1 = adic1;
    info_s->adicional2 = adic2;

    return info_s;

}

void liberar_info_simbolo(INFO_SIMBOLO *is){

    if(!is) return;

    if(is->lexema) free(is->lexema);

    free(is);

    return;
}

NODO_HASH *crear_nodo(INFO_SIMBOLO *is){

    NODO_HASH *nh = NULL;

    nh = (NODO_HASH*)calloc(1, sizeof(NODO_HASH));

    if(!nh) return NULL;

    nh->info = is;

    return nh;
}

void liberar_nodo(NODO_HASH *nh){

    if(!nh) return;

    if(nh->info) liberar_info_simbolo(nh->info);

    free(nh);

    return;
}

TABLA_HASH *crear_tabla(int tam){

    TABLA_HASH *th = NULL;

    if(tam < 1) return NULL;

    th = (TABLA_HASH*)calloc(1, sizeof(TABLA_HASH));
    if(!th) return NULL;

    th->tam = tam;

    th->tabla = (NODO_HASH**)calloc(tam, sizeof(NODO_HASH*));

    if(!th->tabla){
        free(th);
        return NULL;
    }

    return th;
}

void liberar_tabla(TABLA_HASH *th){

    int i = 0;
    NODO_HASH *nh1 = NULL, *nh2 = NULL;

    if(!th) return;

    if(th->tabla){
        for(i = 0; i < th->tam; i++){
            while(nh1){
                nh2 = nh1->siguiente;
                liberar_nodo(nh1);
                nh1 = nh2;
            }
        }
        free(th->tabla);
    }

    free(th);

    return;
}

unsigned long hash(const char *str){

    unsigned long hash = HASH_INI;
    int c = 0;

    while(c = *str++){
        hash = HASH_FACTOR * hash + c;
    }

    return hash;
    
}

INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *th, const char *lexema){

    unsigned long hash_r = 0;
    NODO_HASH *nh = NULL;

    if(!th || !lexema) return NULL;

    hash_r = hash(lexema);

    nh = th->tabla[hash_r%th->tam];

    while (nh && (!nh->info || strcmp(nh->info->lexema, lexema))){
        nh = nh->siguiente;
    }
     
    if(nh) return nh->info;

    return NULL;
}

STATUS insertar_simbolo(TABLA_HASH *th, const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2){

    unsigned long hash_r = 0;
    NODO_HASH *nh = NULL;
    INFO_SIMBOLO *is = NULL;

    if(!th || !lexema) return ERR;

    hash_r = hash(lexema);

    is = crear_info_simbolo(lexema, categ, tipo, clase, adic1, adic2);
    if(!is) return ERR;

    nh = crear_nodo(is);
    if(!nh){
        liberar_info_simbolo(is);
        return ERR;
    } 

    nh->siguiente = th->tabla[hash_r%th->tam];
    th->tabla[hash_r%th->tam] = nh;

    return OK;

}

void borrar_simbolo(TABLA_HASH *th, const char *lexema){

    unsigned long hash_r = 0;
    NODO_HASH *nh = NULL, *nh_aux = NULL;

    if(!th || !lexema) return;  

    nh = th->tabla[hash_r%th->tam];

    while (nh || (!nh->info || strcmp(nh->info->lexema, lexema))){
        nh_aux = nh;
        nh = nh->siguiente;
    }
    
    if(!nh) return;

    if(nh_aux) th->tabla[hash_r%th->tam] = nh->siguiente;
    else nh_aux->siguiente = nh->siguiente;
    
    liberar_nodo(nh);

    return; 
}