#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// <summary>
// defining input/output buffer abstraction and establish how bytes are moving across the wire
// given a socket and a buffer, move bytes

struct OpaqueBuffer{
    char* data; // allocated memory
    size_t size; // total capacity
    size_t read_pos; // next byte to read
    size_t write_pos; // next byte to write
};

/*
* <summary>
* creation of a new buffer in an empty state
* <param name="size">total memory capacity of the new buffer<param>
*/
OpaqueBuffer* iobuffer_create(size_t size){
    OpaqueBuffer *new_buff = (OpaqueBuffer *)malloc(sizeof(OpaqueBuffer) * 1);
    if(new_buff == NULL){
        perror("Memory allacation failed.");
        return NULL;
    }

    new_buff->data = (char *)malloc((size));
    if(new_buff->data == NULL){
        perror("Dynamic allocation of memory failed.");
        free(new_buff);
        return NULL;
    }

    new_buff->size = size;
    new_buff->read_pos = 0;
    new_buff->write_pos = 0;

    return new_buff;
}

/*
* <summary>
* destroys IO buffer instance and frees that space in the memory
* <param name="buffer"><param>
*/
void iobuffer_destroy(OpaqueBuffer* buffer){

}

// read()/recv()

/*
* <summary>
* <param name="buffer"><param>
* <param name="data"><param>
* <param name="read_bytes"><param>
*/
size_t iobuffer_read(OpaqueBuffer* buffer, void* data, size_t read_bytes){
    
}

//write()/send()

/*
* <summary>
* <param name="buffer"><param>
* <param name="data"><param>
* <param name="write_bytes"><param>
*/
size_t iobuffer_write(OpaqueBuffer* buffer, const void* data, size_t write_bytes){

}
