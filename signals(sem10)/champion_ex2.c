#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int process_type;

void Signal1(int nsig) { //подаем номер сигнала
		printf("РТ");
		sleep(1);
		kill(process_type, SIGUSR2);//подаем сигнал завершения процессу process_type 

}

void Signal2(int nsig) {
		printf("ЧЕМПИОН!\n");
		sleep(1);
		kill(process_type, SIGUSR1); //передаем в родительский
}

void Run() {
	Signal1(0); //вызываем функцию от нулевого сигнала
	while(1);
}

int main()
{
	int pid;

	signal (SIGUSR1, Signal1);//как реагировать на SIGUSR1 с помощью функции
	signal (SIGUSR2, Signal2);
	
	process_type = getpid();//используем один главный процесс, по факту он сам себе подает сигналы
	
	Run();//функция циклится и процессы передают друг другу сигналы
	
	return 0;
}
