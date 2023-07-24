CC=gcc
CFLAGS=-c -W -g -o
OBJS=main.o stack.o

main:$(OBJS)
	@$(CC) $^ -o $@
%.o:%.c
	@$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	rm *.o main -f
