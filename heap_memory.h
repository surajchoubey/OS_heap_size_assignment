#ifndef HEAP_MEMORY
#define HEAP_MEMORY

struct Heap;

struct Heap *create_heap(unsigned long max_size);

void heap_memory_allocate(struct Heap* heap, unsigned long allocation_size);

void clear_heap(struct Heap *heap);

void destroy_heap(struct Heap *heap);

#endif // HEAP_MEMORY
