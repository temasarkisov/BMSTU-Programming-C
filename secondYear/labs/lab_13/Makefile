CC = gcc
CFLAGS = -std=c99 -Wall -Werror  

libcmp.so: cmp_dmc.o
	$(CC) -shared -o $@ $^

libcmp.a: cmp_stc.o 
	ar cr $@ $^

cmp_dmc.o: cmp.c ../c_src_headers/cmp.h
	$(CC) $(CFLAGS) -fPIC -o $@ -c $<

cmp_stc.o: cmp.c ../c_src_headers/cmp.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) *.o *.exe