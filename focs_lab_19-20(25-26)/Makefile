CC=gcc
CFLAGS=-g -c -Wall -pedantic --std=c99

NAME=main
HEADERS=headers/sort.h headers/queue.h headers/header.h

all: $(NAME)

$(NAME): main.o queue.o sort.o
	$(CC) main.o queue.o sort.o -o $(NAME)

main.o: src/main.c $(HEADERS)
	$(CC) $(CFLAGS) src/main.c

queue.o: src/queue.c $(HEADERS)
	$(CC) $(CFLAGS) src/queue.c

sort.o: src/sort.c $(HEADERS)
	$(CC) $(CFLAGS) src/sort.c

clean:
	rm -rf *.o $(NAME)

