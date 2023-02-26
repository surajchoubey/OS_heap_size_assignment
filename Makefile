
CC := "gcc"

output: main.o heap_memory.o
	${CC} main.o heap_memory.o -o make_heap

main.o: main.c
	${CC} -c main.c

heap_memory.o: heap_memory.c heap_memory.h
	${CC} -c heap_memory.c

clean:
	rm *.o output

