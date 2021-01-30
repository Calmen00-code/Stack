CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJ = stack.o LinkedList.o StackTest.o print.o
EXEC = main

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

stack.o : stack.c stack.h header.h
	$(CC) $(CFLAGS) -c stack.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

StackTest.o : StackTest.c stack.h header.h
	$(CC) $(CFLAGS) -c StackTest.c

print.o : print.c print.h
	$(CC) $(CFLAGS) -c print.c

clean:
	rm -f $(OBJ) $(EXEC)
