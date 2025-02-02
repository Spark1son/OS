#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
 int fd[2];
 pid_t pid;
 char  buffer[100];
 char msg[] = "hello";
 
 if (pipe(fd) == -1) {
    perror("pipe error");
    return 1;
 }
 pid = fork();
 if (pid < 0) { 
    perror("fork error");
    return 1;
 } else if(pid == 0) {
       close(fd[1]);
       read(fd[0], buffer, sizeof(buffer));
       printf("Child received: %s\n", buffer);
       close(fd[0]);
   } else { 
     close(fd[0]);
     write(fd[1] , msg, strlen(msg) + 1);
     close(fd[1]);
     wait(NULL);
}
return 0;
}


