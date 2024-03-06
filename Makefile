

CC = gcc

CFlags = -g -Wall

tictactoe: main.o
	$(CC) -o tictactoe main.o

main.o: main.c
	$(CC) -c main.c

clean:
	rm -f *.o tictactoe
