struct freeBlock {
  struct freeBlock* previous;
  struct freeBlock* next;
  unsigned int size;
};

struct memoryBlock {
  unsigned int start;
  unsigned int end;
  unsigned int size;
  struct freeBlock* first;
};

void mem_init(unsigned int start, unsigned int size);
void* malloc(unsigned int size);
void* calloc(unsigned int num, unsigned int size);
void* realloc (void* ptr, unsigned int size);
void free(void* ptr);
