main:main.o linkqueue.o
	gcc -o main main.o linkqueue.o
main.o:main.c
	gcc -c main.c
linkqueue.o:linkqueue.c
	gcc -c linkqueue.c
clean:
	rm *.o
	rm main
rebuild:clean main
