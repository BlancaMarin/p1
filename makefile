all:p1

file.o: file.h file.c types.h
	gcc -c file.c -Wall -Wextra


arxius.o: arxius.h arxius.c types.h
	gcc -c arxius.c -Wall -Wextra

connect.o: connect.h connect.c types.h
	gcc -c connect.c -Wall -Wextra

main.o: main.c types.h arxius.h connect.h file.h
	gcc -c main.c -Wall -Wextra


p1: file.o arxius.o connect.o main.o
	gcc file.o arxius.o connect.o main.o -o McGruder

clean:
	rm -f *.o p1
