CC = gcc
CFLAGS = -Wall -pedantic

debug: CFLAGS += -g -DDEBUG
debug: test

.o:.c
	$(CC) -c $< -o $@ $(CFLAGS)

glist.o: glist.c

gstack.o: gstack.c

gdsutils.o: gdsutils.c

test_glist.o: test_glist.c

test_gdsutils.o: test_gdsutils.c

test_gstack.o: test_gstack.c

test: glist.o gdsutils.o test_glist.o test_gdsutils.o gstack.o test_gstack.o
	$(CC) gdsutils.o test_gdsutils.o -o test_gdsutils.exe
	$(CC) glist.o gdsutils.o test_glist.o -o test_glist.exe
	$(CC) gstack.o glist.o gdsutils.o test_gstack.o -o test_gstack.exe

clean:
	rm -f *.o
	rm -f test_gdsutils.exe
	rm -f *.*~
	 
