#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int *parent, *child;
    int prNumber = 0;
    scanf("%d", &prNumber);
    parent = (int*) calloc(prNumber, sizeof(int));
    child = (int*) calloc(prNumber, sizeof(int));

    for (int j = 0; j < prNumber; ++j) {
        scanf("%d %d", &parent[j], &child[j]);
    }

    int currentParent = -1, localParent = -1, status = 0, exitNumber = 0;
    for (int i = 0; i < prNumber; ++i) {
        if (parent[i] == currentParent) {
            int pid = fork();
            if (pid == 0) {
                localParent = currentParent;
                currentParent = child[i];
                printf("New process is created: child = %d parent = %d\n", currentParent, localParent);
            } else exitNumber++;
        }
    }

    for (int k = 0; k < exitNumber; ++k) {
        wait(&status);
    }
    printf("child (%d) exit from parent's (%d) process.\n", currentParent, localParent);

    return 0;
}