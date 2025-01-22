#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
  if (sig == SIGUSR1) {
    printf("Child  received SIGUSR1 signal from parent.\n");
    }
}

int main() {
  pid_t pid = fork();

  if (pid < 0) {
      perror("Fork failed");
      return 1;
    } else if (pid == 0) {
      signal(SIGUSR1, signal_handler);
      printf("Child  waiting for signal...\n");
        pause();
        printf("Child exiting.\n");
    } else {
       sleep(1);
       printf("Parent sending SIGUSR1 signal to child (PID: %d)\n", pid);
       kill(pid, SIGUSR1); 
       sleep(1); 
       printf("Parent process exiting.\n");
    }

    return 0;
}
