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
            printf("child: %d parent: %d\n", getpid(), getppid());
            exit(i);
        }
        status = 0;
        wait(&status);
        printf("%d child's exit status = %d\n", i + 1, status);
    }
    return 0;
}
