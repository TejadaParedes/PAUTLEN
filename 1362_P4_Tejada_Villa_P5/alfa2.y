%{
#include <stdio.h>
#include <string.h>
#include "alfa.h"

int yylex();
void yyerror();
extern FILE * yyout;
extern long yylin;
extern long yycol;
extern int yymorph;

TIPO tipo_actual;
CLASE clase_actual;
int tamano_vector_actual;

INFO_SIMBOLO* read;

INFO_SIMBOLO inserta;

int cuantos_no=0;
int cuantas_comparaciones=0;
int cuantos_condicionales=0;
int cuantos_bucles=0;
int pos_variable_local_actual=0;
int num_variables_locales_actual=0;
int num_parametros_actual = 0;
int pos_parametro_actual = 0;
int es_funcion=0;
int es_llamada=0;
int params = 0;
int hay_return = 0;
%}

/* Palabras reservadas */
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

/* Símbolos */
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

/* Identificadores  */
%token <atributos> TOK_IDENTIFICADOR

/* Constantes */
%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

/* Errores */
%token TOK_ERROR

%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> constante
%type <atributos> exp

%type <atributos> if_exp
%type <atributos> if_exp_sentencias

%type <atributos> while
%type <atributos> while_exp

%type <atributos> elemento_vector

%type <atributos> fn_name
%type <atributos> fn_declaration

%type <atributos> call_func

%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND
%right MENOSU TOK_NOT

%union {
  tipo_atributos atributos;
}
%%

programa: TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escribirTabla funciones escribirMain sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
        ;

declaraciones: declaracion {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
             | declaracion declaraciones {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
             ;

declaracion: clase identificadores TOK_PUNTOYCOMA {/* Llamar a la tabla de simbolos*/ fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
           ;

clase: clase_escalar {fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual=ESCALAR;}
     | clase_vector {fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n"); clase_actual=VECTOR;}
     ;

clase_escalar: tipo {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");}
             ;

tipo: TOK_INT {tipo_actual=ENTERO; fprintf(yyout, ";R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {tipo_actual=BOOLEANO; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");}
    ;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {
  tamano_vector_actual = $4.valor_numerico; 
  if(tamano_vector_actual<1 || tamano_vector_actual > MAX_TAMANIO_VECTOR) {
    fprintf(stderr, "****Error semantico en lin %ld: El tamanyo del vector excede los limites permitidos (1,64).\n", yylin);
    return -1;
  }
  fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
}
            ;

identificadores: identificador {fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");}
               | identificador TOK_COMA identificadores {fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
               ;

funciones: funcion funciones {fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
         | {fprintf(yyout, ";R21:\t<funciones> ::=\n");}
         ;

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR {
    hay_return = 0;
    es_funcion=1;
    read = BuscarSimbolo($3.nombre);
    if(read != NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
      return -1;
    }

    inserta.lexema = $3.nombre;
    inserta.categoria = FUNCION;
    inserta.clase = ESCALAR; /* ? */
    inserta.tipo = tipo_actual;

    strcpy($$.nombre, $3.nombre);
    $$.tipo = tipo_actual;

    DeclararFuncion($3.nombre, &inserta);
    pos_variable_local_actual=0;
    num_variables_locales_actual=0;
    num_parametros_actual = 0;
    pos_parametro_actual = 0;
}

fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
  /* Actualizar atributo num_parametros */
    read = BuscarSimbolo($1.nombre);
    if(read == NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
      return -1;
    }
    read->adicional1 = num_parametros_actual;
    strcpy($$.nombre, $1.nombre);
    $$.tipo = $1.tipo;
    declarar_funcion(yyout, $1.nombre, num_variables_locales_actual);
} 

funcion: fn_declaration sentencias TOK_LLAVEDERECHA {
  if(!hay_return) {
    fprintf(stderr, "****Error semantico en lin %ld: Funcion %s sin sentencia de retorno.\n", yylin, $1.nombre);
    return -1;
  }
  CerrarFuncion();
  fin_funcion(yyout);
  read = BuscarSimbolo($1.nombre);
  if(read == NULL) {
      /* TODO */
      fprintf(stderr, "****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
      return -1;
  }
  read->adicional1 = num_parametros_actual;
  es_funcion = 0;
  fprintf(yyout, ";R22:\t<funcion> ::=function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");}

parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                  | {fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n");}
                  ;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                        | {fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");}
                        ;

parametro_funcion: tipo idpf {
  num_parametros_actual++;
  pos_parametro_actual++;
  fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
                 ;

idpf : TOK_IDENTIFICADOR {
    read = BuscarSimbolo($1.nombre);
    if(read != NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
      return -1;
    }
    inserta.lexema = $1.nombre;
    inserta.categoria = PARAMETRO;
    inserta.clase = ESCALAR;
    inserta.tipo = tipo_actual;
    inserta.adicional1 = num_parametros_actual;

    Declarar($1.nombre, &inserta);
}

declaraciones_funcion: declaraciones {fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                     | {fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");}
                     ;

sentencias: sentencia {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");}
          | sentencia sentencias {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
          ;

sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
         | bloque {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");}
         ;

sentencia_simple: asignacion {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                | lectura {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
                | escritura {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
                | retorno_funcion {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
                ;

bloque: condicional {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
      | bucle {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");}
      ;

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp  {
    read = BuscarSimbolo($1.nombre);
    if(read==NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", yylin, $1.nombre);
      return -1;
    } else {
      if(read->categoria == FUNCION) {
        fprintf(stderr, "****Error semantico en lin %ld: Asignacion incompatible.\n", yylin);
        return -1;
      }
      if(read->clase == VECTOR) {
        fprintf(stderr, "****Error semantico en lin %ld: Asignacion incompatible.\n", yylin);
        return -1;
      }
      if(read->tipo != $3.tipo) {
        fprintf(stderr, "****Error semantico en lin %ld: Asignacion incompatible.\n", yylin);
        return -1;
  
        }
      if (UsoGlobal($1.nombre) == NULL) {
      /* Estamos en una funcion y la variable es local */
        if(read->categoria == PARAMETRO) {
          // REVISAR
          asignar_local(yyout, (num_parametros_actual-read->adicional1+1), $3.es_direccion?0:1);
        } else {
          asignar_local(yyout, -(read->adicional1+1), $3.es_direccion?0:1);
        }

      } else {
        asignar(yyout, $1.nombre, $3.es_direccion?0:1);
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
  }
}

          | elemento_vector TOK_ASIGNACION exp {
            if($1.tipo != $3.tipo) {
              fprintf(stderr, "****Error semantico en lin %ld: Asignacion incompatible.\n", yylin);
              return -1;
            }
            asignar_vector(yyout, $3.es_direccion?0:1);
            fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
          ;

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
  read = BuscarSimbolo($1.nombre);
  if(read == NULL) {
    fprintf(stderr, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", yylin, $1.nombre);
    return -1;
  }  
  if(read->categoria == FUNCION) { /***REVISAR*/
    fprintf(stderr,"****Error semantico en lin %ld: Identificador no valido\n", yylin);
    return -1;  
  }  
  if(read->clase == ESCALAR) {
    fprintf(stderr, "****Error semantico en lin %ld: Intento de indexacion de una variable que no es de tipo vector.\n", yylin);
    return -1;
  }
  $$.tipo = read->tipo;  
  $$.es_direccion = 1;
  if($3.tipo != ENTERO) {
    fprintf(stderr, "****Error semantico en lin %ld: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", yylin);
    return -1;
  }
  escribir_operando_array(yyout, $1.nombre, $3.es_direccion?0:1, read->adicional1);

  fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
               ;

condicional: if_exp_sentencias TOK_LLAVEDERECHA {
  etiqueta_final_condicional_compuesto(yyout, $1.etiqueta);
  fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
}
           | if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
            etiqueta_final_condicional_compuesto(yyout, $1.etiqueta);
            fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
           ;

if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
    if($3.tipo != BOOLEANO) {
      fprintf(stderr, "****Error semantico en lin %ld: Condicional con condicion de tipo int.\n", yylin);
      return -1;
    }
    $$.etiqueta = cuantos_condicionales++;
    inicio_condicional(yyout, $3.es_direccion?0:1, $$.etiqueta);
  }

if_exp_sentencias:  if_exp sentencias {
  $$.etiqueta = $1.etiqueta;
  sino_condicional(yyout, $$.etiqueta);

}


bucle: while_exp sentencias TOK_LLAVEDERECHA {
  etiqueta_final_while(yyout, $1.etiqueta);
  fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
     ;

while: TOK_WHILE TOK_PARENTESISIZQUIERDO {
  $$.etiqueta = cuantos_bucles++;
  etiqueta_inicio_while(yyout, $$.etiqueta);
}

while_exp: while exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA {
  if($2.tipo != BOOLEANO) {
    fprintf(stderr, "****Error semantico en lin %ld: Bucle con condicion de tipo int.\n", yylin);
    return -1;
  }

  $$.etiqueta = $1.etiqueta;
  inicio_bucle(yyout, $2.es_direccion?0:1, $$.etiqueta);
};

lectura: TOK_SCANF TOK_IDENTIFICADOR {
    read = BuscarSimbolo($2.nombre);
    if(read == NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", yylin, $2.nombre);
      return -1;
    }
    leer(yyout, $2.nombre, read->tipo); 
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
};

escritura: TOK_PRINTF exp {
    escribir(yyout, !($2.es_direccion), ($2.tipo));

    fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");}
         ;

retorno_funcion: TOK_RETURN exp {
  if(!es_funcion) {
    fprintf(stderr, "****Error semantico en lin %ld: Sentencia de retorno fuera del cuerpo de una funcion.\n", yylin);
    return -1;
  }

  hay_return = 1;
  retorno_funcion(yyout, $2.es_direccion?0:1);
  fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
               ;

exp: exp TOK_MAS exp {
  if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
    fprintf(stderr, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
    return -1;
  }
  sumar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
  $$.tipo = ENTERO;

  fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
}

   | exp TOK_MENOS exp {
  if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
    fprintf(stderr, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
    return -1;
  }
  $$.tipo = ENTERO;
  restar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
}

   | exp TOK_DIVISION exp {
  if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
    /** ERROR **/
    fprintf(stderr, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
    return -1;
  }
  $$.tipo = ENTERO;
  dividir(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
}

   | exp TOK_ASTERISCO exp {
  if($1.tipo!=ENTERO || $3.tipo != ENTERO) {
    fprintf(stderr, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
    return -1;
  }
  $$.tipo = ENTERO;
  multiplicar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
}

   | TOK_MENOS exp %prec MENOSU {
    if($2.tipo!=ENTERO) {
      fprintf(stderr, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", yylin);
      return -1; 
    }
    $$.tipo = ENTERO;
    cambiar_signo(yyout, $2.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
}
   | exp TOK_AND exp {
    if($1.tipo!=BOOLEANO || $3.tipo != BOOLEANO) {
      fprintf(stderr, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", yylin);
      return -1;
    }
    $$.tipo = BOOLEANO;
    y(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
}
   | exp TOK_OR exp {
    if($1.tipo!=BOOLEANO || $3.tipo != BOOLEANO) {
      fprintf(stderr, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", yylin);
      return -1;
    }
    $$.tipo = BOOLEANO;
    o(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
  }
   | TOK_NOT exp {
    if($2.tipo!=BOOLEANO) {
      fprintf(stderr, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", yylin);
      return -1;
    }
    $$.tipo = BOOLEANO;
    no(yyout, $2.es_direccion?0:1, cuantos_no++);
    $$.es_direccion = 0;
    fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
}
   | TOK_IDENTIFICADOR {
    strcpy($$.nombre, $1.nombre);
    read = BuscarSimbolo($1.nombre);
    if(read == NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", yylin, $1.nombre);
      return -1;
    }
    if (UsoGlobal($1.nombre) == NULL) {
      /* Estamos en una funcion y la variable es local */
      if(read->categoria == PARAMETRO) {
        escribir_operando_funcion(yyout, (num_parametros_actual-read->adicional1)+1);
      } else {
        escribir_operando_funcion(yyout, -(read->adicional1+1));
      }

    } else {
      if(read->categoria==FUNCION) {
        /* NUNCA SUCEDE */
        fprintf(stderr,"Identificador no valido\n");
        return -1;
    }
    
    escribir_operando(yyout, $1.nombre, 1);

    }
    $$.es_direccion = 1;
    $$.tipo = read->tipo;

    fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

  }
   | constante {
    $$.tipo =$1.tipo;
    $$.es_direccion = $1.es_direccion;
    escribir_operando(yyout, $1.nombre, 0);
    fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
  }
   | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
    $$.tipo =$2.tipo;
    $$.es_direccion = $2.es_direccion;
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
  }
   | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
    $$.tipo =BOOLEANO;
    $$.es_direccion = 0;
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
    fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
  }
   | elemento_vector {
    fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");

  }
   |  call_func lista_expresiones TOK_PARENTESISDERECHO {
    read = BuscarSimbolo($1.nombre);
    if(read == NULL) {
      fprintf(stderr, "****Error semantico en lin %ld: Funcion no declarada (%s).\n", yylin, $1.nombre);
      return -1;
    }
    if(read->categoria != FUNCION){
      fprintf(stderr, "****Error semantico en lin %ld: El identificador no es una funcion (%s).\n", yylin, $1.nombre);
      return -1;
    }
    if(read->adicional1 != params) {
      fprintf(stderr, "****Error semantico en lin %ld: Numero incorrecto de parametros en llamada a funcion.\n", yylin);
      return -1;
    }
    es_llamada = 0;
    $$.tipo = read->tipo;
    llamar_funcion(yyout, $1.nombre, read->adicional1);

    fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
   ;

call_func: TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO {
  if(es_llamada) {
    fprintf(stderr, "****Error semantico en lin %ld: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", yylin);
    return -1;
  }
  es_llamada = 1;
  params = 0;
  strcpy($$.nombre, $1.nombre);
}
lista_expresiones: expf resto_lista_expresiones {
  es_llamada = 0;
  params++;
  
  fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
                 |   {
                  es_llamada = 0;
                  fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");}
                 ;

resto_lista_expresiones: TOK_COMA expf resto_lista_expresiones {
  params++;

  fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
                       |   {fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");}
                       ;
expf: exp {
  if($1.es_direccion) {
    cambiar_a_valor(yyout);
  }
}

comparacion: exp TOK_IGUAL exp {
  if($1.tipo != ENTERO || $3.tipo != ENTERO) {
    fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
    return -1;
  }
  igual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++);
  /*$$.tipo = BOOLEANO;
  $$.es_direccion = 0;*/
  fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
}
           | exp TOK_DISTINTO exp {
            if($1.tipo != ENTERO || $3.tipo != ENTERO) {
              fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
              return -1;
            }
            distinto(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++); 
            fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
            }
           | exp TOK_MENORIGUAL exp {
            if($1.tipo != ENTERO || $3.tipo != ENTERO) {
              fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
              return -1;
            }
            menorigual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++);
            fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
           | exp TOK_MAYORIGUAL exp {
            if($1.tipo != ENTERO || $3.tipo != ENTERO) {
              fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
              return -1;
            }
            mayorigual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++);
            fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
           | exp TOK_MENOR exp {
            if($1.tipo != ENTERO || $3.tipo != ENTERO) {
              fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
              return -1;
            }
            menor(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++);
            fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");}
           | exp TOK_MAYOR exp {
            if($1.tipo != ENTERO || $3.tipo != ENTERO) {
              fprintf(stderr, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", yylin);
              return -1;
            }
            mayor(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, cuantas_comparaciones++);
            fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");}
           ;

constante: constante_entera {$$.tipo = $1.tipo; $$.es_direccion = $1.es_direccion; strcpy($$.nombre, $1.nombre); fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");}
         | constante_logica {$$.tipo = $1.tipo; $$.es_direccion = $1.es_direccion; strcpy($$.nombre, $1.nombre); fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");}
         ;

constante_logica: TOK_TRUE {$$.tipo = BOOLEANO; $$.es_direccion = 0; strcpy($$.nombre,"1"); fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");}
                | TOK_FALSE {$$.tipo = BOOLEANO; $$.es_direccion = 0; strcpy($$.nombre,"0"); fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");}
                ;

constante_entera: TOK_CONSTANTE_ENTERA { $$.tipo = ENTERO; $$.es_direccion = 0; fprintf(yyout, ";R104:\t<constante_entera> ::= <numero>\n");}
                ;

identificador: TOK_IDENTIFICADOR {
    read = BuscarSimbolo($1.nombre);
    if((read != NULL && !es_funcion) || (read != NULL && EsLocal($1.nombre)) ) {
      fprintf(stderr, "****Error semantico en lin %ld: Declaracion duplicada.\n", yylin);
      return -1;
    }

    inserta.lexema = $1.nombre;
    inserta.categoria = VARIABLE;
    inserta.clase = clase_actual;
    inserta.tipo = tipo_actual;
    if(clase_actual == VECTOR) {
      inserta.adicional1 = tamano_vector_actual;

    } else {
      inserta.adicional1 = 1;
    }
    if(es_funcion) {
      if(clase_actual == VECTOR) {
        fprintf(stderr, "****Error semantico en lin %ld: Variable local de tipo no escalar.\n", yylin);
        return -1;
      }
      inserta.adicional1 = num_variables_locales_actual;
      num_variables_locales_actual++;
      pos_variable_local_actual++;
    } else {
      declarar_variable(yyout, $1.nombre, tipo_actual,  inserta.adicional1);
        
    }
    Declarar($1.nombre, &inserta);


    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
             ;

 
escribirTabla: { /* Escribir tabla de simbolos a nasm */ escribir_segmento_codigo(yyout); }

escribirMain: { escribir_inicio_main(yyout);}

%%

void yyerror(const char * s) {
    if(!yymorph) {
        printf("****Error sintactico en [lin %ld, col %ld]\n", yylin, yycol);
    }
}