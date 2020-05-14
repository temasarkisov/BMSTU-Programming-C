CC = gcc
CFLAGS = -std=c99 -Wall -Werror  

test.exe: test.o test_auxiliary.o snprintf.o
	$(CC) -o $@ $^

test.o: test.c test.h
	$(CC) $(CFLAGS) -c $<

test_auxiliary.o: test_auxiliary.c test_auxiliary.h
	$(CC) $(CFLAGS) -c $<

snprintf.o: snprintf.c snprintf.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *.exe
