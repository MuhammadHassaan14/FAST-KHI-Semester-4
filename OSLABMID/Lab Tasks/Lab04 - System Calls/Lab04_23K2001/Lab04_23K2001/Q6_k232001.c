// 23K2001 - Muzammil
/*Write a C program to lines the number of lines in a file. The parent process 
opens the file, forks a child process that reads character by character, 
liness the newline (\n) characters, and prints the total line lines
after the child process finishes execution.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
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
        char ch;
        int lines = 0;
        
        while (read(fd, &ch, 1) > 0){
            if (ch == '\n')
                lines++;
        }
        close(fd);
        printf("Total number of lines = %d\n", lines);
        exit(0);
    } 
    else
        wait(NULL);

    return 0;
}

