// 23K2001 - Muzammil
/*Write a program which uses fork () system-call to create a child process. The child process prints the contents of the current
directory, and the parent process waits for the child process to terminate.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
  size_t p = fork();
  if(p == 0){
    execlp("/bin/ls","ls",NULL);
  }
  else{
    wait(NULL);
    printf("\nChild process terminated. Exiting program.\n"); 
  }
  return 0;
}
