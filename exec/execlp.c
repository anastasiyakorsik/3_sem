#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	if (fork() == 0)
	{
		execlp("gcc", "gcc", "exec_hello.c", "-o", "hello", NULL);
	}
	int status = 0;
	wait(&status);
	execlp("./hello", "./hello", NULL);
	
	return 0;
}