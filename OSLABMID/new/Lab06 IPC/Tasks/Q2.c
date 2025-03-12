#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(){
  int fd[2];
  pid_t pid;
  if(pipe(fd)==-1){
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  
  pid = fork();
  if(pid < 0){
    perror("fork");
    exit(EXIT_FAILURE);
  }
  
  if(pid > 0){
    close(fd[0]);
    float temp, hum;
    char data[20];
    printf("Enter temp & humidity: ");
    scanf("%f%f", &temp, &hum);
    snprintf(data, sizeof(data), "%f %f", temp, hum);
    write(fd[1], data, strlen(data)+1);
    close(fd[1]);
  }
  else{
    close(fd[1]);
    float temp, hum;
    char data[20];
    read(fd[0], data, sizeof(data));
    sscanf(data, "%f %f", &temp, &hum);
    
    if(temp>40.0){
      printf("\nALERT: High Temperature!");
    }
    else
      printf("\nNormal Weather Conditions.");
    close(fd[0]);
  }
  
  return 0;
}
