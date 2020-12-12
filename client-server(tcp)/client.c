#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define HOST 34543

int main(int argc, char const *argv[])
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
	{
		printf("Can not create socket\n");
	}
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
	adr.sin_port = htons(HOST);
	//задаем адрес, парамаетры функции - семейство адресов, ip адрес, куда его поместить - туда, где должен храниться ip фвкуыы на который мы будем стучаться
	int address = inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
	if (address == 0)
	{
		printf("Can not define address because src was not an AF_INET or AF_INET6 family address\n");
	}
	if (address == -1)
	{
		printf("Can not define address\n");
	}
	//подключение к серверу, параметры функции - через какой сокет подключаемся, указываем адрес сервера, размер сервера
	int connection = connect(fd, (struct sockaddr *) &adr, sizeof adr);
	if (connection == -1)
	{
		printf("Can not connect to the server\n");
	}
	//передаем на сервер информацию, параметры функции - куда передаем, что передаем, сколько символов
	write(fd, "hello\n", 6);
	char buf[256];
	int nread = read(fd, buf, 256);
	if (nread == -1)
	{
		printf("Can not read message\n");
	}
	if (nread == 0)
	{
		printf("END OF MESSAGE\n");
	}
	//отобразим на консоль то, что нам пришло
	write(STDOUT_FILENO, buf, nread);
	//закрываем сокет
	close(fd);

	return 0;
}