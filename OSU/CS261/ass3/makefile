default: prog

link.o:
	gcc -Wall -g -std=c99 linkedList.c linkedList.h testLinkedList.c -o question1

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o link.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o
		
clean:
	rm cirListDeque.o
	rm testCirListDeque.o
	rm prog
	rm question1
