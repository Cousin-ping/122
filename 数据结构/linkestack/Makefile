main:main.o linkstack.o
	gcc -o main main.o linkstack.o
main.o:main.c
	gcc -c main.c
link.o:linkstack.c
	gcc -c linkstack.c
clean:
	rm *.o
	rm main
rebuild:clean main
