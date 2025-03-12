#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define buffer 25
#define read_end 0
#define write_end 1

int main(){
  char writeMsg[buffer] = "Hello World";
  char readMsg[buffer];
  int fd[2];
  
  pid_t pid;
  if(pipe(fd)==-1){ //Creating the pipe
    printf("\n Failed to create pipe.");
    return 1;
  }
  pid = fork();   //Creating fork, for consumer
  if(pid < 0){
    printf("\n Failed to create fork,");
    return 1;
  }
  
  if(pid>0){    //Parent - Producer
    close(fd[read_end]);
    write(fd[1], writeMsg, strlen(writeMsg)+1);
    close(fd[write_end]);
  }
  if(pid==0){   //Child - Consumer
    close(fd[write_end]);
    read(fd[0], readMsg, buffer);
    printf("\n Consumer read: %s", readMsg);
    close(fd[read_end]);
  }
  return 0;
}
