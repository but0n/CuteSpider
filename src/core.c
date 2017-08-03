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
	send(*fd_user, HTTP_RESPONSE_HEADERS(HTTP_STATUS_LINE_OK), sizeof(HTTP_RESPONSE_HEADERS(HTTP_STATUS_LINE_OK))-1, 0);
	send(*fd_user, "<html>hello</html>", sizeof("<html>hello</html>")-1, 0);
}

int main(int argc, char const *argv[]) {
	socketServer(1313);
	// Cearte socket for listen
	route("/", test);

	runServer();
	// parse("/test", &stack[0]);
	return 0;
}
