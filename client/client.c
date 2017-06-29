#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define print			printf

#define ECHO_PORT		8080
#define MAX_COMMAND		10

int main(int argc, char const *argv[]) {
	int sock_fd;
	struct sockaddr serv_addr;

	char *buff[MAX_COMMAND] = {"abc, def, test, hello, quit"};
	char tmp_buff[100];

	// Create socket
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_fd == -1) {
		print("Failed to create socket!\n");
		return 1;
	} else {
		print("Success to cearte socket!\n");
	}

	// Set up address
	serv_addr.sa_family		= AF_INET;
	serv_addr.sa_data[0]	= 0x1F;
	serv_addr.sa_data[1]	= 0x90;	// Port: 8080
	// IP: 127.0.0.1 - 7F:00:00:01
	serv_addr.sa_data[2]	= 0x00;
	serv_addr.sa_data[3]	= 0x00;
	serv_addr.sa_data[4]	= 0x00;
	serv_addr.sa_data[5]	= 0x00;

	// Connect to server
	if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
		print("Success to connect!\n");
	} else {
		print("Failed to connect!\n");
		return 1;
	}

	int n;
	for(int i = 0; i < MAX_COMMAND; i++) {
		send(sock_fd, buff[i], 100, 0);
		n = recv(sock_fd, tmp_buff, 100, 0);
		tmp_buff[n] = '\0';
		print("data send: %s reveive: %s\n", buff[i], tmp_buff);

		if(strncmp(tmp_buff, "quit", 4))
			break;
	}

	close(sock_fd);

	return 0;
}
