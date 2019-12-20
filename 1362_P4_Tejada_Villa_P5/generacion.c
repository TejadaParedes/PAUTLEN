#include "generacion.h"


void escribir_cabecera_bss(FILE* fpasm){

    fprintf(fpasm,"segment .bss\n\t__esp resd 1\n");

    return;
}

void escribir_subseccion_data(FILE* fpasm){

    fprintf(fpasm, "segment .data\n\t_errordivision db \"Estas inetntando dividir un numero entre 0\", 0\n\t_error_indice_vector db \"Indice de vector fuera de rango\", 0\n");

    return;
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){

    if(tamano == 1){
        fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
        return;
    }
    else{
      fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
      /*fprintf(fpasm, "\t_%s%d resd %d\n", nombre, tamano, tamano);*/
      return;
    }

    return;
}

void escribir_segmento_codigo(FILE* fpasm){

    fprintf(fpasm, "segment .text\n\tglobal main\n\textern print_int, print_boolean, print_string,  print_blank, print_endofline, scan_int, scan_boolean\n");

    return;
}

void escribir_inicio_main(FILE* fpasm){

    fprintf(fpasm, "main:\n\tmov dword [__esp], esp\n");

    return;
}

/*CAMBIAR*/
void escribir_fin(FILE* fpasm){

    /*fprintf(fpasm, "final:\n\tpush dword _errordivision\n\tcall print_string\n\tadd esp, 4\nexit:\n\tmov dword esp, [__esp]\n\tret\n");*/
    fprintf(fpasm, "\tjmp near exit\n");
    fprintf(fpasm, "error_division:\n\tpush dword _errordivision\n\tcall print_string\n\tadd esp, 4\n\tcall print_endofline\n\tjmp near exit\n");
    fprintf(fpasm, "error_indice_vector:\n\tpush dword _error_indice_vector\n\tcall print_string\n\tadd esp, 4\n\tcall print_endofline\n\tjmp near exit\n");
    fprintf(fpasm, "exit:\n\tmov dword esp, [__esp]\n\tret\n");
    return;
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){

    if(es_variable){

        fprintf(fpasm, "\tpush dword _%s\n", nombre); /*duda [_%s] o _%s*/
        return;
    }
    else{

        fprintf(fpasm, "\tpush dword %s\n", nombre);
        return;
    }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){

    fprintf(fpasm, "\tpop dword eax\n");

    if(es_variable){

        fprintf(fpasm, "\tmov dword eax, eax\n");

    }
    
    fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);

    return;
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){

  /*fprintf(fpasm, "\tmov dword eax, 0\n\tmov dword ebx, 0\n\tpop dword eax\n\tpop dword ebx\n");*/
  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tadd eax, edx\n\tpush dword eax\n");

  return;

}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tsub eax, edx\n\tpush dword eax\n");

  return;
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\timul edx\n\tpush dword eax\n");

  return;
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){

  /*fprintf(fpasm, "\tpop dword ecx\n\tpop dword eax\n\tcmp ecx, 0\n\tje near error_division\n");*/
  fprintf(fpasm,"\tpop dword ecx\n");

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword ecx, [ecx]\n");
  }

  fprintf(fpasm,"\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  fprintf(fpasm,"\tcdq\n");

  fprintf(fpasm,"\tcmp ecx, 0\n");

  fprintf(fpasm,"\tje near error_division\n");

  fprintf(fpasm, "\tidiv ecx\n\tpush dword eax\n");

  return;
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tor eax, edx\n\tpush dword eax\n");

  return;
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable_2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tand eax, edx\n\tpush dword eax\n");

  return;
}

void cambiar_signo(FILE* fpasm, int es_variable){

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  fprintf(fpasm, "\tneg eax\n\tpush dword eax\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable){
    fprintf(fpasm, "\tmov dword eax , [eax]\n");
  }

  fprintf(fpasm, "\tor eax , eax\n");
  fprintf(fpasm, "\tjz near negar_falso%d\n",cuantos_no);

  fprintf(fpasm, "\tmov dword eax, 0\n");
  fprintf(fpasm, "\tjmp near fin_negacion%d\n",cuantos_no);

  fprintf(fpasm, "\tnegar_falso%d:\n\t mov dword eax, 1\n",cuantos_no);
  fprintf(fpasm, "\tfin_negacion%d:\n\tpush dword eax\n",cuantos_no);

  }

void leer(FILE* fpasm, char* nombre, int tipo){

  if(tipo == ENTERO){
    fprintf(fpasm, "\tpush dword _%s\n\tcall scan_int\n\tadd esp, 4\n", nombre);
    return;
  }
  else{
    fprintf(fpasm, "\tpush dword _%s\n\tcall scan_boolean\n\tadd esp, 4\n", nombre);
    return;
  }

  return ;
}
void escribir(FILE* fpasm, int es_variable, int tipo){

  fprintf(fpasm, "\tpop dword eax\n");

  if(tipo == ENTERO){
    if(es_variable){
      fprintf(fpasm, "\tpush dword [eax]\n");
    }
    else{
      fprintf(fpasm, "\tpush dword eax\n");
    }
    fprintf(fpasm, "\tcall print_int\n");
  }
  else{
    if(es_variable){
      fprintf(fpasm, "\tpush dword [eax]\n");
    }
    else{
      fprintf(fpasm, "\tpush dword eax\n");
    }
    fprintf(fpasm, "\tcall print_boolean\n");
  }

  fprintf(fpasm, "\tadd esp, 4\n\tcall print_endofline\n");

  return ;

}

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tje near igual%d\n\tpush dword 0\n\tjmp near fin_igual%d\nigual%d:\n\tpush dword 1\nfin_igual%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tjne near distinto%d\n\tpush dword 0\n\tjmp near fin_distinto%d\ndistinto%d:\n\tpush dword 1\nfin_distinto%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tjle near menorigual%d\n\tpush dword 0\n\tjmp near fin_menorigual%d\nmenorigual%d:\n\tpush dword 1\nfin_menorigual%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tjge near mayorigual%d\n\tpush dword 0\n\tjmp near fin_mayorigual%d\nmayorigual%d:\n\tpush dword 1\nfin_mayorigual%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tjl near menor%d\n\tpush dword 0\n\tjmp near fin_menor%d\nmenor%d:\n\tpush dword 1\nfin_menor%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

  fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

  if(es_variable1){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  if(es_variable2){
    fprintf(fpasm, "\tmov dword edx, [edx]\n");
  }

  fprintf(fpasm, "\tcmp eax, edx\n\tjg near mayor%d\n\tpush dword 0\n\tjmp near fin_mayor%d\nmayor%d:\n\tpush dword 1\nfin_mayor%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);

  return;
}


void while_inicio(FILE* fpasm, int etiqueta){


  fprintf(fpasm, "inicio_while%d:\n", etiqueta);

  return;
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){


  fprintf(fpasm, "\tpop eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 0\n\tje near fin_while%d\n", etiqueta);
}

void while_fin(FILE* fpasm, int etiqueta){

  fprintf(fpasm, "\tjmp near inicio_while%d\nfin_while%d:\n", etiqueta, etiqueta);

  return;
}

void escribir_elemento_vector(FILE* fpasm, char* nombre, int tamanio, int es_variable){

  fprintf(fpasm, "\tpop dword eax\n");

  if (es_variable)
  {
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }
  
  /*fprintf(fpasm, "\tcmp eax, 0\n\tjl near error_indice_vector\n\tcmp eax, %d-1\n\tjg near error_indice_vector\n\tmov dword edx, _%s%d\n", tamanio, nombre, tamanio);*/
  fprintf(fpasm, "\tcmp eax, 0\n\tjl near error_indice_vector\n\tcmp eax, %d-1\n\tjg near error_indice_vector\n\tmov dword edx, _%s\n", tamanio, nombre);
  fprintf(fpasm, "\tlea eax, [edx + eax*4]\n\tpush dword eax\n");

  return;
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){

  fprintf(fpasm, "\tpop dword ebx\n\tpop dword eax\n");

  if(es_variable){
    fprintf(fpasm, "\tmov dword eax, [eax]\n");
  }

  fprintf(fpasm, "\tmov [ebx], eax\n");

  return;
}

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

  fprintf(fpasm, "\tpop eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 0\n\tje near fin_si%d\n", etiqueta);

  return;
}

void ifthenelse_fin_then( FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\tjmp near fin_sino%d\n\tfin_si%d:\n", etiqueta, etiqueta);

  return;
}

void ifthenelse_fin( FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\tfin_sino%d:\n", etiqueta);
  
  return;
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

  fprintf(fpasm, "\tpop eax\n");

  if (exp_es_variable)
  {
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 0\n\tje near fin_si%d\n", etiqueta);

  return;
  
}

void ifthen_fin(FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\tfin_si%d:\n", etiqueta);

  return;
}

void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc){

  fprintf(fd_asm, "_%s:\n\tpush ebp\n\tmov ebp, esp\n\tsub esp, 4*%d\n", nombre_funcion, num_var_loc);

  return;
}
void retornarFuncion(FILE * fd_asm, int es_variable){

  fprintf(fd_asm, "\tpop eax\n");

  if(es_variable){
    fprintf(fd_asm, "\tmov dword eax, [eax]\n");
  }

  fprintf(fd_asm, "\tmov esp,ebp\n\tpop ebp\n\tret\n");
}
void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){

  int d_ebp;
  d_ebp = 4*( 1 + (num_total_parametros - pos_parametro));

  fprintf(fpasm, "\tlea eax, [ebp + %d]\n\tpush dword eax\n", d_ebp);

  return;
}
void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){

  int d_ebp;
  d_ebp = 4*posicion_variable_local;

  fprintf(fpasm, "\tlea eax, [ebp - %d]\n\tpush dword eax\n", d_ebp);

  return;
}
void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){

  fprintf(fd_asm, "\tpop eax\n");

  if(es_variable){
    fprintf(fd_asm, "\tmov eax, [eax]\n");
  }

  fprintf(fd_asm, "\tpush eax\n");

  return;
}
void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){

  fprintf(fd_asm, "\tcall _%s\n\tadd esp, %d*4\n\tpush dword eax\n", nombre_funcion, num_argumentos);

  return;
}
void limpiarPila(FILE * fd_asm, int num_argumentos){

  fprintf(fd_asm, "\tadd esp, 4*%d\n", num_argumentos);
}