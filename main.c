#include "heap_memory.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// for (int i = 0; i < argc; i++) {
	// 	printf("%s\n", argv[i]);
	// }

	int max_size = atoi(argv[1]);
	struct Heap* myHeap = create_heap(max_size);

	heap_memory_allocate(myHeap, 0x40);

	heap_memory_allocate(myHeap, 0x80);

	clear_heap(myHeap);

	destroy_heap(myHeap);

	return 0;
}