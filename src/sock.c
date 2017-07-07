#include "sock.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

static char buff[1024];

#define print	printf

int socketServer(unsigned short port) {
	struct sockaddr local = {
		.sa_family = AF_INET,
		.sa_data[0] = (unsigned char)(port>>8 & 0xFF),
		.sa_data[1] = (unsigned char)(port & 0xFF),
		.sa_data[2] = 127,
		.sa_data[3] = 0,
		.sa_data[4] = 0,
		.sa_data[5] = 1
	};
	int fd = socket(AF_INET, SOCK_STREAM, 0);	// TCP
	if(fd == -1)
		return -1;
	if(bind(fd, (struct sockaddr *)&local, sizeof(local)) == 0) {
		print("Success to bind address!\n");
	} else {
		print("Failed to bind address!\n");
		close(fd);
		return -1;
	}

	// Set up listen
	if(listen(fd, MAX_CLIENT_NUM) == 0) {
		print("Success to listen!\n");
	} else {
		print("Failed to listen!\n");
		close(fd);
		return -1;
	}
	return fd;
}

int handleServer(int fd) {
	struct sockaddr 	cltAddr;
	socklen_t 			len = sizeof(cltAddr);

	int cltfd = accept(fd, (struct sockaddr *)&cltAddr, &len);
	if(cltfd <= 0) {
		print("Failed to accept!\n");
		close(cltfd);
		return 0;
	}

	int pid = fork();
	if(pid > 0) {
		// Parent MAIN process
		close(cltfd);
		print("Host is still listening...\nChild: %d\n", pid);

	} else if(pid == 0) {
		// Child process
		while(1) {
			int n;
			while((n = recv(cltfd, buff, 100, 0)) > 0) {
				buff[n] = '\0';
				print("[%d]\tNumber of receive bytes = %d data = %s\n", getpid(), n, buff);

				fflush(stdout);
				send(cltfd, buff, n, 0);

				if(strncmp(buff, "quit", 4) == 0) {
					close(cltfd);
					close(fd);
					print("[%d]\tChild is over!\n", getpid());
					break;
				}

			}
			exit(0);
		}
	} else {
		print("Failed to fork!\n");
		close(cltfd);
		close(fd);
		return 0;
	}
	return 1;
}