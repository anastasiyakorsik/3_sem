#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd[2];
    int size_1, size_2;
    char string[] = "Hey, what's up?";
    char resString[14];
    int size_res;

    if (pipe(fd) < 0) {
       printf("Can not create pipe\n");
       exit(-1);
    }

    if (size_1 != size_2) {

    size_1 = write(fd[1], string, 14);
    size_2 = read(fd[0], resString, 14);
    size_res++;
    }

    printf("pipe size = %d\n", size_res);

    return 0;
}