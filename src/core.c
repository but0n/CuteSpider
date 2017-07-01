#include "core.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define print			printf

#define HOST_TCP_PORT	8080
#define MAX_CLIENT_NUM	3

int main(int argc, char const *argv[]) {
	char buff[1024];
	int sock_fd;
	// Set up server address
	struct sockaddr serv_addr = {
		.sa_family	= AF_INET,
		.sa_data[0]	= HOST_TCP_PORT>>8 & 0xFF,
		.sa_data[1]	= HOST_TCP_PORT & 0xFF,
		// IP: 127.0.0.1 - 7F:00:00:01
		.sa_data[2]	= 127,
		.sa_data[3]	= 0,
		.sa_data[4]	= 0,
		.sa_data[5]	= 1
	};

	// Create socket file description
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd == -1) {
		print("Failed to create socket!\n");
		return 1;
	} else {
		print("Success to cearte socket %d\n", sock_fd);
	}

	// Bind address and socket
	if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
		print("Success to bind address!\n");
	} else {
		print("Failed to bind address!\n");
		close(sock_fd);
		return 1;
	}

	// Set up listen
	if(listen(sock_fd, MAX_CLIENT_NUM) == 0) {
		print("Success to listen!\n");
	} else {
		print("Failed to listen!\n");
		close(sock_fd);
		return 1;
	}

	// Cearte socket for listen
	while(1) {
		int clientfd;
		struct sockaddr clientAdd;
		socklen_t len = sizeof(clientAdd);
		clientfd = accept(sock_fd, (struct sockaddr *)&clientAdd,  &len);
		if(clientfd <= 0) {
			print("Failed to accept!\n");
			close(sock_fd);
			return 1;
		}
		int pid = fork();
		if(pid > 0) {
			// Parent MAIN process
			print("Host is still listening...\nChild: %d\n", pid);

		} else if(pid == 0) {
			// Child process
			while(1) {
				int n;
				while((n = recv(clientfd, buff, 100, 0)) > 0) {
					buff[n] = '\0';
					print("[%d]\tNumber of receive bytes = %d data = %s\n", getpid(), n, buff);

					fflush(stdout);
					send(clientfd, buff, n, 0);

					if(strncmp(buff, "quit", 4) == 0) {
						close(clientfd);
						close(sock_fd);
						print("[%d]\tChild is over!\n", getpid());
						return 0;
					}

				}
			}
		} else {
			print("Failed to fork!\n");
			close(clientfd);
			close(sock_fd);
			return 1;
		}

	}
	return 0;
}