#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_file "/tmp/new"
#define size 20

int main(){
  int fd;
  char details[size];
  ssize_t bytes;
  
  mkfifo(FIFO_file, 0666);
  fd = open(FIFO_file, O_RDONLY);
  if(fd == -1){
    perror("write");
    exit(EXIT_FAILURE);
  }
  
  while(1){
    bytes = read(fd, details, sizeof(details));
    if(bytes == -1){
      perror("write");
      exit(EXIT_FAILURE);
    }
    
    if((int)bytes >= 6){
      printf("\nValid, Balance: $5000");
    }
    else{
      printf("\nInvalid credentials.");
    }
  }
  
  close(fd);
  unlink(FIFO_file);
  return 0;
}
