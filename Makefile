all: msh
msh: my_shell.o lex.yy.o main.c tic.c
	gcc -o msh main.c tic.c my_shell.o lex.yy.o -lfl
test: test.c lex.yy.o my_shell.o
	gcc -o test test.c my_shell.o lex.yy.o -lfl
my_shell.o: my_shell.c
	gcc -Wall -g -c my_shell.c
lex.yy.o: lex.yy.c
	gcc -Wall -g -c lex.yy.c
lex.yy.c: lex.c
	flex lex.c
clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f msh
