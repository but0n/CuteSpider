#include "sock.h"
#include "route.h"
#include <stdio.h>
#include <sys/socket.h>
#include "http.h"

const char	rep[] =
 "HTTP/1.1 200 OK\r\n"
 "Content-type: text/html; charset=UTF-8\r\n\r\n"
 "<html>hello</html>";
void test(int *fd_user) {
	send(*fd_user, rep, sizeof(rep), 0);
}

int main(int argc, char const *argv[]) {
	socketServer(1313);
	// Cearte socket for listen
	route("/test", test);

	runServer();
	// parse("/test", &stack[0]);
	return 0;
}
