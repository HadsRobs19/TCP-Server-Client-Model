#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// <summary>
// defining input/output buffer abstraction and establish how bytes are moving across the wire
// given a socket and a buffer, move bytes

/*
*              sliding window diagram of buffer memory reading and writing
*
* data           -> [...............................] (allocated memory)
* read_pos       -> ^ start of unread data
* write_pos      ->           ^ end of written data
* size           -> total capacity
*
*                              free space
*                [data + read_pos .... data + write_pos]
*/
struct OpaqueBuffer{
    char* data; 
    size_t size; 
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

//write()/send()
/*
* <summary>
* takes raw bytes from the caller and appends this data to the unread regions of memory
* <param name="buffer"><param>
* <param name="data"><param>
* <param name="write_bytes"><param>
*/
size_t iobuffer_write(OpaqueBuffer* buff, const void* data, size_t write_bytes){\
    memcpy(buff->data + buff->write_pos, data, write_bytes);

}


// read()/recv()

/*
* <summary>
* copy the byte from new_buff into user memory and advance the read pointer
* <param name="buffer"><param>
* <param name="data"><param>
* <param name="read_bytes"><param>
*/
size_t iobuffer_read(OpaqueBuffer* new_buff, void* data, size_t read_bytes){
    
}

/*
* <summary>
* destroys IO buffer instance and frees that space in the memory
* <param name="buffer"><param>
*/
void iobuffer_destroy(OpaqueBuffer* new_buff){
    free(new_buff->data);
    free(new_buff);
}
