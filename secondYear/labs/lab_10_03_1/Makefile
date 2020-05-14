CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

test.exe: test.o experiment_cdio.o experiment_oper.o experiment_sort.o test_auxiliary.o
	$(CC) -o $@ $^

app.exe: main.o experiment_cdio.o experiment_oper.o experiment_sort.o
	$(CC) -o $@ $^

test.o: test.c test_auxiliary.h
	$(CC) $(CFLAGS) -c $<

test_auxiliary.o: test_auxiliary.c test_auxiliary.h
	$(CC) $(CFLAGS) -c $<	

main.o: main.c main.h	
	$(CC) $(CFLAGS) -c $<

experiment_sort.o: experiment_sort.c experiment_sort.h
	$(CC) $(CFLAGS) -c $<

experiment_oper.o: experiment_oper.c experiment_oper.h
	$(CC) $(CFLAGS) -c $<

experiment_cdio.o: experiment_cdio.c experiment_cdio.h 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o *.exe

