// 23K2001 - Muzammil
/*Write a C program creates a child process using fork(). The child process 
redirects its output to a file and executes the who command using execlp(). 
The parent process waits for the child to finish and informs 
the user that the output has been successfully stored.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    char file[100];
    printf("Input the file to store the output: ");
    scanf("%s", file);
    pid_t pid = fork();
    if (pid == -1){
        perror("Fork failed");
        return 1;
    }
    
    if (pid == 0){
        int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1){
            perror("Error opening file");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);

        execlp("who", "who", NULL);
        perror("execlp failed");
        exit(1);
    } 
    else{
        wait(NULL);
        printf("Output successfully stored in %s\n", file);
    }
    return 0;
}

