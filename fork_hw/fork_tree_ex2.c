#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int status = 0, N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int pid = fork();
        if (pid == 0) {
            printf("Process №%d is created: %d(child) %d(parent)\n", i, getpid(), getppid());
            exit(i);
        }
        status = 0;
        wait(&status);
        printf("child %d (pid = %d) exit from parent's (ppid = %d) process.\n", i, pid, getpid());
        }
    return 0;
    }
