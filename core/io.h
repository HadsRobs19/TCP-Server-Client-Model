#ifndef IOBUFFER_H
#define IOBUFFER_H
#include <stddef.h>

// declare opaque type, or stuct for io buffer withouth defining its internal members
struct OpaqueBuffer;
typedef struct OpaqueBuffer OpaqueBuffer;

// Public API function that creates a new IO buffer instance
// takes in the size of the internal buffer and returns a pointer to the new buffer
OpaqueBuffer* iobuffer_create(size_t size);

// destroys IO buffer instance and frees that space in the memory and takes in the buffer being destroyed
void iobuffer_destroy(OpaqueBuffer* buffer);

//consumes data from io buffer and takes in the desired buffer, pointer to store the read data, the num of bytes that need to be read, and return the num of bytes actually read
size_t iobuffer_read(OpaqueBuffer* buffer, void* data, size_t read_bytes);

// fills buffer and takes in the desired buffer, pointer to the data to write, the num of bytes that need to be written, and returns the num of bytes actually written
size_t iobuffer_write(OpaqueBuffer* buffer, const void* data, size_t write_bytes);

#endif