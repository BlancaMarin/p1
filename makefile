all:p1

file.o: file.h file.c types.h
	gcc -c file.c -Wall -Wextra


arxius.o: arxius.h arxius.c types.h
	gcc -c arxius.c -Wall -Wextra

main.o: main.c types.h arxius.h file.h
	gcc -c main.c -Wall -Wextra


p1: file.o arxius.o main.o
	gcc file.o arxius.o main.o -o p1

clean:
	rm -f *.o p1
