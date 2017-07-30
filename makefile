a.out:main.o donate.o
	gcc main.o donate.o -o a.out
main.o:main.c donate.h
	gcc -c -o main.o  main.c
donate.o:donate.c donate.h
	gcc -c -o donate.o donate.c