final: main.o kdTree.o stack.o helper.o
	gcc main.o kdTree.o stack.o helper.o -o final

main.o: main.c kdTree.h stack.h helper.h
	gcc -c main.c

kdTree.o: kdTree.c kdTree.h stack.h helper.h
	gcc -c kdTree.c

stack.o: stack.c stack.h kdTree.h helper.h
	gcc -c stack.c

helper.o: helper.c helper.h kdTree.h stack.h
	gcc -c helper.c
	
clean:
	rm *.o final