// 23K2001 - Muzammil
/*Write a C program to create a backup of a file. The program takes two filenames as input (source and destination), where the parent process opens both files, forks a 
child process to read from the source file and write to the destination file, 
and ensures proper error handling if the file does not exist.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char src[100], dest[100];
    printf("\nInput source file path: ");
    scanf("%s", src);
    printf("Input destination file path: ");
    scanf("%s", dest);

    int f1 = open(src, O_RDONLY);
    if (f1 == -1){
        perror("\nError opening source file");
        return 1;
    }
    int f2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (f2 == -1){
        perror("\nError creating destination file");
        close(f1);
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1){
        perror("\nFork failed");
        close(f1);
        close(f2);
        return 1;
    }

    if (pid == 0){
        char buffer[1024];
        ssize_t bytesRead;
        
        while ((bytesRead = read(f1, buffer, sizeof(buffer))) > 0)
            write(f2, buffer, bytesRead);
        
        close(f1);
        close(f2);
        printf("\nBackup successful!\n");
    } 
    else
        wait(NULL);

    return 0;
}

