// 23K2001 - Muzammil
/*Write a program which prints its PID and uses fork () system call to create a child process. After fork () system call, both
parent and child processes print what kind of process they are and their PID. Also, the parent process prints its child’s PID,
and the child process prints its parent’s PID.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
  size_t p = fork();
  if(p == 0){
    printf("\n(Inside child):\nCurrent Process: p_id = %d\nParent Process: p_id = %d\n",getpid(),getppid());
  }
  else{
    wait(NULL);
    printf("\n(Inside parent):\nChild Process: p_id = %lu\nCurrent Process: p_id = %d\nParent Process: p_id = %d\n",p,getpid(),getppid());
  }
  return 0;
}
