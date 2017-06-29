#include "core.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
// #include <sys/arpa/inet.h>

#define print			printf

#define ECHO_PORT		8080
#define MAX_CLIENT_NUM	10

int main(int argc, char const *argv[]) {

	int sock_fd;
	struct sockaddr serv_addr;
	int clientfd;
	struct sockaddr clientAdd;
	char buff[100];
	socklen_t len;
	int n;

	// Create socket
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd == -1) {
		print("Failed to create socket!\n");
		return 1;
	} else {
		print("Success to cearte socket!\n");
	}

	// Set up server address
	serv_addr.sa_family		= AF_INET;
	serv_addr.sa_data[0]	= 0x1F;
	serv_addr.sa_data[1]	= 0x90;	// Port: 8080
	// IP: 127.0.0.1 - 7F:00:00:01
	serv_addr.sa_data[2]	= 0x00;
	serv_addr.sa_data[3]	= 0x00;
	serv_addr.sa_data[4]	= 0x00;
	serv_addr.sa_data[5]	= 0x00;

	// serv_addr.sin_post			= htons(ECHO_PORT);
	// serv_addr.sin_addr.s_addr	= htons(INADDR_ANY);

	// Bind address and socket
	if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
		print("Success to bind address!\n");
	} else {
		print("Failed to bind address!\n");
		close(sock_fd);
		return 1;
	}

	// Set up listen
	if(listen(sock_fd, MAX_CLIENT_NUM)) {
		print("Success to listen!\n");
	} else {
		print("Failed to listen!\n");
		close(sock_fd);
		return 1;
	}

	// Cearte socket for listen
	len = sizeof(clientAdd);
	clientfd = accept(sock_fd, (struct sockaddr *)&clientAdd,  &len);
	if(clientfd <= 0) {
		print("Failed to accept!\n");
		close(sock_fd);
		return 1;
	}

	// Handle request
	while((n = recv(clientfd, buff, 100, 0))) {
		buff[n] = '\0';
		print("Number of receive bytes = %d data = %s\n", n, buff);

		fflush(stdout);
		send(clientfd, buff, n, 0);

		if(strncmp(buff, "quit", 4))
			break;
	}
	close(clientfd);
	close(sock_fd);

	return 0;
}