#include "sock.h"
#include "route.h"
#include <stdio.h>

extern st_path	stack[STACK_LEN];

void test() {
	printf("hello\n");
}

int main(int argc, char const *argv[]) {
	// socketServer(1313);
	// // Cearte socket for listen
	// runServer();
	route("/test", test);
	parse("/test", &stack[0]);
	return 0;
}
