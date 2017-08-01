#ifndef SOCK_H
#define SOCK_H

#define print			printf
#define MAX_CLIENT_NUM	3

void socketServer(unsigned short port);
int handleServer();
void runServer();


#endif