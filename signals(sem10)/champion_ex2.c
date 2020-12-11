#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int process_s1;

void Signal1(int nsig) {
		printf("РТ");
		kill(process_s1, SIGUSR1);

}

void Signal2(int nsig) {
		printf("ЧЕМПИОН!\n");
		int process = getppid();
		kill(process, SIGUSR1);
}


int main(void)
{
	int pid;

	//signal (SIGUSR1, Signal1);
	//signal (SIGUSR2, Signal2);

	pid = fork();
	if (pid == -1) //error
	{
		printf("error\n");

	} else if (pid == 0) //child
	{
		signal (SIGUSR2, Signal2);
		while(1);

	} else //parent
	{
		process_s1 = pid;
		signal (SIGUSR1, Signal1);
		while(1);
	}



	while(1);
	return 0;
}