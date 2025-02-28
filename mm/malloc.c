// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	void *ptr = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED) {
		return NULL;
	}

	*(size_t *)ptr = size;

	// Add to list the new allocated memory
	mem_list_add(ptr + sizeof(size_t), size);
	return ptr + sizeof(size_t);
}

void *calloc(size_t nmemb, size_t size)
{
	void *ptr = malloc(nmemb * size);
	if (ptr == NULL) {
		return NULL;
	}

	// Make sure that the memory is zeroed
	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
	struct mem_list *mem = mem_list_find(ptr);

	if (mem == NULL) {
		return;
	}
	
	// Unmap the memory
	munmap(ptr - sizeof(size_t), mem->len + sizeof(size_t));
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{	
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *new_ptr = malloc(size);
	memcpy(new_ptr, ptr, size);
	free(ptr);
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (ptr == NULL) {
		return malloc(size * nmemb);
	}

	if (size * nmemb == 0) {
		free(ptr);
		return NULL;
	}

	// In the other case the call is equivalent to malloc(size * nmemb),
	// then memcpy() of the old block, and last but not least, free() of the old block.
	void *new_ptr = malloc(size * nmemb);
	memcpy(new_ptr, ptr, size * nmemb);
	free(ptr);
	return new_ptr;
}
