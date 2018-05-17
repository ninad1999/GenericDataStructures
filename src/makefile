glist.o: glist.c
	gcc -g -c -Wall glist.c

gstack.o: gstack.c
	gcc -g -c -Wall gstack.c

gdsutils.o: gdsutils.c
	gcc -g -c -Wall gdsutils.c

test_glist.o: test_glist.c
	gcc -g -c -Wall test_glist.c

test_gdsutils.o: test_gdsutils.c
	gcc -g -c -Wall test_gdsutils.c

test_gstack.o: test_gstack.c
	gcc -g -c -Wall test_gstack.c

test: glist.o gdsutils.o test_glist.o test_gdsutils.o gstack.o test_gstack.o
	gcc -g -Wall gdsutils.o test_gdsutils.o -o test_gdsutils.exe
	gcc -g -Wall glist.o gdsutils.o test_glist.o -o test_glist.exe
	gcc -g -Wall gstack.o glist.o gdsutils.o test_gstack.o -o test_gstack.exe

clean:
	rm -f *.o
	rm -f test_gdsutils.exe
	rm -f *.*~
	 
