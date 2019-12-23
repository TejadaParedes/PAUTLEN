%{

#include <stdio.h>
#include <string.h> 
#include "alfa.h"  

int yylex();
void yyerror();
extern FILE* yyout;
extern int n_linea;
extern int n_columna;
extern int error;

TIPO tipo;
CLASE clase;
int tam_vector;

INFO_SIMBOLO *is;

INFO_SIMBOLO is_aux;

int num_no = 0;
int num_cmp = 0;
int num_cond = 0;
int num_loops = 0;
int idx_variable_local = 0;
int num_local_variables = 0;
int num_parametros = 0;
int idx_parametro = 0;
int is_function = 0;
int is_call_function = 0;
int parametros = 0;
int existe_return = 0;

%}

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

%token TOK_IGUAL
%token TOK_AND
%token TOK_OR
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token TOK_NOT

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

%token TOK_TRUE
%token TOK_FALSE
%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_IDENTIFICADOR

%token TOK_ERROR

%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> constante
%type <atributos> exp

%type <atributos> if_statement
%type <atributos> if_statement_sentencias

%type <atributos> while_star
%type <atributos> while_end

%type <atributos> elemento_vector

%type <atributos> funct_name 
%type <atributos> funct_name_params

%type <atributos> funct_call_star

%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND
%right MENOSU TOK_NOT

%union{
    TIPO_ATRIBUTOS atributos;
}
%%

programa: TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escribirTabla funciones escribirMain sentencias TOK_LLAVEDERECHA {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
;

declaraciones: declaracion {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
    | declaracion declaraciones {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
;

declaracion: clase identificadores TOK_PUNTOYCOMA {fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
;

clase: clase_escalar {clase = ESCALAR; fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");}
    | clase_vector {clase = VECTOR; fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");}
;

clase_escalar: tipo {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");}
;

tipo: TOK_INT {tipo = ENTERO; fprintf(yyout, ";R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {tipo = BOOLEANO; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");}
;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO {
    tam_vector = $4.valor_entero;
    if(tam_vector < 1 || tam_vector > MAX_TAMANIO_VECTOR){
        fprintf(stderr, "****Error semantico en linea %d: El tamanyo del vector %s excede los limites permitidos (1,64).\n", n_linea, $4.lexema);
        return -1;
    }
    fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");}
;

identificadores: identificador {fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");}
    | identificador TOK_COMA identificadores {fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
;

funciones: funcion funciones {fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
    | {fprintf(yyout, ";R21:\t<funciones> ::=\n");}
;

funct_name: TOK_FUNCTION tipo TOK_IDENTIFICADOR{
    existe_return = 0;
    is_function = 1;
    is = BuscarSimbolo($3.lexema);
    if(is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.\n", n_linea);
        return -1;
    }

    is_aux.lexema = $3.lexema;
    is_aux.categoria = FUNCION;
    is_aux.tipo = tipo;
    is_aux.clase = ESCALAR;

    strcpy($$.lexema, $3.lexema);
    $$.tipo = tipo;

    declararFuncion($3.lexema, &is_aux);
    idx_variable_local = 0;
    num_local_variables = 0;
    idx_parametro = 0;
    num_parametros = 0;
}

funct_name_params: funct_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion{

    is = BuscarSimbolo($1.lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is->adicional1 = num_parametros;
    strcpy($$.lexema, $1.lexema);
    $$.tipo = $1.tipo;
    declarar_Funcion(yyout, $1.lexema, num_local_variables);
}

funcion: funct_name_params sentencias TOK_LLAVEDERECHA {

    if(!existe_return){
        fprintf(stderr, "****Error semantico en lin %d: Funcion %s sin sentencia de retorno.", n_linea, $1.lexema);
        return -1;
    }
    cerrarFuncion();
    funcionFin(yyout);
    is = BuscarSimbolo($1.lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is->adicional1 = num_parametros; 
    is_function = 0;
    fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ){ <declaracion_funcion> <sentencias> }\n");}


parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
    | {fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n");}
;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>\n");}
    | {fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");}
;

parametro_funcion: tipo pfid {
    num_parametros++;
    idx_parametro++;
    fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
;

pfid: TOK_IDENTIFICADOR{
    is = BuscarSimbolo($1.lexema);
    if(is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.\n", n_linea);
        return -1;
    }
    is_aux.lexema = $1.lexema;
    is_aux.categoria = PARAMETRO;
    is_aux.clase = ESCALAR;
    is_aux.tipo = tipo;
    is_aux.adicional1 = num_parametros;
    declarar($1.lexema, &is_aux);
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

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp {
    is = BuscarSimbolo($1.lexema);
    if(!is){
       fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, $1.lexema);
        return -1; 
    }
    else{
        if(is->categoria == FUNCION){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(is->clase == VECTOR){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(is->tipo != $3.tipo){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(!usoGlobal($1.lexema)){
            if(is->categoria == PARAMETRO) asignar_local(yyout, num_parametros-is->adicional1+1, $3.es_direccion);
            else asignar_local(yyout, -(is->adicional1+1), $3.es_direccion);
        }
        else{
            asignar(yyout, $1.lexema, $3.es_direccion);
            fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
        }

    }
}
    | elemento_vector TOK_ASIGNACION exp {
        if($1.tipo != $3.tipo){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        asignar_vector(yyout, $3.es_direccion);
        fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
;

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
    is = BuscarSimbolo($1.lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, $1.lexema);
        return -1;
    }
    else if(is->clase == ESCALAR){
        fprintf(stderr, "****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", n_linea);
        return -1;
    }

    $$.tipo = is->tipo;
    $$.es_direccion = 1;

    if($3.tipo != ENTERO){
        fprintf(stderr, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", n_linea);
        return -1;
    }

    escribir_elemento_vector(yyout, $1.lexema, is->adicional1, $3.es_direccion);

    fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> = [ <exp> ]\n");}
;

condicional: if_statement TOK_LLAVEDERECHA {
    
    ifthenelse_fin(yyout, $1.etiqueta); /***---*/
    fprintf(yyout, ";R50:\t<condicional> ::= <identificador> = if( <exp> ){ <sentencias> }\n");}
    | if_statement TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
        ifthenelse_fin(yyout, $1.etiqueta);
        fprintf(yyout, ";R51:\t<condicional> ::= <identificador> = if( <exp> ){ <sentencias> } else { <sentencias> }\n");}
;

if_statement_sentencias: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA{
    if($3.tipo != BOOLEANO){
        fprintf(stderr, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", n_linea);
        return -1;
    }

    $$.etiqueta = num_cond++;

    ifthen_inicio(yyout, $3.es_direccion, $$.etiqueta);
}

if_statement: if_statement_sentencias sentencias{
    $$.etiqueta = $1.etiqueta;
    ifthenelse_fin_then(yyout, $$.etiqueta);
}

bucle: while_end sentencias TOK_LLAVEDERECHA {
    while_fin(yyout, $1.etiqueta);
    fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
;

while_star: TOK_WHILE TOK_PARENTESISIZQUIERDO {

    $$.etiqueta = num_loops++;
    while_inicio(yyout, $$.etiqueta);
}

while_end: while_star exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA{
    if($2.tipo != BOOLEANO){
        fprintf(yyout, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", n_linea);
        return -1;
    }

    $$.etiqueta = $1.etiqueta;
    while_exp_pila(yyout, $2.es_direccion, $$.etiqueta);
};

lectura: TOK_SCANF TOK_IDENTIFICADOR {
    is = BuscarSimbolo($2.lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, $2.lexema);
        return -1;
    }
    leer(yyout, $2.lexema, is->tipo);
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");}
;

escritura: TOK_PRINTF exp {
    escribir(yyout, !($2.es_direccion), $2.tipo);
    fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");}
;

retorno_funcion: TOK_RETURN exp {
    if(!is_function){
        fprintf(stderr, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una función.\n", n_linea);
        return -1;
    }
    existe_return = 1;
    retornarFuncion(yyout, $2.es_direccion);
    fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
;

exp: exp TOK_MAS exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        sumar(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = ENTERO;
        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
    }
    | exp TOK_MENOS exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        restar(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = ENTERO;
        fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
    }
    | exp TOK_DIVISION exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        dividir(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = ENTERO;
        fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
    }
    | exp TOK_ASTERISCO exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        multiplicar(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = ENTERO;
        fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
    }
    | TOK_MENOS exp %prec MENOSU{
        if($2.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        cambiar_signo(yyout, $2.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = ENTERO;
        fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
    }
    | exp TOK_AND exp {
        if($1.tipo != BOOLEANO || $3.tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        y(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = BOOLEANO;
        fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    }
    | exp TOK_OR exp {
        if($1.tipo != BOOLEANO || $3.tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        o(yyout, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = BOOLEANO;
        fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
    }
    | TOK_NOT exp {
        if($2.tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        no(yyout, $2.es_direccion, num_no++);
        $$.es_direccion = 0;
        $$.tipo = BOOLEANO;
        fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
    }
    | TOK_IDENTIFICADOR {
        strcpy($$.lexema, $1.lexema);
        is = BuscarSimbolo($1.lexema);
        if(!is){
            fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, $1.lexema);
            return -1; 
        }
        if(!usoGlobal($1.lexema)){
            if(is->categoria == PARAMETRO){
                escribir_operando_funcion(yyout, (num_parametros - is->adicional1)+1);
            }
            else{
                escribir_operando_funcion(yyout, -(is->adicional1+1));
            }
        }else{

            escribir_operando(yyout, $1.lexema, 1);
        }
        
        $$.es_direccion = 1;
        $$.tipo = is->tipo;
        
        fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");
    }
    | constante {
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
        escribir_operando(yyout, $1.lexema, 0);
        fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
    }
    | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        $$.tipo = $2.tipo;
        $$.es_direccion = $2.es_direccion;
        fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
    }
    | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
        fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
    }
    | elemento_vector {
        fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");
    }
    | funct_call_star lista_expresiones TOK_PARENTESISDERECHO {
        is = BuscarSimbolo($1.lexema);
        if(is->adicional1 != parametros){
            fprintf(stderr, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", n_linea);
            return -1;
        }
        is_call_function = 0;
        $$.tipo = is->tipo;
        llamarFuncion(yyout, $1.lexema, is->adicional1);
        fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
;

funct_call_star: TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO{
    if(is_call_function){
        fprintf(stderr, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", n_linea);
        return -1;
    }

    is_call_function = 1;
    parametros = 0;
    strcpy($$.lexema, $1.lexema);
}

lista_expresiones: expf resto_lista_expresiones {
    is_call_function = 0;
    parametros++;
    fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
    | {
        is_call_function = 0;
        fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");}
;

resto_lista_expresiones: TOK_COMA expf resto_lista_expresiones {
    parametros++;
    fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
    | {fprintf(yyout, ";R92:\t<lista_expresiones> ::=\n");}
;

expf: exp{
    if($1.es_direccion){
        cambiar_a_valor(yyout);
    }
}

comparacion: exp TOK_IGUAL exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        igual(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
    }
    | exp TOK_DISTINTO exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        distinto(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
    }
    | exp TOK_MENORIGUAL exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        menor_igual(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
    }
    | exp TOK_MAYORIGUAL exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        mayor_igual(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
    }
    | exp TOK_MENOR exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        menor(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
    }
    | exp TOK_MAYOR exp {
        if($1.tipo != ENTERO || $3.tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        mayor(yyout, $1.es_direccion, $3.es_direccion, num_cmp);
        fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
    }
;

constante: constante_logica {
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
        strcpy($$.lexema, $1.lexema);
        fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");
    }
    | constante_entera {
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
        strcpy($$.lexema, $1.lexema);
        fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
    }
;

constante_logica: TOK_TRUE {
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
        strcpy($$.lexema, "1");
        fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
    }
    | TOK_FALSE {
        $$.tipo = BOOLEANO;
        $$.es_direccion = 0;
        strcpy($$.lexema, "0");
        fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
    }
;

constante_entera: TOK_CONSTANTE_ENTERA {
    $$.tipo = ENTERO;
    $$.es_direccion = 0;
    fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");}
;


identificador: TOK_IDENTIFICADOR {
    is = BuscarSimbolo($1.lexema);
    if((is && !is_function) || (is && EsLocal($1.lexema))){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is_aux.lexema = $1.lexema;
    is_aux.categoria = VARIABLE;
    is_aux.clase = clase;
    is_aux.tipo = tipo;
    if(clase == VECTOR) is_aux.adicional1 = tam_vector;
    else is_aux.adicional1 = 1;

    if(is_function){
        if(clase == VECTOR){
            fprintf(stderr, "****Error semantico en lin %d: Variable local de tipo no escalar.\n", n_linea);
            return -1;
        }
        is_aux.adicional1 = num_local_variables;
        num_local_variables++;
        idx_variable_local++;
    }
    else declarar_variable(yyout, $1.lexema, tipo, is_aux.adicional1);

    declarar($1.lexema, &is_aux);

    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
;

escribirTabla: {escribir_segmento_codigo(yyout);}

escribirMain: {escribir_inicio_main(yyout);}

%%


void yyerror(const char* s) {
    if(!error){
        fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", n_linea, n_columna);
    }
    error = 0;
}