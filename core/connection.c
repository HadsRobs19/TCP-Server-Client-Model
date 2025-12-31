#include <sys/socket.h>
#include <netinet/in.h>

// owns the already-accepted client socket and all per-connection states, including buffers, lifecycle tracking, and metadata, while delegating actual I/O to a separate I/O layer
int main(int argc, char const* argv[]){
    // adopt socket to recieve fd
    

    // wrap in a connection structure

    // tracks states, buffers, and metadata
}