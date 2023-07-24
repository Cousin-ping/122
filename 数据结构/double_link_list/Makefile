CC=gcc
CFLAGS=-c -W -g -o
OBJS=main.o double_link_list.o

test:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	rm *.o test -f
