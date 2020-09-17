#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>


int main() {
  /* Intializes random number generator */
  time_t t;
  srand((unsigned) time(&t)); 

  pid_t child_1, child_2;
  char str[80];

  int iterations = rand() % 31;


  child_1 = fork();

  if (child_1 == 0) {
    /* Child A code */
    for (int i = 0; i < iterations; i++) {
      int sleepTime = rand() % 11;
      sprintf(str, "Child Pid: %d is going to sleep!", getpid()); 
      puts(str);
      sleep(sleepTime);
      sprintf(str, "Child Pid: %d is awake! Where is my Parent: %d", getpid(), getppid());
      puts(str);
    }
    exit(0);
  } else {
    child_2 = fork();

    if (child_2 == 0) {
      /* Child B code */
      for (int i = 0; i < iterations; i++) {
        int sleepTime = rand() % 11;
        sprintf(str, "Child Pid: %d is going to sleep!", getpid()); 
        puts(str);
        sleep(sleepTime);
        sprintf(str, "Child Pid: %d is awake! Where is my Parent: %d", getpid(), getppid());
        puts(str);
      }
      exit(0);
    } else {
        /* Parent Code */
        pid_t cpid = wait(NULL);
        pid_t cpid2 = wait(NULL);
        sprintf(str, "Child Pid: %d has completed!", cpid);
        puts(str);
        sprintf(str, "Child Pid: %d has completed!", cpid2);
        puts(str);
    }
  }
  
  
  return 0; 
} 