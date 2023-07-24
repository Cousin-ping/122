CC=gcc
CFLAGS=-c -Wall -g -o
OBJS=main.o seqlist.o

seqlist:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	rm *.o seqlist -f