CC = gcc
CFLAGS = -std=c99 -Wall -Werror  
test.exe: test.o matrix_cdio.o matrix_math.o matrix_oper.o 
	$(CC) -o $@ $^
app.exe: main.o matrix_cdio.o matrix_math.o matrix_oper.o 
	$(CC) -o $@ $^
main.o: main.c main.h
	$(CC) $(CFLAGS) -c $<
test.o: test.c matrix_math.h matrix_oper.h struct_matrix_t.h
	$(CC) $(CFLAGS) -c $<
matrix_cdio.o: matrix_cdio.c matrix_cdio.h 
	$(CC) $(CFLAGS) -c $<
matrix_math.o: matrix_math.c matrix_math.h
	$(CC) $(CFLAGS) -c $<
matrix_oper.o: matrix_oper.c matrix_oper.h 
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) *.o *.exe
