CC=gcc
CFLAGS=-c -W -g -o
OBJS=main.o tree.o

test:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	rm *.o test -f
