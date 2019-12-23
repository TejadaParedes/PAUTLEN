%{
#include <stdio.h>
#include <string.h>
#include "alfa.h"
#include "y.tab.h"

#define MAXLEN  100
int n_linea = 1;
int n_columna = 1;
int error = 0;
%}
%option noyywrap  
NUMBER    [0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*

%%
"main" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAIN; }
"int" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_INT; }
"boolean" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_BOOLEAN; }
"array" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ARRAY; }
"function" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_FUNCTION; }
"if" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_IF; }
"else" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ELSE; }
"while" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_WHILE; }
"scanf" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_SCANF; }
"printf" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PRINTF; }
"return" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_RETURN; }
";" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PUNTOYCOMA; }
"," { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_COMA; }
"(" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PARENTESISIZQUIERDO; }
")" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_PARENTESISDERECHO; }
"[" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CORCHETEIZQUIERDO; }
"]" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CORCHETEDERECHO; }
"{" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_LLAVEIZQUIERDA; }
"}" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_LLAVEDERECHA; }
"==" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_IGUAL; }
"=" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ASIGNACION; }
"+" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAS; }
"-" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENOS; }
"/" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_DIVISION; }
"*" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_ASTERISCO; }
"&&" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_AND; }
"||" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_OR; }
"!=" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_DISTINTO; }
"!" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_NOT; }
"<=" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENORIGUAL; }
">=" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAYORIGUAL; }
"<" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MENOR; }
">" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_MAYOR; }
"true" { n_columna += yyleng;  fprintf(yyout, ";D:\t%s\n", yytext); return TOK_TRUE; }
"false" { n_columna += yyleng; fprintf(yyout, ";D:\t%s\n", yytext); return TOK_FALSE; }
{IDENTIFICADOR} { if (yyleng<=MAXLEN){ n_columna += yyleng; strcpy(yylval.atributos.lexema, yytext); fprintf(yyout, ";D:\t%s\n", yytext);  return TOK_IDENTIFICADOR; }else{ error = 1; n_columna += yyleng; fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n", n_linea, n_columna,yytext); return TOK_ERROR;} }
{NUMBER} { n_columna += yyleng; yylval.atributos.valor_entero = atoi(yytext); fprintf(yyout, ";D:\t%s\n", yytext); return TOK_CONSTANTE_ENTERA; }
[\n] { n_linea++; n_columna = 0; } /*Salto de linea*/
[ \t]+ { n_columna += yyleng; } /*Espacios, tabuladores*/
. { error = 1; n_columna += yyleng; fprintf(stderr, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n", n_linea, n_columna,yytext); return TOK_ERROR; }
"//".* { } /*Comentarios, que acaban en salto de linea*/

%%

/*int main(){

  return yylex();
}*/