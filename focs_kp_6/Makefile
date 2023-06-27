CC=gcc
LD=gcc
RM=rm -fr
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -g
LDFLAGS=
EXECUTABLE=main person_dump

main: src/main.o person_dump
	$(LD) $(LDFLAGS) src/main.o -o main

person_dump: src/person_dump.o
	$(LD) $(LDFLAGS) src/person_dump.o -o person_dump

src/person_dump.o: src/person_dump.c
	$(CC) $(CCFLAGS) -c src/person_dump.c -o src/person_dump.o

src/main.o: src/main.c
	$(CC) $(CCFLAGS) -c src/main.c -o src/main.o

clean:
	$(RM) src/*.o $(EXECUTABLE)
