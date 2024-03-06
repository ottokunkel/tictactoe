

CC=gcc

CFlags=

tictactoe: main.o
	$(CC) -o tictactoe main.o

main.o: main.c
	$(CC) -c main.c


