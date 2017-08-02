#include "sock.h"
#include "route.h"
#include <stdio.h>


int main(int argc, char const *argv[]) {
	socketServer(1313);
	// Cearte socket for listen
	runServer();
	return 0;
}
