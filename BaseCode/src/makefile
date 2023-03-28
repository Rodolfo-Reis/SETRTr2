# Variables and rules
P=main
Objects= cmdproc.o main.o
CFlags= -g -Wall -O3
CC = gcc

all: $(P)

# Generate app
$(P):$(Objects)
	$(CC) $(CFlags) -o $(P) $(Objects)

# Generate FIFO.o
cmdproc.o: cmdproc.c cmdproc.h
	$(CC) $(CFlags) -c cmdproc.c

# Generate testapp.o
main.o: main.c cmdproc.h
	$(CC) $(CFlags) -c main.c

clean: 
	rm *.o $(P)

