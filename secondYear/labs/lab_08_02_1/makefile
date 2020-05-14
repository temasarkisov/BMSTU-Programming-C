CC = gcc
CFLAGS = -std=c99 -Wall -Werror
app.exe: main.o arr_form.o arr_math.o arr_oper.o arr_print.o
	$(CC) -o $@ $^
test.exe: test.o arr_math.o arr_oper.o 
	$(CC) -o $@ $^
main.o: main.c arr_form.h arr_math.h arr_oper.h arr_print.h
	$(CC) $(CFLAGS) -c $<
test.o: test.c arr_math.h arr_oper.h
	$(CC) $(CFLAGS) -c $<
arr_form.o: arr_form.c arr_form.h
	$(CC) $(CFLAGS) -c $<
arr_math.o: arr_math.c arr_math.h
	$(CC) $(CFLAGS) -c $<
arr_oper.o: arr_oper.c arr_oper.h
	$(CC) $(CFLAGS) -c $<
arr_print.o: arr_print.c arr_print.h
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) *.o *.exe

