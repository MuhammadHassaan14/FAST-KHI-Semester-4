#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    mkfifo(FIFO_FILE, 0777); // Create the named pipe (FIFO)

    fd = open(FIFO_FILE, O_RDONLY); // Open the named pipe for reading (consumer)

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Consumer loop

        num_bytes = read(fd, buffer, sizeof(buffer)); // Read input from the named pipe

        if (num_bytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("Consumer: Read a message: %.*s", (int)num_bytes, buffer);
        if (strncmp(buffer, "exit", 4) == 0){ // Check for exit condition
            break;
        }
    }

    close(fd); // Close the named pipe
    unlink(FIFO_FILE); // Remove the named pipe from the file system

    return 0;
}

