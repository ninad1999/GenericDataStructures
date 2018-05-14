glist.o: glist.c
	gcc -c -Wall glist.c

gdsutils.o: gdsutils.c
	gcc -c -Wall gdsutils.c

test_glist.o: test_glist.c
	gcc -c -Wall test_glist.c

test_gdsutils.o: test_gdsutils.c
	gcc -c -Wall test_gdsutils.c

test: glist.o gdsutils.o test_glist.o test_gdsutils.o
	gcc -Wall gdsutils.o test_gdsutils.o -o test_gdsutils.exe
	gcc -Wall glist.o gdsutils.o test_glist.o -o test_glist.exe

clean:
	rm -f *.o
	rm -f test_gdsutils.exe
     
