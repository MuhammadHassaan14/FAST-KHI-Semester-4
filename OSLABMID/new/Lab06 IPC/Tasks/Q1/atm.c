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
  fd = open(FIFO_file, O_WRONLY);
  if(fd == -1){
    perror("write");
    exit(EXIT_FAILURE);
  }
  
  while(1){
    printf("\nEnter account details (ACC_NO: XXXXXX PIN: XXX)\n : ");
    fgets(details, size, stdin);
    bytes = write(fd, details, strlen(details)+1);
    if(bytes == -1){
      perror("write");
      exit(EXIT_FAILURE);
    }
    
    printf("Request sent. Waiting for response from server.");
  }
  
  close(fd);
  unlink(FIFO_file);
  return 0;
}
