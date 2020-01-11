#include <stdio.h>
#include <string.h>
#include "alfa.h"

int yylex();
int yyparse();
extern FILE *yyin;
extern FILE *yyout;


int main(int argc, char const *argv[]){
    

    if(argc != 3){
        fprintf(stderr, "Error en los parametros de entrada.\nEjecutad:\t./alfa <fichero_de_entrada> <fichero_de_saliada>\n");
        return 0;
    }

    yyin = fopen(argv[1], "r");
    if(!yyin){
        fprintf(stderr, "Error a la hora de abrir el fichero de entrada.\n");
        return 0;
    }

    yyout = fopen(argv[2], "w");
    if(!yyout){
        fprintf(stderr, "Error a la hora de abrir el fichero de salida.\n");
        fclose(yyin);
        return 0;
    }



    escribir_subseccion_data(yyout);
    escribir_cabecera_bss(yyout);

    if(!yyparse()){
        fprintf(stdout, "Analisis realizado con exito\n");
    }
    else{
        fprintf(stdout, "Analisis realizado sin exito\n");
    }

    escribir_fin(yyout);

    fclose(yyin);
    fclose(yyout);


    return 0;
}
