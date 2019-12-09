CC = gcc
EXE = pruebaTablaSimbolos
OBJ = pruebaTablaSimbolos.o tablaSimbolos.o tablaHash.o

all: ${EXE}

${EXE}:%: ${OBJ}
	$(CC) -o $@ $^ -Wall

%.o: %c
	$(CC) -o $@ -c $< -Wall

clean:
	rm *.o pruebaTablaSimbolos