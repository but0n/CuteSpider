#include "sock.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#include "route.h"

#define MAX_CLIENT_NUM	3


static int fd_host;

void socketServer(unsigned short port) {
	// File descriptor
	fd_host = socket(AF_INET, SOCK_STREAM, 0);	// TCP
	if(fd_host == -1) {
		exit(1);
	}

	// Address
	struct sockaddr local = {
		.sa_family	= AF_INET,
		.sa_data[0]	= (unsigned char)(port>>8 & 0xFF),
		.sa_data[1]	= (unsigned char)(port & 0xFF),
		.sa_data[2]	= 127,
		.sa_data[3]	= 0,
		.sa_data[4]	= 0,
		.sa_data[5]	= 1
	};

	// Bind Address
	if(bind(fd_host, (struct sockaddr *)&local, sizeof(local)) == -1) {
		printf("Failed to bind address!\n\n");
		close(fd_host);
		exit(1);
	}

	// Set up listen
	if(listen(fd_host, MAX_CLIENT_NUM) == 0) {
		printf("Success to initial server, listening at %d:\n\n", port);
	} else {
		printf("Failed to listen!\n\n");
		close(fd_host);
		exit(1);
	}
}

int handleServer() {
	struct sockaddr 	cltAddr;
	socklen_t 			len = sizeof(cltAddr);

	int cltfd = accept(fd_host, (struct sockaddr *)&cltAddr, &len);
	if(cltfd == -1) {
		printf("Failed to accept!\n\n");
		close(cltfd);
		return 0;
	}

	int pid = fork();
	if(pid > 0) {
		// Parent MAIN process
		close(cltfd);
		printf("Host is still listening...\nPID: %d\n\n", pid);

	} else if(pid == 0) {
		// Child process
		char buff[2048];
		int n = recv(cltfd, buff, 2047, 0);
		buff[n] = '\0';
		printf("%s\n", buff);
		parse(&cltfd, strchr(buff, '/'), stack);
		close(cltfd);
		// close(fd_host);
		exit(0);
	} else {
		printf("Failed to fork!\n");
		close(cltfd);
		close(fd_host);
		return 0;
	}
	return 1;
}

void runServer() {
	while(handleServer());
}