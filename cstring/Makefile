output: main.o cstring.o
	gcc -o str main.o cstring.o
	del *.o
	str

main.o: main.c
	gcc -c main.c

cstring.o: string/cstring.c
	gcc -c string/cstring.c