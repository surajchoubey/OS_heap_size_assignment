#include "heap_memory.h"
#include <stdlib.h>
#include <stdio.h>

# define UL unsigned long

struct Heap {
	int max_size;
	int allocated_memory;
	int free_size;

	int *start_pointer;
	int *bump_pointer;
	int *end_pointer;
};

void print_size(struct Heap* heap) {
	if (!heap || !(heap -> start_pointer) || !(heap -> end_pointer) || !(heap -> bump_pointer)) return;
	printf("Allocation size = %d\n", heap -> allocated_memory);
	printf("Free size = %d\n", heap -> free_size);
	printf("==============================================================================================\n");
}

struct Heap *create_heap(UL max_size) {

	struct Heap* newHeap = (struct Heap *) malloc(sizeof(struct Heap));

	newHeap -> start_pointer = (int *) malloc(max_size); // instead of maxsize * sizeof(int)
	newHeap -> end_pointer = newHeap -> start_pointer + max_size;
	newHeap -> bump_pointer = newHeap -> start_pointer;

	newHeap -> max_size = max_size;
	newHeap -> free_size = newHeap -> end_pointer - newHeap -> bump_pointer;
	newHeap -> allocated_memory = 0;

	if (newHeap) {
		printf("Heap creation successful of size %d !\n", newHeap -> max_size);
		print_size(newHeap);
		return newHeap;
	} else {
		printf("Heap creation failed!");
		exit(1);
	}
}

void heap_memory_allocate(struct Heap* heap, UL allocation_size) {

	if (!heap || !(heap -> start_pointer)) {
		printf("Heap memory allocated failed!\n");
		exit(1);
	}

	heap -> bump_pointer = heap -> start_pointer + allocation_size;
	heap -> allocated_memory = heap -> bump_pointer - heap -> start_pointer;
	heap -> free_size = heap -> end_pointer - heap -> bump_pointer;

	if (heap -> bump_pointer) {
		printf("Heap allocation successful of size %d !\n", heap -> allocated_memory);
		print_size(heap);
	} else {
		printf("Heap creation failed!");
		exit(1);
	}

}

void clear_heap(struct Heap *heap) {
	
	if (!heap || !(heap -> start_pointer)) {
		printf("Heap cannot be cleared!\n");
		exit(1);
	}

	heap -> bump_pointer = heap -> start_pointer;
	heap -> allocated_memory = 0;
	heap -> free_size = heap -> max_size;

	printf("Heap clear successful!\n");
	print_size(heap);
}

void destroy_heap(struct Heap *heap) {
	if (heap && heap -> start_pointer) {
		free(heap -> start_pointer);
		free(heap);
		printf("Heap destroy successful!\n");
		printf("==============================================================================================\n");
	} else {
		printf("Heap destroy failed ! \n");
	}

}