CC = gcc
FLAGS = -Wall -ansi
BS = bison
BFLAGS = -d -y -v
FX = flex
OBJ = alfa.o tablaSimbolos.o tablaHash.o generacion.o y.tab.o lex.yy.o

all: alfa

alfa: $(OBJ)
	$(CC) -o alfa $(OBJ)
 
alfa.o: alfa.c y.tab.h alfa.h
	$(CC) $(FLAGS) -c alfa.c

tablaSimbolos.o: tablaSimbolos.c tablaSimbolos.h
	$(CC) $(FLAGS) -c tablaSimbolos.c

tablaHash.o: tablaHash.c tablaHash.h
	$(CC) $(FLAGS) -c tablaHash.c

generacion.o: generacion.c generacion.h
	$(CC) $(FLAGS) -c generacion.c

y.tab.o: y.tab.h y.tab.c
	$(CC) $(FLAGS) -c y.tab.c

y.tab.h y.tab.c: alfa.y
	$(BS) $(BFLAGS) alfa.y

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c

lex.yy.c: alfa.l y.tab.h
	$(FX) alfa.l

clean:
	rm -rf alfa $(OBJ) lex.yy.c y.tab.h y.tab.c