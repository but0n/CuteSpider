#include "sock.h"
#include "route.h"
#include <stdio.h>
#include "http.h"


void test(int *fd_user) {
	send(*fd_user, HTTP_RESPONSE(HTTP_STATUS_LINE_OK), sizeof(HTTP_RESPONSE(HTTP_STATUS_LINE_OK))-1, 0);
	send(*fd_user, "<html>hello</html>", sizeof("<html>hello</html>")-1, 0);
}

int main(int argc, char const *argv[]) {
	socketServer(1313);
	// Cearte socket for listen
	route("/test", test);

	runServer();
	// parse("/test", &stack[0]);
	return 0;
}
