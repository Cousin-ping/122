CC=gcc
CFLAGS=-c -Wall -g -o
OBJS=main.o linklist.o

linklist:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	rm *.o linklist -f