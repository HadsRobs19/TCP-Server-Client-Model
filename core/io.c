#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining input/output buffer abstraction and establish how bytes are moving across the wire
// given a socket and a buffer, move bytes

struct OpaqueBuffer{
    char* data; // allocated memory
    size_t size; // total capacity
    size_t read_pos; // next byte to read
    size_t write_pos; // next byte to write
};

OpaqueBuffer* iobuffer_create(size_t size){

}

void iobuffer_destroy(OpaqueBuffer* buffer){

}

size_t iobuffer_read(OpaqueBuffer* buffer, void* data, size_t read_bytes){

}

size_t iobuffer_write(OpaqueBuffer* buffer, const void* data, size_t write_bytes){
    
}
// read()/recv()
//write()/send()
