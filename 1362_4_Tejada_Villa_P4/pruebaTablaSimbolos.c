
#include "tablaSimbolos.h"

int main(int argc, char const *argv[]){

    FILE *fin = NULL;
    FILE *fout = NULL;
    int numero = 0, leido = 0;
    char cadena[100] = "\0";
    INFO_SIMBOLO *is = NULL;
    
    if(argc != 3){
        fprintf(stderr, "Número incorrecto de parametro de entrada.\nPara ejecutar el programa: ./pruebaTablaSimbolos <fichero_entrada> <fichero_salida>\n");
        return -1;
    }

    fin = fopen(argv[1], "r");
    if(!fin) return -1;

    fout = fopen(argv[2], "w");
    if(!fout){
        fclose(fin);
        return -1;
    }

    while ((leido = fscanf(fin, "%s%d", cadena, &numero)) > 0){
        if(leido == 1){
            is = usoLocal(cadena);
            if(!is){
                fprintf(fout, "%s\t-1\n", cadena);
            }
            else{
                fprintf(fout, "%s\t%d\n", cadena, is->adicional1);
            }
        }
        else if (leido == 2){
            if(numero < 0){
                if(!strcmp("cierre", cadena) && numero == -999){
                    fprintf(fout, "%s\n", cadena);
                    cerrarFuncion();
                }
                else{
                    if(declararFuncion(cadena, numero) == OK) fprintf(fout, "%s\n", cadena);
                    else fprintf(fout, "-1\t%s\n", cadena);
                }
            }
            else if( numero > 0){
                if(declarar(cadena, numero) == OK) fprintf(fout, "%s\n", cadena);
                else fprintf(fout, "-1\t%s\n", cadena);
            }
        }
    }
    
    terminar();
    fclose(fin);
    fclose(fout);
    return 0;
}
