main:main.o queue.o
	gcc -o main main.o queue.o
main.o:main.c
	gcc -c main.c
queue.o:queue.c
	gcc -c queue.c
clean:
	rm *.o
	rm main
rebuild:clean main
