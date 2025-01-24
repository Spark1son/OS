#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        fclose(file);
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        fprintf(file, "Child PID: %d\n", getpid());
        fclose(file);
    } else {
        wait(NULL); 
        fprintf(file, "Parent PID: %d\n", getpid());
        fclose(file);
    }

    return 0;
}
