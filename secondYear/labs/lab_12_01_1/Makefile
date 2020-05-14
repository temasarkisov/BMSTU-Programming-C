CC = gcc
CFLAGS = -std=c99 -Wall -Werror

test.exe: test.o test_auxiliary.o polynom_cdio.o polynom_oper.o
	$(CC) -o $@ $^

app.exe: main.o polynom_cdio.o polynom_oper.o
	$(CC) -o $@ $^

test.o: test.c main.h 
	$(CC) $(CFLAGS) -c $<

test_auxiliary.o: test_auxiliary.c test_auxiliary.h
	$(CC) $(CFLAGS) -c $<

main.o: main.c main.h	
	$(CC) $(CFLAGS) -c $<

polynom_oper.o: polynom_oper.c polynom_oper.h 
	$(CC) $(CFLAGS) -c $<

polynom_cdio.o: polynom_cdio.c polynom_cdio.h 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *.exe
