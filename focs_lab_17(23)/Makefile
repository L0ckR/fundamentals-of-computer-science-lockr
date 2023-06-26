CC=gcc
RM=rm -fr
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
SOURCES= src/stack.c src/tree.c src/main.c src/tree_func.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)

debug: CFLAGS+=-Og -g
debug: all