CC = gcc
CFLAGS = -std=c99 -Wall -Werror

build: main.o oper.o
	$(CC) -o $@ $^

run:
	./build in.txt 

main.o: main.c main.h	
	$(CC) $(CFLAGS) -c $<

oper.o: oper.c oper.h 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *.exe
