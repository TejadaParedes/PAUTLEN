CC=gcc
FLAG = -ansi -Wall -pedantic

all: ej1 ej2 ej3 ej4 ej5 ej6 ej7

ej1: ej1.o generacion.o 
	$(CC) -o ej1 ej1.o generacion.o 

ej1.o : ej1.c generacion.h
	$(CC) -g $(FLAG) -c ej1.c

ej2: ej2.o generacion.o 
	$(CC) -o ej2 ej2.o generacion.o 

ej2.o : ej2.c generacion.h
	$(CC) -g $(FLAG) -c ej2.c

ej3: ej3.o generacion.o 
	$(CC) -o ej3 ej3.o generacion.o 

ej3.o : ej3.c generacion.h
	$(CC) -g $(FLAG) -c ej3.c

ej4: ej4.o generacion.o 
	$(CC) -o ej4 ej4.o generacion.o 

ej4.o : ej4.c generacion.h
	$(CC) -g $(FLAG) -c ej4.c

ej5: ej5.o generacion.o 
	$(CC) -o ej5 ej5.o generacion.o 

ej5.o : ej5.c generacion.h
	$(CC) -g $(FLAG) -c ej5.c

ej6: ej6.o generacion.o 
	$(CC) -o ej6 ej6.o generacion.o 

ej6.o : ej6.c generacion.h
	$(CC) -g $(FLAG) -c ej6.c

ej7: ej7.o generacion.o 
	$(CC) -o ej7 ej7.o generacion.o 

ej7.o : ej7.c generacion.h
	$(CC) -g $(FLAG) -c ej7.c

generacion.o : generacion.c generacion.h 
	$(CC) -g $(FLAG) -c generacion.c

ej1_nasm: ej1_nasm.o alfalib.o 
	$(CC) -m32 -o ej1_nasm ej1_nasm.o alfalib.o

ej1_nasm.o: ej1_nasm.asm
	nasm -g -o ej1_nasm.o -f elf32 ej1_nasm.asm

ej2_nasm: ej2_nasm.o alfalib.o 
	$(CC) -m32 -o ej2_nasm ej2_nasm.o alfalib.o

ej2_nasm.o: ej2_nasm.asm
	nasm -g -o ej2_nasm.o -f elf32 ej2_nasm.asm

ej3_nasm: ej3_nasm.o alfalib.o 
	$(CC) -m32 -o ej3_nasm ej3_nasm.o alfalib.o

ej3_nasm.o: ej3_nasm.asm
	nasm -g -o ej3_nasm.o -f elf32 ej3_nasm.asm

ej4_nasm: ej4_nasm.o alfalib.o 
	$(CC) -m32 -o ej4_nasm ej4_nasm.o alfalib.o

ej4_nasm.o: ej4_nasm.asm
	nasm -g -o ej4_nasm.o -f elf32 ej4_nasm.asm

ej5_nasm: ej5_nasm.o alfalib.o 
	$(CC) -m32 -o ej5_nasm ej5_nasm.o alfalib.o

ej5_nasm.o: ej5_nasm.asm
	nasm -g -o ej5_nasm.o -f elf32 ej5_nasm.asm

ej6_nasm: ej6_nasm.o alfalib.o 
	$(CC) -m32 -o ej6_nasm ej6_nasm.o alfalib.o

ej6_nasm.o: ej6_nasm.asm
	nasm -g -o ej6_nasm.o -f elf32 ej6_nasm.asm

ej7_nasm: ej7_nasm.o alfalib.o 
	$(CC) -m32 -o ej7_nasm ej7_nasm.o alfalib.o

ej7_nasm.o: ej7_nasm.asm
	nasm -g -o ej7_nasm.o -f elf32 ej7_nasm.asm

run_ej1: ej1
	./ej1 ej1_nasm.asm

run_ej2: ej2
	./ej2 ej2_nasm.asm

run_ej3: ej3
	./ej3 ej3_nasm.asm

run_ej4: ej4
	./ej4 ej4_nasm.asm

run_ej5: ej5
	./ej5 ej5_nasm.asm

run_ej6: ej6
	./ej6 ej6_nasm.asm

run_ej7: ej7
	./ej7 ej7_nasm.asm

clean:
	rm -f *.o *.asm ej1 ej2 ej3 ej4 ej5 ej6 ej7 ej1_nasm ej2_nasm ej3_nasm ej4_nasm ej5_nasm ej6_nasm ej7_nasm

