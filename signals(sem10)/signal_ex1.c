#include <signal.h>
#include <stdio.h>

void my_handler(int nsig) {
		printf("Ignore recieved signal %d\n", nsig);
}

int main(void)
{
	for (int i = 1; i < 32; i++) {
		(void) signal (i, my_handler);
	}
	while(1);
	return 0;
}
