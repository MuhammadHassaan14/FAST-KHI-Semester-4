// 23K2001 - Muzammil
/*Develop a program that copies the contents of one file into another file using system calls. 
The program should accept two file paths as command-line arguments: the source file to be copied 
from and the destination file to be copied to. Ensure proper error handling for 
file opening, reading, and writing operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int f1, f2;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];
    
    // Open input file (1st argument) for reading
    f1 = open(argv[1], O_RDONLY);
    if (f1 == -1) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    // Open output file (2nd argument) for writing (create if not exists, truncate if exists)
    f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f2 == -1) {
        perror("Failed to open output file");
        close(f1);
        exit(EXIT_FAILURE);
    }
    
    // Read from input file and write to output file
    while ((bytes_read = read(f1, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(f2, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(f1);
            close(f2);
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1) {
        perror("Read error");
        close(f1);
        close(f2);
        exit(EXIT_FAILURE);
    }
    
    // Close input and output files
    if (close(f1) == -1) {
        perror("Failed to close input file");
        exit(EXIT_FAILURE);
    }
    if (close(f2) == -1) {
        perror("Failed to close output file");
        exit(EXIT_FAILURE);
    }
    
    printf("File copied successfully.\n");
    return 0;
}
