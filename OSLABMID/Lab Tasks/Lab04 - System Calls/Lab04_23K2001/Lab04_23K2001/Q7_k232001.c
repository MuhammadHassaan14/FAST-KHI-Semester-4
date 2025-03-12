// 23K2001 - Muzammil
/*Write a C program to display the contents of a file on the terminal. 
The parent process opens the file and forks a child process, which reads the file 
using read() and writes the content to the terminal using write(), 
while handling errors if the file does not exist.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    char path[100];
    printf("Input file path: ");
    scanf("%s", path);

    int fd = open(path, O_RDONLY);
    if (fd == -1){
        perror("Error opening file");
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1){
        perror("Fork failed");
        close(fd);
        return 1;
    }

    if (pid == 0){
        char buffer[1024];
        int bytesRead;
        while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
            write(STDOUT_FILENO, buffer, bytesRead);
        
        close(fd);
        exit(0);
    }
    else
        wait(NULL);

    return 0;
}

