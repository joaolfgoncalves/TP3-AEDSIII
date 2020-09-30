run: main.o lib.o
	gcc main.o lib.o -o run
	
main.o: main.c lib.h
	gcc -c -Wall -Wextra -Werror -std=c99 -pedantic main.c
	
lib.o: lib.c lib.h
	gcc -c -Wall -Wextra -Werror -std=c99 -pedantic lib.c

clean:
	rm *.o lib

txt:
	rm *.txt

exec:
	./run
