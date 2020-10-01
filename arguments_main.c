#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; ++i)
	{
		printf("argv: %s\n", argv[i]);
	}
	for (int i = 0; envp[i] != 0; ++i)
	{
		printf("envp: %s\n", envp[i]);
	}
	return 0;
}