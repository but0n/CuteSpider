#include "sock.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

static char buff[2048];
const char	rep[] =
"HTTP/1.1 200 OK\r\n"
"Content-type: text/html; charset=UTF-8\r\n\r\n"
"<html>hello</html>";

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
	if(cltfd == -1) {
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
		int n = recv(cltfd, buff, 2047, 0);
		buff[n] = '\0';
		print("%s\n", buff);
		if(!strncmp(buff, "GET /favicon.ico", 16)) {

		} else {
			send(cltfd, rep, sizeof(rep)-1, 0);
		}
		close(cltfd);
		close(fd);
		exit(0);
	} else {
		print("Failed to fork!\n");
		close(cltfd);
		close(fd);
		return 0;
	}
	return 1;
}