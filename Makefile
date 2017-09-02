partialKey: main.o Derive_The_Key.o
	gcc -o partialKey main.o Derive_The_Key.o

main.o: main.c
	gcc -c main.c

Derive_The_Key.o: Derive_The_Key.c
	gcc -c Derive_The_Key.c -lm

clear:
	rm *.o partialKey
