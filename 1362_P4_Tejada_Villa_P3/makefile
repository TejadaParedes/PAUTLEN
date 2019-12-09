GCC = gcc 
FLAGS = -Wall -o

all: pruebaSintactico

pruebaSintactico: pruebaSintactico.c lex.yy.c alfa.tab.c alfa.tab.h
	$(GCC) $(FLAGS) pruebaSintactico pruebaSintactico.c lex.yy.c alfa.tab.c

alfa.tab.h alfa.tab.c: alfa.y
	bison -d alfa.y

lex.yy.c: alfa.l
	flex alfa.l

clean: 
	rm  pruebaSintactico lex.yy.c alfa.tab.h alfa.tab.c