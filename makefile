all:p1

file.o: file.h file.c types.h
	gcc -c file.c -Wall -Wextra

main.o: main.c types.h
	gcc -c main.c -Wall -Wextra

p1: file.o main.o
	gcc file.o main.o  -o p1

clean:
	rm -f *.o p1
