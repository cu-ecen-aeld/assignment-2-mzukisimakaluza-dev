CC=$(CROSS_COMPILE)gcc
all: writer.o
	$(CC) -o writer writer.o
writer.o:
	$(CC) -c writer.c
clean:
	rm -r *.o writer
