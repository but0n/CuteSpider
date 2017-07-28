#include "sock.h"
#include <stdio.h>
// #include <signal.h>



int main(int argc, char const *argv[]) {
	int sock_fd = socketServer(HOST_TCP_PORT);
	if(sock_fd == -1)
		return 1;

	// Cearte socket for listen
	while(handleServer(sock_fd));
	return 0;
}
